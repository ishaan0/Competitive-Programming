#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;


#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     memz(cont)          memset(cont, 0, sizeof cont)
#define     memn(cont)          memset(cont, -1, sizeof cont)
#define     Case                printf("Case %d: ",++cs)
#define     PI                  3.1415926535897932384
#define     pf                  printf
#define     sf                  scanf
#define     mp                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;
typedef     pair <ll , ll >             pll ;

/** Debugging Tool **/
TS void show(const T& v) {    cerr << v << ' ' ;}
TM void show(const T1& first,const T2&... rest){show(first);show(rest...);}
TP ostream& operator<<(ostream& os,const pair<F,S>& p){return os<<"("<<p.ff<<", "<<p.ss<<")";}
TS ostream& operator<<(ostream& os,const vector<T>& v){os << "{"; typename vector< T >::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if( it != v.begin() )os<<", ";os<<*it;}return os<<"}";}
TS ostream& operator<<(ostream& os,const set<T>& v){os<<"[";typename set<T>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
TP ostream& operator<<(ostream& os,const map<F,S>& v){os<<"[";typename map<F,S>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<it->ff<<" = "<<it->ss;}return os<<"]";}
/** Ends **/

const double eps = 1e-9 ;
/*
int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
int const drH[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
int const dcH[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;
*/

const ll lim = 1e7+5 ;
const ll mod = 1e9+7 ;
bool mark[lim] ;
int lpf[lim] ;
vector<int> prime ;

void sieve(){
    prime.pb(2) ;
    for(ll i=4; i<lim; i+=2) mark[i] = true ;
    for(ll i=3; i<lim; i+=2){
        if(mark[i]) continue ;
        prime.pb(i) ;
        for(ll j=i*i; j<lim; j+=2*i)
            mark[j] = true ;
    }

    for(ll i=0; i<prime.size(); i++){
        for(ll j=prime[i]; j<lim; j+=prime[i])
            lpf[j] = prime[i] ;
    }
}


map<ll,ll> ans, temp ;

void factorize(ll n){
    
    while(n>1){
        temp[ lpf[n] ]++ ;
        n /= lpf[n] ;
    }
    
}

ll bigMod(ll a,ll b){
    a %= mod ;
    ll res = 1 ;
    while(b>0){
        if(b&1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        b >>= 1 ;
    }
    return res ;
}


int solve(){
    ll n ;
    sf("%lld", &n) ;
    
    for(int i=0; i<n; i++){
        ll m ;
        sf("%lld", &m) ;
        
        temp.clear() ;

        while(m--){
            ll val ;
            sf("%lld", &val) ;
            factorize(val) ;
        }
        
        if(i){
            vector<int> id ;
            foreach(temp) if(ans.count(val.ff))
                ans[val.ff] = min(val.ss, ans[val.ff]) ;
            foreach(ans) if(!temp.count(val.ff)) id.pb(val.ff) ;
            foreach(id) ans.erase(val) ;
        }
        else foreach(temp) ans[val.ff] = val.ss ;

    }
    
    ll res = 1 ;
    
    foreach(ans)
        res = (res * bigMod(val.ff, val.ss)) % mod ;
    
    pf("%lld\n", res) ;

    return 0 ;
}


int main()
{
    sieve() ;
    //Boost ;
    int t = 1,cs = 0 ;
    //sf("%d",&t) ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}