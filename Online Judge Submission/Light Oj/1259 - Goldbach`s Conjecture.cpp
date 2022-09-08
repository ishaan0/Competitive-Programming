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
const int lim = 10000005 ;
bool mark[lim] ;
vector<int> primes ;

void sieve(){
    int sq = sqrt(lim-2) ;
    primes.pb(2) ;
    mark[0] = mark[1] = true ;
    for(int i=4; i<lim; i+=2) mark[i] = true ;
    for(int i=3; i<lim; i+=2){
        if(!mark[i]){
            primes.pb(i) ;
            if(i<=sq){
                for(int j=i*i; j<lim; j+= i*2)
                    mark[j] = true ;
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

    sieve() ;
    int t,cs=0 ;
    cin>> t ;

    while(t--){
        int n,cnt=0 ;
        cin>> n ;
        for(int i=0; primes[i]<=n/2; i++)
            if(!mark[n-primes[i]]) cnt++ ;
        Case ;
        cout<< cnt << endl ;
    }



    return 0;
}



