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
#define     mem(c1,c2)          memset(c1, c2, sizeof c1)
#define     sz(cont)            (int)(cont).size()
#define     sq(x)               ((x) * (x))
#define     Case                cout<< "Case "<< ++cs << ": "
#define     PI                  3.1415926535897932384
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
const ll mod = 1e9+7 ;

/** Functions Start **//*
TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }
TP inline F resetBit(F mask, S pos) { return mask &= (~((F)1 << pos)) ; }
TP inline F toggleBit(F mask, S pos){ return mask ^= ((F)1 << pos) ; }

ll egcd(ll a,ll b,ll &x,ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1;ll gcd=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return gcd;}
ll bigMod(ll a,ll b){a%=mod;ll res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}

inline ll MOD(ll a){ return (a%mod + mod) %mod ; }
inline ll modAdd(ll a,ll b){ return MOD( MOD(a) + MOD(b) ) ; }
inline ll modSub(ll a,ll b){ return MOD( MOD(a) - MOD(b) ) ; }
inline ll modMul(ll a,ll b){ return MOD( MOD(a) * MOD(b) ) ; }
inline ll modInv(ll a){ return bigMod(a,mod-2) ; }*/
/** Functions End **/

/** Direction Array **//*
const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;*/
/** Direction Array ends **/

#define     left    2*iter
#define     right   2*iter+1

const ll lim = 1e5 + 5 ; 

int n , q ;
int arr[lim], segtree[4*lim][4] ;

void mrg(int iter){
    for(int i=0; i<3; i++)
        segtree[iter][i] = segtree[left][i] + segtree[right][i] ;
}

void build(int iter,int lo,int hi){
    if(lo == hi){
        segtree[iter][0] = 1 ;
        return ;
    }
    int mid = lo + (hi-lo)/2 ;
    build(left, lo, mid) ;
    build(right, mid+1, hi) ;
    mrg(iter) ;
}

void lazy_up(int iter,int lo,int hi,int val){
    val %= 3 ;
    for(int i=0; i<val ; i++){
        swap(segtree[iter][1], segtree[iter][2]) ;
        swap(segtree[iter][0], segtree[iter][1]) ;
        segtree[iter][3] = ( segtree[iter][3] + 1 ) % 3 ;
    }
}
void push_down(int iter,int lo,int hi,int mid){
    lazy_up(left, lo, mid, segtree[iter][3]) ;
    lazy_up(right, mid+1, hi, segtree[iter][3]) ;
    segtree[iter][3] = 0 ;
}

void update(int iter,int lo,int hi,int qi,int qj){
    if(qj < lo || qi > hi) return ;
    if(qi <= lo && hi <= qj){
        lazy_up(iter, lo, hi, 1) ;
        return ;
    }
    int mid = lo + (hi-lo)/2 ;
    push_down(iter, lo, hi, mid) ;
    update(left, lo, mid, qi, qj) ;
    update(right, mid+1, hi, qi, qj) ;
    mrg(iter) ;
}

int query(int iter,int lo,int hi,int qi,int qj){
    if(qj < lo || qi > hi) return 0 ;
    if(qi <= lo && hi <= qj) return segtree[iter][0] ;
    int mid = lo + (hi-lo)/2 ;
    push_down(iter, lo, hi, mid) ;
    int lft = query(left, lo, mid, qi, qj) ;
    int rgt = query(right, mid+1, hi, qi, qj) ;
    mrg(iter) ;
    return lft + rgt ;
}


int solve(){
    mem(segtree, 0) ;
    scanf("%d %d", &n, &q) ;
    build(1, 1, n) ;

    while(q--){
        int tp, lo, hi ;
        scanf("%d %d %d", &tp, &lo, &hi) ;
        lo++, hi++ ;
        if(tp) printf("%d\n", query(1, 1, n, lo, hi)) ;
        else update(1, 1, n, lo, hi) ;
    }

    return 0 ;
}


int main()
{
    int t = 1,cs = 0 ;
    scanf("%d", &t) ;

    while(t--){
        printf("Case %d:\n", ++cs) ;
        solve() ;
    }

    return 0;
}