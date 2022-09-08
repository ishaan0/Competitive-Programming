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
const int mx = 1e6 ;

vector<int> primes[mx+5] ;
vector<int> divisor(mx+5) ;

void sieve(){
    for(int i=1; i<=mx; i++)
        for(int j=i; j<=mx; j+=i)
            divisor[j]++ ;
    for(int i=2; i<=mx; i++)
        if(primes[i].size()==0)
        for(int j=i; j<=mx; j+=i)
            primes[j].pb(i) ;
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

    int cnt= 0 ;
    for(int i=1; i<=mx; i++){
        int val = divisor[i] ;
        if(primes[val].size()==2 &&
           primes[val][0]*primes[val][1] == val){
            cnt++ ;
            if(cnt%9==0) cout<< i << endl  ;
        }
    }


    return 0;
}


