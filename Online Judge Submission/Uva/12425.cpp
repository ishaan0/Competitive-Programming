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
const double eps = 1e-9;

vector<int> primes ;
bool mark[1000005] ;

void seive(int n){
    int i,j,lim= sqrt(n) + eps ;
    for(int i=4; i<=n; i+=2)
        mark[i] = true ;
    mark[0]=mark[1] = true ;
    primes.pb(2) ;
    for(i=3; i<=n; i+=2){
        if(!mark[i]){
            primes.pb(i) ;
            if(i<=lim){
                for(j=i*i; j<=n; j+=i*2)
                    mark[j] = true ;
            }
        }
    }
}

ll phi(ll n){
    ll res = n ;
    ll lim = sqrt(n)+eps ;
    for(ll i=0; i<primes.size() && primes[i]<=lim; i++){
        if(n%primes[i] == 0){
            while(n%primes[i] == 0)
                n /= primes[i] ;
            res /= primes[i] ;
            res *= primes[i]-1 ;
        }
    }
    if(n!=1){
        res /= n ;
        res *= n-1 ;
    }
    return res ;
}


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0;
    cin>> t ;

    seive(1000004) ;
    while(t--){
        ll n,q ;
        cin>> n >>q ;
        vector<ll> div ;
        for(ll i=1; i*i<=n; i++){
            if(n%i == 0){
                div.pb(i) ;
                if(n/i != i) div.pb(n/i) ;
            }
        }
        sort(all(div)) ;
        vector<ll> ans ;
        cout<< "Case " << ++cs <<endl;
        for(int i=0; i<div.size(); i++){
            ans.pb(phi(n/div[i])) ;
            if(i) ans[i] += ans[i-1] ;
        }

        while(q--){
            ll x ;
            cin>> x ;
            if(x>=n){
                cout<< n << endl ;
                continue ;
            }
            if(x<1){
                cout<< "0" << endl ;
                continue ;
            }
            ll pos = upper_bound(all(div),x) - div.begin() ;
            pos-- ;
            cout<< ans[pos] << endl ;
        }
    }

    return 0;
}


