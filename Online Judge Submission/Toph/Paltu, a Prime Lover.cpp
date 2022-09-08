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

const ll lim1 = 1e8+5 ;
const ll lim2 = 1e5+5 ;

ll mark[ (lim1/64)+5 ] ;
vector<int> prime ;

inline ll   setBit(ll num, ll pos){ return num = (num | (1LL<<pos)); }
inline bool getBit(ll num, ll pos){ return (bool)(num & (1LL<<pos)); }

void sieve(){
    prime.pb(2) ;
    for(ll i=4; i<lim1; i+=2) mark[i/64LL] = setBit(mark[i/64LL], i%64LL) ;
    for(ll i=3; i<lim1; i+=2){
        if(getBit(mark[i/64LL], i%64LL)) continue ;
        prime.pb(i) ;
        for(ll j=i*i; j<lim1; j+=2*i)
            mark[j/64LL] = setBit(mark[j/64LL], j%64LL) ;
    }
}

ll arr[lim2] , segtree[2][4*lim2] ;

void build(int node,int lo,int hi){
    if(lo == hi){
        segtree[0][node] = segtree[1][node] = arr[lo] ;
        return ;
    }
    int mid = lo + (hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    segtree[0][node] = min(segtree[0][2*node], segtree[0][2*node+1]) ;
    segtree[1][node] = max(segtree[1][2*node], segtree[1][2*node+1]) ;
}

void update(int node,int lo,int hi,int i,int val){
    if(i<lo || i>hi) return ;
    if(i<=lo && hi<=i) {
        segtree[0][node] = segtree[1][node] = val ;
        return ;
    }
    int mid = lo + (hi-lo)/2 ;
    update(2*node,lo,mid,i,val) ;
    update(2*node+1,mid+1,hi,i,val) ;
    segtree[0][node] = min(segtree[0][2*node], segtree[0][2*node+1]) ;
    segtree[1][node] = max(segtree[1][2*node], segtree[1][2*node+1]) ;
}

pii query(int node,int lo,int hi,int i,int j){
    if(j<lo || i>hi) return mp(INT_MAX,INT_MIN) ;
    if(i<=lo && hi<=j) return mp(segtree[0][node],segtree[1][node]) ;
    int mid = lo + (hi-lo)/2 ;
    pii lft = query(2*node,lo,mid,i,j) ;
    pii rgt = query(2*node+1,mid+1,hi,i,j) ;
    return mp(min(lft.ff,rgt.ff),max(lft.ss,rgt.ss)) ;
}

int solve(){
    ll n , q ;
    sf("%lld %lld", &n, &q) ;
    for(int i=1; i<=n; i++) sf("%lld", &arr[i]) ;
    build(1,1,n) ;

    while(q--){
        ll t ;
        sf("%lld", &t) ;
        if(t==1){
            ll l,v ;
            sf("%lld %lld", &l, &v) ;
            update(1,1,n,l,v) ;
        }
        else{
            ll l,r ;
            sf("%lld %lld", &l, &r) ;
            pii ans = query(1,1,n,l,r) ;
            
            ll p1 = upper_bound(all(prime),ans.ff-1) - prime.begin() ;
            ll p2 = upper_bound(all(prime),ans.ss) - prime.begin() ;
            
            pf("%lld\n", p2-p1) ;
        }
    }


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