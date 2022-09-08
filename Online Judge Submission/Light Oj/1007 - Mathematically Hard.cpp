#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     show(val)           cout<< #val << " -> " << val << endl
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs << ": "
#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second
#define     inf                 LONG_LONG_MIN
#define     INF                 LONG_LONG_MAX

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

ll const lim = 5e6+5 ;

bool mark[lim] ;
ull phi[lim] ;

void sievePhi(){
    for(ll i=1; i<lim; i++) phi[i] = i ;
    for(ll i=2; i<lim; i++){
        if(!mark[i]){
            phi[i] = i-1 ;
            for(ll j=2*i; j<lim; j+=i){
                phi[j] = (phi[j]/i) * (i-1) ;
                mark[j] = true ;
            }
        }
    }
    phi[0] = 0 ;
    for(ll i=1; i<lim; i++){
        phi[i] *= phi[i] ;
        phi[i] += phi[i-1] ;
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

    sievePhi() ;

    int t,cs=0 ;
    cin>> t;

    while(t--){
        ull a,b ;
        cin>> a >> b ;
        ull ans = phi[b] - phi[a-1] ;
        Case ;
        cout<< ans << endl ;
    }

    return 0;
}



