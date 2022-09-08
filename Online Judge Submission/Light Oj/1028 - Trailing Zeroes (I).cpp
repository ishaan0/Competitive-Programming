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

#define lim 1000010

bool mark[lim] ;
vector<int> primes ;

void sieve(){
    int sq = sqrt(lim)+2,n=lim-5;
    for(int i=4; i<=n; i+=2)
        mark[i] = true ;
    primes.pb(2) ;
    for(int i=3; i<=n; i+=2){
        if(!mark[i]){
            primes.pb(i) ;
            if(i<=sq){
                for(int j=i*i; j<=n; j+=2*i)
                    mark[j] = true ;
            }
        }
    }
}


ll factorize(ll n){
    ll ans = 1 ;
    for(int i=0; i<primes.size()&&primes[i]*primes[i]<=n; i++){
        if(n%primes[i] != 0) continue ;
        int cnt=0 ;
        while(n%primes[i]==0){
            cnt++ ;
            n /= primes[i] ;
        }
        ans *= (cnt+1) ;
    }
    if(n>1) ans *= 2 ;
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

    int t,cs=0;
    cin>> t ;
    sieve() ;
    while(t--){
        ll n ;
        cin>> n ;
        ll ans = factorize(n) -1;
        Case ;
        cout<< ans << endl ;
    }


    return 0;
}


