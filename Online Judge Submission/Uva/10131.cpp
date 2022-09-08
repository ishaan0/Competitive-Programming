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

int dp[1005],dir[1005],n;
struct data{
    data(int a,int b,int c){w=a,s=b,idx=c;}
    int w,s,idx ;
};
vector<data> arr ;

bool cmp(data a,data b){
    return a.s>b.s ;
}

int lis(int i){
    int &ans = dp[i] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    for(int j=i+1; j<n; j++){
        if(arr[j].w > arr[i].w){
            int len = lis(j) ;
            if(len > ans){
                ans = len ;
                dir[i] = j ;
            }
        }
    }
    ans++ ;
    return ans ;
}

void print(int i){
    if(i == -1) return ;
    cout<< arr[i].idx << endl ;
    print(dir[i]) ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif


    n=1 ;
    int a,b ;
    while(cin>> a >> b ){
        arr.pb(data(a,b,n)) ;
        n++ ;
    }
    sort(all(arr),cmp) ;

    memset(dp, -1, sizeof dp) ;
    memset(dir, -1, sizeof dir) ;
    int ans = -1,st ;
    for(int i=0; i<n; i++){
        int tt = lis(i) ;
        if(tt > ans){
            ans = tt ;
            st = i ;
        }
    }
    cout<< ans << endl ;
    for(int i=0; i<n; i++)
    if(dp[i] == ans){
        print(i) ;
        break ;
    }

    return 0;
}




