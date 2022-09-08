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

int arr[lim], cnt[lim][102] ;
int parent[lim][20], depth[lim] ;
vector<int> adj[lim] ;

void dfs(int u,int p,int d){
    if(p != -1){
        for(int i=1; i<=100; i++)
            cnt[u][i] = cnt[p][i] ;
    }
    cnt[u][ arr[u] ]++ ;
    depth[u] = d ;
    parent[u][0] = p ;

    for(int v: adj[u]){
        if(v == p) continue ;
        dfs(v, u, d+1) ;
    }
}

void build(int n){
    dfs(1, -1, 0) ;

    for(int j=1; (1<<j)<n; j++){
        for(int i=1; i<=n; i++){
            if(parent[i][j-1] != -1)
                parent[i][j] = parent[ parent[i][j-1] ][j-1] ;
        }
    }
}

int query(int p,int q){
    if(depth[p] < depth[q])
        swap(p,q) ;
    int lg = log2(depth[p]) ;
    for(int i=lg; i>=0; i--){
        if(depth[p]-(1<<i) >= depth[q])
            p = parent[p][i] ;
    }
    if(p == q) return p ;
    for(int i=lg; i>=0; i--){
        if(parent[p][i] != -1 && parent[p][i] != parent[q][i]){
            p = parent[p][i] ;
            q = parent[q][i] ;
        }
    }
    return parent[p][0] ;
}

void reset(){
    for(int i=0; i<lim; i++){
        adj[i].clear() ;
        arr[i] = depth[i] = 0 ;
    }
    CLR(cnt) ;
    NEG(parent) ;
}


int solve(){
    reset() ;

    int n, q ;
    cin>> n >> q ;

    for(int i=1; i<=n; i++)
        cin>> arr[i] ;
    
    for(int i=0; i<n-1; i++){
        int u, v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }

    build(n) ;
    
    while(q--){
        int u, v ;
        cin>> u >> v ;
        int p = query(u, v), last = -1e8, ans = 1e8 ;
        
        
        for(int i=1; i<=100; i++){
            int add = ((p == 1) ? cnt[p][i] : cnt[p][i]-cnt[ parent[p][0] ][i]) ;
            int x = cnt[u][i] + cnt[v][i] - (2*cnt[p][i]) + add ;
            
            if(x > 1) ans = 0 ;
            else if(x > 0){
                ans = min(ans, i - last) ;
                last = i ;
            }
        }

        cout<< ans << "\n" ;
    }

    return 0 ;
}


int main(){
    FastRead ;
    int t = 1,cs = 0 ;
    //scanf("%d", &t) ;
    cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}