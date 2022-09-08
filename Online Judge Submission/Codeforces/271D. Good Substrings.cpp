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

const ll mod1 = 1423172537 ;
const ll mod2 = 1423165193 ;
const ll base1 = 61 ;
const ll base2 = 73 ;


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    string str,good ;
    ll k ;
    cin>> str >> good >> k ;

    set<pair<ll,ll> > s ;
    for(int i=0; i<str.size(); i++){
        ll h1 = 0, h2 = 0 , bad = 0 ;
        for(int j=i; j<str.size(); j++){
            if(good[ str[j]-'a' ] == '0') bad++ ;
            if(bad > k) break ;
            h1 = h1*base1 + str[j] ;
            h1 = (h1%mod1 + mod1) % mod1 ;
            h2 = h2*base2 + str[j] ;
            h2 = (h2%mod2 + mod2) % mod2 ;
            s.insert(mk(h1,h2)) ;
        }
    }

    cout<< s.size() << endl ;

    return 0;
}


