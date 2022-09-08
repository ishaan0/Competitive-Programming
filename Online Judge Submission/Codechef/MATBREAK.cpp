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
const ll mod = 1e9+7 ;


ll bigMod(ll a,ll p){
    if(p==0) return 1 ;
    else if(p&1)
        return ((a%mod)*bigMod(a,p-1))%mod ;
    else{
        ll temp = bigMod(a,p/2) ;
        temp = (temp*temp)%mod ;
        return temp ;
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

    int t ;
    cin>> t ;

    while(t--){
        ll n,a ;
        cin>> n >> a ;

        ll cur = a,sum = 0;
        for(int i=1; i<=n; i++){
            ll pro = bigMod(cur,(2*i-1)) ;
            sum = (sum + pro) %mod ;
            cur = (cur*pro)%mod ;
        }

        cout<< sum << endl ;
    }


    return 0;
}


