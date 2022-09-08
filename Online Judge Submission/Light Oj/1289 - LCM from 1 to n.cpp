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
const ull mod = 4294967296 ;
const ll sz = 1e8+100 ;
const ll lim = (sz/64)+100 ;



ll setBit(ll n,ll pos){ return n |= ((ll)1<<pos); }
bool check(ll n,ll pos){ return (bool) (n & ((ll)1<<pos)); }

ll mark[lim] ;
unsigned primes[5761558];
unsigned int dp[5761558];
int cnt ;

void sieve(){
    int sq = sqrt(1e8+5) ;
    primes[cnt++] = 2 ;
    for(int i=4; i<sz; i+=2)
        mark[i/64] = setBit(mark[i/64],i%64) ;
    for(int i=3; i<sz; i+=2){
        if(!check(mark[i/64],i%64)){
            primes[cnt++] = i;
            if(i<=sq){
                for(int j=i*i; j<sz; j+=2*i)
                    mark[j/64] = setBit(mark[j/64],j%64) ;
            }
        }
    }
}


ull factorize(ull n){
    ull ans = 1 ;

    for(int i=0; i<cnt&&primes[i]*primes[i]<=n; i++){
        ull temp = n ;
        temp /= primes[i] ;
        while(temp >= primes[i]){
            ans = (ans*primes[i])%mod ;
            temp /= primes[i] ;
        }
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

    sieve() ;

    dp[0] = 2 ;
    for(int i=1; i<cnt; i++)
        dp[i] = (dp[i-1]*(ull)primes[i])%mod ;

    int t,cs= 0 ;
    cin>> t ;

    while(t--){
        ull n ;
        cin>> n ;
        ull ans = factorize(n) ;
        int up = upper_bound(primes,primes+cnt,n) - primes ;
        up-- ;
        ans = (ans*dp[up])%mod ;
        Case ;
        cout<< ans << endl ;
    }

    return 0;
}



