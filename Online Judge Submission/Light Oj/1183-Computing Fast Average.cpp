/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

PBDS
*x.find_by_order(pos) ----> returns the value at "pos" index in the set 0-based
x.order_of_key(value)     ----> returns the position of "value" in the set 0-based

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;

Large primes : 479001599, 1979339339, 1000163491, 1000173893, 1423165193, 1423172537, 2513475829
Small primes : 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
*/
#include <bits/stdc++.h>
using namespace std;


#define     FastRead            ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     _clear              cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     ran(a, b)           ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define     mem(cont,h)         memset(cont, h, sizeof cont)
#define     SZ(cont)            (int)(cont).size()
#define     SQR(x)              ((x) * (x))
#define     Case                printf("Case %d:\n", ++cs) ;
#define     PI                  (acos(-1.0))
#define     EPS                 (1e-9)
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;
typedef     pair <ll , ll >             pll ;

/** Debugging Tool **/
TS void show(const T& v) { cerr << v << ' ' ;}
TM void show(const T1& first,const T2&... rest){show(first);show(rest...);}
TP ostream& operator<<(ostream& os,const pair<F,S>& p){return os<<"("<<p.ff<<", "<<p.ss<<")";}
TS ostream& operator<<(ostream& os,const vector<T>& v){os << "{"; typename vector< T >::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if( it != v.begin() )os<<", ";os<<*it;}return os<<"}";}
TS ostream& operator<<(ostream& os,const set<T>& v){os<<"[";typename set<T>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
TP ostream& operator<<(ostream& os,const map<F,S>& v){os<<"[";typename map<F,S>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<it->ff<<" = "<<it->ss;}return os<<"]";}
struct dbg_time{clock_t start;dbg_time(){start=clock();}void reset(){start=clock();}void get(){fprintf(stderr,"%0.6f\n",(clock()-start)/(1.0*CLOCKS_PER_SEC));}};
/** Ends **/


/** Tricks for hash_map **//*
struct custom_hash {
    static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    size_t operator()(uint64_t x) const{static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+FIXED_RANDOM);}
    size_t operator()(pair<uint64_t,uint64_t> x) const{static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);}
};
m.reserve(1024) ;
m.max_load_factor(0.25) ;*/
/** Tricks ends **/

/** Functions Start **//*
TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }
TP inline F resetBit(F mask, S pos) { return mask &= (~((F)1 << pos)) ; }
TP inline F toggleBit(F mask, S pos){ return mask ^= ((F)1 << pos) ; }

ll egcd(ll a,ll b,ll &x,ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1;ll gcd=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return gcd;}
ll bigMod(ll a,ll b,ll mod){a%=mod;ll res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}

inline ll modAdd(ll _a,ll _b,ll mod){if(_a<0){_a+=mod;}if(_b<0){_b+=mod;}if(_a+_b>=mod)return (_a+_b-mod);return (_a + _b);}
inline ll modMul(ll _a,ll _b,ll mod){if(_a<0){_a+=mod;}if(_b<0){_b+=mod;}return (_a*_b)%mod;}
inline ll modInv(ll a,ll mod){ return bigMod(a,mod-2,mod) ; }*/
/** Functions End **/

/** Direction Array **//*
const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;*/
/** Direction Array ends **/


struct node{
    int sum, lazy ;
    node(){ sum = 0, lazy = -1 ; }
    node(int _sum,int _lazy){
        sum = _sum, lazy = _lazy ;
    }
};

const int maxN = 1e5 + 5 ; 
node segtree[4 * maxN] ;

#define     left     2*iter 
#define     right    2*iter+1
inline void mrg(int iter){
    segtree[iter].sum = segtree[left].sum + segtree[right].sum ;
}

void build(int iter,int lo,int hi){
    if(lo == hi){
        segtree[iter] = node(0, -1) ;
        return ;
    }
    int mid = lo + (hi - lo)/2 ;
    build(left, lo, mid) ;
    build(right, mid+1, hi) ;
    mrg(iter) ;
    segtree[iter].lazy = -1 ;
}

inline void lazy_update(int iter,int lo,int hi,int x){
    segtree[iter].sum = (hi-lo+1) * x ;
    segtree[iter].lazy = x ;
}

inline void push_down(int iter,int lo,int hi,int mid){
    if(segtree[iter].lazy == -1) return ;
    lazy_update(left,lo,mid,segtree[iter].lazy) ;
    lazy_update(right,mid+1,hi,segtree[iter].lazy) ;
    segtree[iter].lazy = -1 ;
}

void update(int iter,int lo,int hi,int qi,int qj,int x){
    if(qj < lo || qi > hi) return ;
    if(qi <= lo && hi <= qj){
        lazy_update(iter,lo,hi,x) ;
        return ;
    }
    int mid = lo + (hi-lo)/2 ;
    push_down(iter,lo,hi,mid) ;
    update(left,lo,mid,qi,qj,x) ;
    update(right,mid+1,hi,qi,qj,x) ;
    mrg(iter) ;
}

int query(int iter,int lo,int hi,int qi,int qj){
    if(lo > qj || hi < qi) return 0 ;
    if(qi <= lo && hi <= qj) return segtree[iter].sum ;
    int mid = lo + (hi-lo)/2 ;
    push_down(iter,lo,hi,mid) ;
    int L = query(left,lo,mid,qi,qj) ;
    int R = query(right,mid+1,hi,qi,qj) ;
    mrg(iter) ;
    return L + R ;
}


int solve(){
    int n, q ;
    scanf("%d %d", &n, &q) ;
    build(1, 1, n) ;

    while(q--){
        int tp, i, j, v ;
        scanf("%d %d %d", &tp, &i, &j) ;
        if(tp == 1){
            scanf("%d", &v) ;
            update(1, 1, n, i+1, j+1, v) ;
        }
        else{
            int ans = query(1, 1, n, i+1, j+1) ;
            if(ans % (j-i+1) != 0){
                int a = ans/__gcd(ans, j-i+1) ;
                int b = (j-i+1)/__gcd(ans, j-i+1) ;
                printf("%d/%d\n", a, b) ;
            }
            else printf("%d\n", ans/(j-i+1)) ;
        }
    }

    return 0 ;
}


int main(){

    int t = 1,cs = 0 ;
    scanf("%d", &t) ;

    while(t--){
        Case ;
        solve() ;
    }

    return 0;
}