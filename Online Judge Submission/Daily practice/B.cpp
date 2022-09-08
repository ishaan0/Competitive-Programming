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
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename... T>
#define     _clear              cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     ran(a, b)           ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define     mem(cont,h)         memset(cont, h, sizeof cont)
#define     count_bits(x)       __builtin_popcountll(x)
#define     SZ(cont)            (int)(cont).size()
#define     SQR(x)              ((x) * (x))
#define     Case                printf("Case %d: ", ++cs)
#define     PI                  (acos(-1.0))
#define     EPS                 (1e-9)
#define     pb                  push_back
#define     ff                  first
#define     ss                  second
#define     nl                  "\n"

#ifdef      local_device
#define     dbg(args...)        do{cerr<< #args << "-> " ;show(args);} while(0); cerr<< endl ;
#define     E_File              freopen("error.txt", "w", stderr) ;
#else
#define     dbg(args...)        ;
#define     E_File              ;
#endif

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;
typedef     pair <ll , ll >             pll ;

/** Debugging Tool **/
TM void show(T&&... args){((cerr<< args <<" "), ...);}
TP ostream& operator<<(ostream& os,const pair<F,S>& p){return os<<"("<<p.ff<<", "<<p.ss<<")";}
TS ostream& operator<<(ostream& os,const vector<T>& v){os << "{"; typename vector< T >::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if( it != v.begin() )os<<", ";os<<*it;}return os<<"}";}
TS ostream& operator<<(ostream& os,const set<T>& v){os<<"[";typename set<T>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
TS ostream& operator<<(ostream& os,const multiset<T>& v){os<<"[";typename multiset<T>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin()) os<<", ";os<< *it;}return os<<"]";}
TP ostream& operator<<(ostream& os,const map<F,S>& v){os<<"[";typename map<F,S>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<it->ff<<" = "<<it->ss;}return os<<"]";}
TP ostream& operator<<(ostream& os,const unordered_map<F,S>& v){os<<"[";typename unordered_map<F,S>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin()) os<<", ";os<<it->ff<<" = "<<it->ss;}return os<<"]";}
// TS ostream& operator<<(ostream& os,const ordered_set<T>& v){os<<"[";typename ordered_set<T>::const_iterator it;
//     for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
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

/** Functions Start **/
TM void read(T&... args){((cin>>args), ...);}
TM void write(T&&... args){((cout<<args<<" "), ...);}
inline void file_io(string path1 = "",string path2 = ""){
    if(path2.size() == 0) path2 = path1 ;
    freopen(path1.c_str(), "r", stdin) ;
    freopen(path2.c_str(), "w", stdout) ;
}

TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }
TP inline F resetBit(F mask, S pos) { return mask &= (~((F)1 << pos)) ; }
TP inline F toggleBit(F mask, S pos){ return mask ^= ((F)1 << pos) ; }

TS T egcd(T a,T b,T& x,T& y){ x=1,y=0;T x1=0,y1=1,a1=a,b1=b;while(b1){T q=a1/b1;tie(x,x1)=make_tuple(x1,x-q*x1);tie(y,y1)=make_tuple(y1,y-q*y1);tie(a1,b1)=make_tuple(b1,a1-q*b1) ;}return a1;}
long long bigMod(long long a,long long b,long long mod){a%=mod;long long res=1;while(b>0){if(b&1)res=((long long)res*a)%mod;a=((long long)a*a)%mod;b>>=1;}return res;}

inline ll modAdd(ll _a,ll _b,ll mod){if(abs(_a) >= mod) _a %= mod;if(abs(_b) >= mod) _b %= mod;if(_a<0){_a+=mod;}if(_b<0){_b+=mod;}if(_a+_b>=mod)return (_a+_b-mod);return (_a + _b);}
inline ll modMul(ll _a,ll _b,ll mod){if(abs(_a) >= mod) _a %= mod;if(abs(_b) >= mod) _b %= mod;if(_a<0){_a+=mod;}if(_b<0){_b+=mod;}return (_a*_b)%mod;}
inline ll modInv(ll a,ll mod){ return bigMod(a,mod-2,mod) ; }
/** Functions End **/

/** Direction Array **//*
const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;*/
/** Direction Array ends **/


const int lim = 1e6 + 5 ;

char str[lim] ;
int n ;
vector<int> adj[lim] ;

ll p[lim], base = 1949313259, mod = 2091573227 ;
pll value[lim] ;


void dfs(int u,int par,int lvl){
    value[u].ff = modAdd(modMul(str[u-1]+1007LL, p[lvl], mod), value[par].ff, mod) ;
    value[u].ss = modAdd(str[u-1]+1007LL, modMul(value[par].ss, base, mod), mod) ;
    for(int v: adj[u])
        if(v != par) dfs(v, u, lvl+1) ;
}



int solve(){
    scanf("%d %s", &n, str) ;

    for(int i = 0; i <= n; i++) adj[i].clear() ;

    for(int i = 0; i < n-1; i++){
        int u, v ;
        scanf("%d %d", &u, &v) ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    dfs(1, 0, 0) ;

    ll p = 0, q = n, g ;

    for(int i = 1; i <= n; i++)
        if(value[i].ff == value[i].ss) p++ ;

    g = __gcd(p, q) ;
    p /= g ;
    q /= g ;

    printf("%lld/%lld\n", p, q) ;

    return 0 ;
}


int main(){
    // file_io("input.in", "output.out") ;
    p[0] = 1 ;
    for(int i = 1; i < lim; i++) p[i] = modMul(p[i-1], base, mod) ;
    value[0].ff = value[0].ss = 0 ;
    E_File ;
    int t = 1,cs = 0 ;
    scanf("%d", &t) ;

    while(t--){
        printf("Case %d: ", ++cs) ;
        solve() ;
    }

    return 0;
}