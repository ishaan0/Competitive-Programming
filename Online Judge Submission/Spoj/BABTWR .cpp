#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &value: cont)
#define     show(val)           cout<< #val << " -> " << val << endl
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs << ": "
#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;

struct box{
    box(int a,int b,int c){h=a,w=b,d=c; }
    int h,w,d ;
};

int n,dp[100];
vector<box> arr ;
int height[100] ;

bool cmp(box a,box b){
    return (a.w*a.d) > (b.w*b.d) ;
}

int lis(int i){
    int &ans = dp[i] ;
    if(ans != -1) return ans ;
    ans = height[i] ;
    for(int j=i+1; j<n; j++){
        if(arr[j].d<arr[i].d && arr[j].w<arr[i].w ){
            int temp = lis(j) ;
            if(temp+height[i] > ans)
                ans = temp+height[i] ;
        }
    }

    return ans ;
}


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    while(cin>> n){
        if(n == 0) break ;
        arr.clear() ;
        for(int i=0; i<n; i++){
            int h,w,d ;
            cin>> h>> w >> d ;
            arr.pb(box(h,min(w,d),max(w,d))) ;
            arr.pb(box(w,min(h,d),max(h,d))) ;
            arr.pb(box(d,min(w,h),max(w,h))) ;
        }
        sort(all(arr),cmp) ;
        n = 3*n ;
        for(int i=0; i<n; i++)
            height[i] = arr[i].h ;
        memset(dp,-1,sizeof dp) ;
        int ans = lis(0) ;
        cout<< ans << endl ;
    }

    return 0;
}

