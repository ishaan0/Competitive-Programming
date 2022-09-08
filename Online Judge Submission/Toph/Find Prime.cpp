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


vector<int> primes ;
int mark[610] ;

void seive(){
    int i,j,n=600,lim=sqrt(n)+2 ;
    for(int i=4; i<=n; i+=2)
        mark[i] = 1 ;
    primes.pb(2) ;
    for(int i=3; i<=n; i+=2){
        if(!mark[i]){
            primes.pb(i) ;
            if(i<=lim){
                for(int j=i*i; j<=n; j+=i*2)
                    mark[j] = 1 ;
            }
        }
    }
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    seive() ;
    int t ;
    cin>> t ;

    while(t--){
        int n;
        cin>> n ;
        int p1 = lower_bound(all(primes),n) - primes.begin() ;
        int v1,v2 ;
        if(primes[p1] == n){
            v1 = primes[p1-1] ;
            v2 = primes[p1+1] ;
        }
        else{
            v1 = primes[p1-1] ;
            v2 = primes[p1] ;
        }
        cout<< v1 << " " << v2 << endl ;
    }


    return 0;
}


