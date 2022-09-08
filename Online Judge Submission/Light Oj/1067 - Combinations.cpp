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

const int mod = 1000003 ;
const int lim = 1000005 ;

ll fact[lim],inv[lim] ;

ll bigMod(int a,int p){
    if(p <= 0) return 1 ;
    if(p&1) return ((a%mod)*bigMod(a,p-1))%mod ;
    else{
        ll temp = bigMod(a,p/2) ;
        return (temp*temp)%mod ;
    }
}

void preCal(){
    fact[0] = inv[0] = 1 ;
    for(int i=1; i<lim; i++){
        fact[i] = (fact[i-1]*i)%mod ;
        inv[i] = bigMod(fact[i],mod-2) ;
    }
}

ll nCr(int n,int r){
    return (fact[n]*((inv[r]*inv[n-r])%mod))%mod ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    preCal() ;
    int t,cs=0 ;
    cin>> t ;

    while(t--){
        int n,k ;
        cin>> n >> k ;
        Case ;
        cout<< nCr(n,k) << endl ;
    }


    return 0;
}



