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
#define lim 200005
#define mod 998244353
ll f[lim],inv[lim] ;

ll bigMod(ll a, ll p){
    if(p<0) return 0 ;
    else if(p==0) return 1 ;
    else if(p&1)
        return ((a%mod)*(bigMod(a,p-1)))%mod ;
    else{
        ll temp = bigMod(a,p/2) ;
        return (temp*temp)%mod ;
    }
}

void dp(){
    f[0] = inv[0] = 1 ;
    for(ll i=1; i<lim; i++){
        f[i] = (f[i-1]*i)%mod ;
        inv[i] = bigMod(f[i],mod-2) ;
    }
}

ll nCr(ll n,ll r){
    if(n-r < 0) return 0 ;
    return (f[n]*((inv[r]*inv[n-r])%mod))%mod ;
}


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    dp() ;
    ll n ,m ;
    cin>> n >> m ;

    ll ans = nCr(m,n-1) ;
    ans = (ans*bigMod(2,n-3))%mod ;
    ans = (ans*(n-2))%mod ;

    cout<< ans << endl ;

    return 0;
}


