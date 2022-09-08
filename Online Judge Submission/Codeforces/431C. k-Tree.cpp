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
const ll lim = 105 ;
const ll mod = 1000000007 ;

ll n,k,d ;
ll dp[lim][2] ;

ll func(ll sum,int taken){
    if(sum > n) return  0;
    else if(sum == n){
        if(taken == 1) return  1;
        else return 0;
    }
    ll &ans = dp[sum][taken] ;
    if(ans != -1) return ans ;
    ans = 0 ;

    for(int i=1; i<=k; i++){
        if(i >= d)
            ans += (func(sum+i,1))%mod ;
        else ans += (func(sum+i,taken))%mod ;
        ans %= mod ;
    }

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

    memset(dp,-1,sizeof dp) ;
    cin>> n >> k >> d ;

    ll ans = 0 ;
    for(int i=1; i<=k; i++){
        int taken = 0 ;
        if(i>=d) taken = 1 ;
        ans += (func(i,taken))%mod ;
        ans %= mod ;
    }

    cout<< ans << endl ;

    return 0;
}


