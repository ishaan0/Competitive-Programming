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

ll sq(ll x){ return (ll)x*(ll)x ; }
ll ans ;

void solve(vector<ll> a,vector<ll> b,vector<ll> c){
    for(auto x: a){
        auto y = lower_bound(all(b),x) ;
        auto z = upper_bound(all(c),x) ;
        if(y == b.end() || z == c.begin()) continue ;
        z-- ;
        ans = min(ans,sq(x-*y)+sq(*y-*z)+sq(x-*z)) ;
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
        ll nr,ng,nb ;
        cin>> nr >> ng >> nb ;
        vector<ll> r(nr),g(ng),b(nb) ;
        foreach(r) cin>> value ;
        foreach(g) cin>> value ;
        foreach(b) cin>> value ;
        sort(all(r)) ;
        sort(all(g)) ;
        sort(all(b)) ;

        ans = 9e18 ;
        solve(r, g, b);
        solve(r, b, g);
        solve(g, b, r);
        solve(g, r, b);
        solve(b, r, g);
        solve(b, g, r);

        cout << ans << endl;
    }


    return 0;
}


