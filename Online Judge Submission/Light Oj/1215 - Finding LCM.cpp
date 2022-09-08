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
#define     ed                  "\n"

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;
const int lim = 1e6+5 ;

bool mark[lim] ;
vector<int> primes ;

void sieve(){
    int sq = sqrt(lim-2) ;
    mark[0] = mark[1] = true ;
    primes.pb(2) ;
    for(int i=4; i<lim; i+=2) mark[i] = true ;
    for(int i=3; i<lim; i+=2){
        if(!mark[i]){
            primes.pb(i) ;
            if(i<=sq){
                for(int j=i*i; j<lim; j+=2*i)
                    mark[j] = true ;
            }
        }
    }
}


ll factorize(ll a,ll b){
    ll ans = 1 ;
    for(int i=0; i<primes.size()&&primes[i]*primes[i]<=b; i++){
        if(b%primes[i] == 0){
            ll temp1 = 1,temp2 = 1 ;
            while(a%primes[i] ==0){
                temp1 *= primes[i] ;
                a /= primes[i] ;
            }
            while(b%primes[i] ==0){
                temp2 *= primes[i] ;
                b /= primes[i] ;
            }
            ll mx = max(temp1,temp2) ;
            if(mx == temp1) continue ;
            ans *= mx ;
        }
    }
    if(b > 1 && a == 1)
        ans *= b ;
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

    sieve() ;
    int t,cs = 0 ;
    cin>>t ;

    while(t--){
        ll a,b,l ;
        cin>> a >>b >> l ;
        ll lcm = (a*b)/(__gcd(a,b)) ;
        Case ;
        if(l%lcm != 0){
            cout<< "impossible" << endl ;
            continue ;
        }
        ll ans = factorize(lcm,l) ;
        cout<< ans << endl ;
    }


    return 0;
}



