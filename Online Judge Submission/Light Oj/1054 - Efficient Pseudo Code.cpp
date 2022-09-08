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
const ll mod = 1000000007 ;
const int lim = 1e6+5 ;


bool mark[lim+5] ;
vector<int> primes ;

void sieve(){
    int sq = sqrt(lim) ;
    primes.pb(2) ;
    mark[0] = mark[1] = true ;
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

ll bigMod(ll a,ll p){
    if(p==0) return 1 ;
    else if(p&1) return ((a%mod)*bigMod(a,p-1))%mod ;
    else{
        ll temp = bigMod(a,p/2) ;
        temp = (temp*temp)%mod ;
        return temp ;
    }
}

ll sod(ll n,ll m){
    ll sum = 1 ;
    for(int i=0; i<primes.size()&&primes[i]*primes[i]<=n; i++){
        if(n%primes[i] == 0){
            ll cnt = 0 ;
            while(n%primes[i]==0){
                cnt++ ;
                n /= primes[i] ;
            }
            ll x = bigMod(primes[i],(cnt*m)+1) ;
            ll y = bigMod(primes[i]-1,mod-2) ;
            ll temp = (((x-1+mod)%mod)*((y+mod)%mod))%mod ;
            sum = (sum*temp)%mod ;
        }
    }
    if(n>1){
        ll x = bigMod(n,m+1) ;
        ll y = bigMod(n-1,mod-2) ;
        ll temp = (((x-1+mod)%mod)*((y+mod)%mod))%mod ;
        sum = (sum*temp)%mod ;
    }
    return sum ;
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
    int t,cs= 0 ;
    cin>> t ;

    while(t--){
        ll n,m ;
        cin>> n >> m ;
        Case ;
        ll ans = sod(n,m) ;
        cout<< ans << endl ;

    }



    return 0;
}



