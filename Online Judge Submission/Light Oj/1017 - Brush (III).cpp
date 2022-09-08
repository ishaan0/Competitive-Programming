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

ll n,w,k ;
ll dp[110][110] ;
ll y[110] ;

ll func(ll i,ll kr){
    if(kr==0 || i>=n) return 0 ;
    ll &ans = dp[i][kr] ;
    if(ans != -1) return ans ;

    ll up = upper_bound(y,y+n,y[i]+w) - y ;
    ll res = up-i ;
    ans = res+func(up,kr-1) ;
    ans = max(ans,func(i+1,kr)) ;
    return ans ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ,cs=0 ;
    cin>> t ;

    while(t--){
        memset(dp,-1,sizeof dp) ;
        cin>> n >> w >> k ;
        ll temp ;
        for(ll i=0; i<n; i++)
            cin>> temp >> y[i] ;
        sort(y,y+n) ;
        ll ans = func(0,k) ;
        Case ;
        cout<< ans << endl ;
    }


    return 0;
}


