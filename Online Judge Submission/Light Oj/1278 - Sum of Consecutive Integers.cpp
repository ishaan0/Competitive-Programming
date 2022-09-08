#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     show(val)           cout<< #val << " -> " << val << endl
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs << ": "
#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second
#define     ed                  "\n"

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;
const ll lim = 1e7+5 ;

bool mark[lim] ;
vector<int> primes ;

void sieve(){
    primes.pb(2) ;
    for(ll i=4; i<lim; i+=2) mark[i] = true ;
    for(ll i=3; i<lim; i+=2){
        if(!mark[i]){
            primes.pb(i) ;
            for(ll j=i*i; j<lim; j+=2*i)
                mark[j] = true ;
        }
    }
}

ll factorize(ll n){
    ll ans = 1 ;
    for(int i=0; i<primes.size()&&primes[i]*primes[i]<=n; i++){
        if(n%primes[i]!=0) continue ;
        ll cnt = 0 ;
        while(n%primes[i]==0){
            cnt++ ;
            n/=primes[i] ;
        }
        if(i) ans *= (cnt+1) ;
    }
    if(n>1 && n!=2)
        ans *= 2 ;
    return ans-1 ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    sieve() ;
    int t,cs=0 ;
    scanf("%d",&t) ;

    while(t--){
        ll n ;
        scanf("%lld",&n) ;
        ll ans = factorize(n) ;
        printf("Case %d: %lld\n",++cs,ans) ;
    }


    return 0;
}


