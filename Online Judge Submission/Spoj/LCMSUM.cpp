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

ll res[1000005] ;
ll phi[1000005] ;
bool mark[1000005] ;

void preCal(ll n){
    for(ll i=1; i<=n; i++)
        phi[i] = i ;
    mark[0] = mark[1] =  true ;
    for(ll i=2; i<=n; i++){
        if(!mark[i]){
            phi[i] = i-1 ;
            for(ll j=i*2; j<=n; j+=i){
                mark[j] = true ;
                phi[j] = (phi[j]/i) * (i-1) ;
            }
        }
    }

    for(ll i=1; i<=n; i++){
        for(ll j=i; j<=n; j+=i)
            res[j] += (i*phi[i]) ;
    }
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    preCal(1000002) ;
    ll t ;
    scanf("%lld",&t) ;

    while(t--){
        ll n ;
        scanf("%lld",&n) ;
        ll ans = res[n] + 1 ;
        ans *= n ;
        ans /= 2 ;
        printf("%lld\n",ans) ;
    }

    return 0;
}



