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

const ll lim = 1e5+5 ;

struct cmp{
    bool operator () (pll const a, pll const b) const{
        return ((a.ff-a.ff/2)*a.ss) > ((b.ff-b.ff/2)*b.ss) ;
    }
};

/// adj[u] = { v , w, c} 
vector<pair<ll, pll > > adj[lim] ; 
multiset<pll, cmp > ms[2]  ;
ll sum ;

ll dfs(ll u,ll par){
    ll cnt = 0 ;

    for(pair<ll, pll > v: adj[u]){
        if(v.ff == par) continue ;
        ll temp = dfs(v.ff,u) ;
        cnt += temp ;
        sum += v.ss.ff * temp ;
        if(v.ss.ss == 1) ms[0].insert(mp(v.ss.ff,temp)) ;
        else ms[1].insert(mp(v.ss.ff,temp)) ;
    }

    if(!cnt) cnt = 1 ;
    return cnt ;
}

void reset(){
    for(int i=0; i<lim; i++)
        adj[i].clear() ;
    ms[0].clear() , ms[1].clear() ;
    sum = 0 ;
}

int solve(){
    reset() ;

    ll n, w ;
    cin>> n >> w ;

    for(int i=0; i<n-1; i++){
        ll u,v,nw,c ;
        cin>> u >> v >> nw >> c ;
        adj[u].pb(mp(v,mp(nw,c))) ;
        adj[v].pb(mp(u,mp(nw,c))) ;
    }

    dfs(1,0) ;

    vector<ll> m[2] ;
    for(int i=0; i<2; i++){
        ll val = 0 ;
        while(ms[i].size() > 0){
            pll temp = *ms[i].begin() ;
            ms[i].erase(ms[i].begin()) ;
            val += (temp.ff-temp.ff/2)*temp.ss ;
            temp.ff /= 2LL ;
            if(temp.ff)
                ms[i].insert(temp) ;
            m[i].pb(val) ;
        }
    }


    ll req = sum - w, ans = 1e18 ;
    ll j = (ll)m[1].size() - 1LL ;

    if(req <= 0) return cout<< "0\n" , 0 ;

    for(ll i = 0; i<m[0].size(); i++){
        if(m[0][i] >= req) ans = min(ans, i+1) ;
        while(j>0LL && m[0][i]+m[1][j-1] >= req)
            j-- ;
        if(j>=0LL && m[0][i]+m[1][j] >= req)
            ans = min(ans, (i+1) + 2LL*(j+1)) ;
    }

    for(ll i=0; i<m[1].size(); i++)
        if(m[1][i] >= req) ans = min(ans, 2LL*(i+1)) ;

    cout<< ans << "\n" ;

    return 0 ;
}


int main()
{
    Boost ;
    int t = 1,cs = 0 ;
    cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}