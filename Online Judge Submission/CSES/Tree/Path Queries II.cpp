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
#define     CLR(cont)           memset(cont, 0, sizeof cont)
#define     NEG(cont)           memset(cont, -1, sizeof cont)
#define     SZ(cont)            (int)(cont).size()
#define     SQR(x)              ((x) * (x))
#define     Case                printf("Case %d: ", ++cs) ;
#define     PI                  (acos(-1.0))
#define     mp                  make_pair
#define     pb                  push_back
#define     pob                 pop_back
#define     pf                  printf
#define     sf                  scanf
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


const int lim = 2e5 + 5 ; 

vector<int> adj[lim] ;
int chainNo, ptr, cost[lim], posInBase[lim] ;
int chainInd[lim], chainHead[lim] ;
int depth[lim], pa[lim][20], sbtr[lim] ;
vector<int> baseArray[lim], st[lim] ;

inline void reset(int n){
    for(int i=0; i<=n; i++){
        chainHead[i] = -1 ;
        for(int j=0; j<20; j++) pa[i][j] = -1 ;
    }
}

#define     left     (iter<<1)+1
#define     right    (iter<<1)+2

inline void mrg(int iter,int segNo){
    st[segNo][iter] = (st[segNo][left] > st[segNo][right]) ? st[segNo][left] : st[segNo][right] ;
}

void build_tree(int iter,int lo,int hi,int segNo){
    if(lo == hi){
        st[segNo][iter] = baseArray[segNo][lo] ;
        return ;
    }
    int mid = (lo+hi)>>1 ;
    build_tree(left, lo, mid, segNo) ;
    build_tree(right, mid+1, hi, segNo) ;
    mrg(iter,segNo) ;
}

void update_tree(int iter,int lo,int hi,int qi,int val,int segNo){
    if(qi < lo || qi > hi) return ;
    else if(qi <= lo && hi <= qi){
        st[segNo][iter] = val ;
        return ;
    }
    int mid = (lo+hi)>>1 ;
    update_tree(left, lo, mid, qi, val, segNo) ;
    update_tree(right, mid+1, hi, qi, val, segNo) ;
    mrg(iter,segNo) ;
}

int query_tree(int iter,int lo,int hi,int qi,int qj,int segNo){
    if(qj<lo || qi>hi) return INT_MIN ;
    else if(qi <= lo && hi <= qj) return st[segNo][iter] ;
    int mid = (lo+hi)>>1 ;
    int L = query_tree(left, lo, mid, qi, qj, segNo) ;
    int R = query_tree(right, mid+1, hi, qi, qj, segNo) ;
    return (L > R) ? L : R ;
}

void dfs(int u,int par,int _depth){
    pa[u][0] = par, depth[u] = _depth, sbtr[u] = 1 ;
    for(int v: adj[u]){
        if(v == par) continue ;
        dfs(v, u, _depth+1) ;
        sbtr[u] += sbtr[v] ;
    }
}

void build_lca(int n){
    for(int j=1; (1<<j)<n; j++){
        for(int i=0; i<n; i++){
            if(pa[i][j-1] != -1)
                pa[i][j] = pa[ pa[i][j-1] ][j-1] ;
        }
    }
}

int get_lca(int u,int v){
    if(depth[u] < depth[v])
        swap(u,v) ;
    int lg = log2(depth[u]) ;
    for(int i=lg; i>=0; i--){
        if(depth[u]-(1<<i) >= depth[v])
            u = pa[u][i] ;
    }
    if(u == v) return u ;
    for(int i=lg; i>=0; i--){
        if(pa[u][i] != -1 && pa[u][i] != pa[v][i]){
            u = pa[u][i] ;
            v = pa[v][i] ;
        }
    }
    return pa[u][0] ;
}

void build_hld(int u,int par){
    if(chainHead[ chainNo ] == -1) chainHead[ chainNo ] = u ;
    chainInd[ u ] = chainNo ;
    baseArray[ chainNo ].push_back( cost[u] ) ;
    posInBase[u] = ptr++ ;

    int bg = -1, mx = -1 ;
    for(int v: adj[u]){
        if(v == par) continue ;
        if(sbtr[v] > mx){
            mx = sbtr[v] ;
            bg = v ;
        }
    }

    if(bg != -1) build_hld(bg, u) ;

    for(int v: adj[u]){
        if(v == par || v == bg) continue ;
        chainNo++ ;
        ptr = 0 ;
        build_hld(v, u) ;
    }
}

int query_hld(int u,int v){
    int uchain, vchain = chainInd[v], ans = INT_MIN ;

    while(1){
        uchain = chainInd[u] ;
        if(uchain == vchain){
            int temp = query_tree(0, 0, SZ(baseArray[uchain])-1, posInBase[v], posInBase[u], uchain) ;
            ans = (ans > temp) ? ans : temp ;
            break ;
        }
        int temp = query_tree(0, 0, SZ(baseArray[uchain])-1, 0, posInBase[u], uchain) ;
        ans = (ans > temp) ? ans : temp ;
        u = chainHead[uchain] ;
        u = pa[u][0] ;
    }
    return ans ;
}


int solve(){
    int n, q ;
    scanf("%d %d", &n, &q) ;
    reset(n) ;

    for(int i=0; i<n; i++) scanf("%d", &cost[i]) ;
    for(int i=0; i<n-1; i++){
        int u, v ;
        scanf("%d %d", &u, &v) ;
        u--, v-- ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }

    dfs(0, -1, 0) ;
    build_lca(n) ;
    build_hld(0, -1) ;
    for(int i=0; i<=chainNo; i++){
        st[i].resize(4 * SZ(baseArray[i]) + 5) ;
        build_tree(0, 0, SZ(baseArray[i])-1, i) ;
    }

    while(q--){
        int tp, a, b ;
        scanf("%d %d %d", &tp, &a, &b) ;

        if(tp == 1){
            a-- ;
            update_tree(0, 0, SZ(baseArray[chainInd[a]])-1, posInBase[ a ], b, chainInd[a]) ;
        }
        else{
            a--, b-- ;
            int lca = get_lca(a, b) ;
            int x = query_hld(a, lca), y = query_hld(b, lca) ;
            int ans = (x > y) ? x : y ;
            printf("%d ", ans) ;
        }
    }

    return 0 ;
}


int main(){

    int t = 1,cs = 0 ;
    //scanf("%d", &t) ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}