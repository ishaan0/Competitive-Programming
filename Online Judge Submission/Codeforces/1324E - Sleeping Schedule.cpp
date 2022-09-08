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
#define lim 2005
int n,h,l,r ;
int arr[lim],dp[lim][lim] ;

int func(int i,int take){
    if(i>=n){
        if(take>=l && take<=r)
            return 1 ;
        return 0 ;
    }
    int &ans = dp[i][take] ;
    if(ans != -1) return ans ;

    int val1 = func(i+1,(take+arr[i])%h) ;
    int val2 = func(i+1,(take+arr[i]-1)%h) ;
    ans = max(val1,val2) ;
    if(take>=l && take<=r && i>0)
        ans++ ;
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

    cin>> n >> h >> l >> r ;
    for(int i=0; i<n; i++)
        cin>> arr[i] ;
    memset(dp,-1,sizeof dp) ;
    int ans = func(0,0) ;

    cout<< ans << endl ;
    return 0;
}

