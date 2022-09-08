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
#define     memz(cont)          memset(cont, 0, sizeof cont)
#define     memn(cont)          memset(cont, -1, sizeof cont)
#define     pcnt                __builtin_popcount
#define     pcntll              __builtin_popcountll
#define     sz(cont)            (int)(cont).size()
#define     sq(x)               ((x) * (x))
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

TP inline F amin(F &a,S b){ if(b<a) a=b ; return a ; }
TP inline F amax(F &a,S b){ if(b>a) a=b ; return a ; }

const double eps = 1e-9 ;
const ll mod = 1e9+7 ;

/** Functions Start **//*
TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }
TP inline F resetBit(F mask, S pos) { return mask &= (~((F)1 << pos)) ; }
TP inline F toggleBit(F mask, S pos){ return mask ^= ((F)1 << pos) ; }

TS T egcd(T a,T b,T &x,T &y){if(b==0){x=1;y=0;return a;}T x1,y1;T gcd=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return gcd;}
TP F bigMod(F a,S b){a%=mod;F res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}

TP inline F modAdd(F a,S b){ return ( (a%mod)+(b%mod) ) %mod ; }
TP inline F modSub(F a,S b){ return ( (a%mod)-(b%mod)+mod ) %mod ; }
TP inline F modMul(F a,S b){ return ( (a%mod)*(b%mod) ) %mod ; }
TS inline T modInv(T a){ return bigMod(a,mod-2) ; }*/
/** Functions End **/

/** Direction Array **//*
const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;*/
/** Direction Array ends **/


const ll lim = 1e5+5 ;
const ll blk = 350 ;

struct box{
    int l, r, idx ;
    bool operator < (box const &ob) const {
        return mp(l/blk, r) < mp(ob.l/blk, ob.r) ;
    }
};

int n,m,q,mx ;
int arr[lim], freq[lim], freqM[lim] ;
vector<box> range ;

inline void add(int id){
    int val = arr[id] ;
    freqM[ freq[val] ]-- ;
    freq[val]++ ;
    freqM[ freq[val] ]++ ;
    amax(mx, freq[val]) ;
}
inline void del(int id){
    int val = arr[id] ;
    freqM[ freq[val] ]-- ;
    if(freqM[ freq[val] ] <= 0 && mx == freq[val]) mx = freq[val] - 1 ;
    freq[val]-- ;
    freqM[ freq[val] ]++ ;
}



void Mo(){
    vector<int> ans(sz(range)) ;
    sort(all(range)) ;
    int l=0, r=-1 ;
    for(auto q: range){
        while(l > q.l) add(--l) ;
        while(r < q.r) add(++r) ;
        while(l < q.l) del(l++) ;
        while(r > q.r) del(r--) ;
        ans[q.idx] = mx ;
    }

    foreach(ans) pf("%d\n", val) ;
}


void reset(){
    memz(freq) ;
    memz(freqM) ;
    range.clear() ;
    mx = 1 ;
}

int solve(){
    reset() ;
    sf("%d %d %d", &n, &m, &q) ;    
    for(int i=0; i<n; i++) sf("%d", &arr[i]) ;

    for(int i=0; i<q; i++){
        box qry ;
        sf("%d %d", &qry.l, &qry.r) ;
        qry.l--, qry.r--, qry.idx = i ;
        range.pb(qry) ;
    }

    Mo() ;

    return 0 ;
}


int main()
{
    //Boost ;
    int t = 1,cs = 0 ;
    sf("%d",&t) ;

    while(t--){
        pf("Case %d:\n", ++cs) ;
        solve() ;
    }

    return 0;
}