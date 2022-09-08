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

const int lim = 3e4 + 5 ; 

vector<int> adj[lim] ;
int baseArray[lim], arr[lim], ptr, chainNo, n ;
int chainInd[lim], chainHead[lim], posInBase[lim] ;
int depth[lim], sparse[lim][20], sbtr[lim], sa[4*lim] ;

void reset(){
    for(int i = 0; i < lim; i++){
        adj[i].clear() ;
        chainHead[i] = -1 ;
        for(int j = 0; j < 20; j++)
            sparse[i][j] = -1 ;
    }
    ptr = chainNo = 0 ;
}

#define      left    (iter<<1)+1
#define      right   (iter<<1)+2

inline void mrg(int iter){
    sa[iter] = sa[left] + sa[right] ;
}

void build_segtree(int iter,int lo,int hi){
    if(lo == hi){
        sa[iter] = baseArray[lo] ;
        return ;
    }
    int mid = lo + (hi - lo)/2 ; 
    build_segtree(left, lo, mid) ;
    build_segtree(right, mid+1, hi) ;
    mrg(iter) ;
}

int query_segtree(int iter,int lo,int hi,int qi,int qj){
    if(qj < lo || qi > hi) return 0 ;
    else if(qi <= lo && hi <= qj) return sa[iter] ;
    int mid = lo + (hi - lo)/2 ;
    int lft = query_segtree(left, lo, mid, qi, qj) ;
    int rgt = query_segtree(right, mid+1, hi, qi, qj) ;
    return (lft + rgt) ;
}

void update_segtree(int iter,int lo,int hi,int qi,int val){
    if(qi < lo || qi > hi) return ;
    else if(qi <= lo && hi <= qi){
        sa[iter] = val ;
        return ;
    }
    int mid = lo + (hi - lo)/2 ;
    update_segtree(left, lo, mid, qi, val) ;
    update_segtree(right, mid+1, hi, qi, val) ;
    mrg(iter) ;
}

void dfs(int u,int p,int d = 0){
    sparse[u][0] = p, depth[u] = d, sbtr[u] = 1 ;

    for(int v: adj[u]){
        if(v == p) continue ;
        dfs(v, u, d+1) ;
        sbtr[u] += sbtr[v] ;
    }
}

void build_lca(int n){
    for(int j=1; (1<<j)<n; j++){
        for(int i=0; i<n; i++){
            if(sparse[i][j-1] != -1)
                sparse[i][j] = sparse[ sparse[i][j-1] ][j-1] ;
        }
    }
}

int get_lca(int u,int v){
    if(depth[u] < depth[v])
        swap(u,v) ;
    int lg = log2(depth[u]) ;
    for(int i=lg; i>=0; i--){
        if(depth[u]-(1<<i) >= depth[v])
            u = sparse[u][i] ;
    }
    if(u == v) return u ;
    for(int i=lg; i>=0; i--){
        if(sparse[u][i] != -1 && sparse[u][i] != sparse[v][i]){
            u = sparse[u][i] ;
            v = sparse[v][i] ;
        }
    }

    return sparse[u][0] ;
}

void build_hld(int u,int p){
    if(chainHead[ chainNo ] == -1)
        chainHead[ chainNo ] = u ;
    chainInd[u] = chainNo ;
    posInBase[u] = ptr ;
    baseArray[ptr++] = arr[u] ;

    int mx = -1, bg = -1 ;
    for(int v: adj[u]){
        if(v == p) continue ;
        if(sbtr[v] > mx){
            mx = sbtr[v] ;
            bg = v ;
        }
    }

    if(bg != -1) build_hld(bg, u) ;

    for(int v: adj[u]){
        if(v == p || v == bg) continue ;
        chainNo++ ;
        build_hld(v, u) ;
    }
}

int query_hld(int u,int v){
    if(u == v) return query_segtree(0, 0, ptr-1, posInBase[v], posInBase[u]) ;
    int uChain, vChain = chainInd[v], res = 0 ;

    while(true){
        uChain = chainInd[u] ;
        if(uChain == vChain){
            int temp = query_segtree(0, 0, ptr-1, posInBase[v], posInBase[u]) ;
            res += temp ;
            break ;
        }
        int temp = query_segtree(0, 0, ptr-1, posInBase[ chainHead[uChain] ], posInBase[u]) ;
        res += temp ;
        u = chainHead[uChain] ;
        u = sparse[u][0] ;
    }
    return res ;
}


int solve(){
    reset() ;
    scanf("%d", &n) ;
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]) ;

    for(int i = 0; i < n-1; i++){
        int u, v ;
        scanf("%d %d", &u, &v) ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }

    dfs(0, -1) ;
    build_hld(0, -1) ;
    build_segtree(0, 0, ptr-1) ;
    build_lca(n) ;

    int q ;
    scanf("%d", &q) ;

    while(q--){
        int tp, i, j ;
        scanf("%d %d %d", &tp, &i, &j) ;
        if(!tp){
            int lca = get_lca(i, j) ;
            int res = query_hld(i, lca) + query_hld(j, lca) - query_hld(lca,lca) ;
            printf("%d\n", res) ;
        }
        else update_segtree(0, 0, ptr-1, posInBase[i], j) ;
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