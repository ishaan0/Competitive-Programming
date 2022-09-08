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
#define     Read                freopen("input.txt", "r", stdin) ;
#define     Write               freopne("output.txt", "w", stdout) ;
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
#define     Case                printf("Case %d: ", ++cs) ;
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

/** Double Comparisons **//*
bool equalTo(double a,double b){return ((fabs(a-b)<=EPS) ? true : false);}
bool notEqual(double a,double b){return ((fabs(a-b)>EPS) ? true : false);}
bool lessThan(double a,double b){return ((a+EPS<b) ? true : false);}
bool lessThanEqual(double a,double b){return ((a<b+EPS) ? true : false);}
bool greaterThan(double a,double b){return ((a>b+EPS) ? true : false);}
bool greaterThanEqual(double a,double b){return ((a+EPS>b) ? true : false);}
*/

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
/*
TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }
TP inline F resetBit(F mask, S pos) { return mask &= (~((F)1 << pos)) ; }
TP inline F toggleBit(F mask, S pos){ return mask ^= ((F)1 << pos) ; }

TS T egcd(T a,T b,T& x,T& y){ x=1,y=0;T x1=0,y1=1,a1=a,b1=b;while(b1){T q=a1/b1;tie(x,x1)=make_tuple(x1,x-q*x1);tie(y,y1)=make_tuple(y1,y-q*y1);tie(a1,b1)=make_tuple(b1,a1-q*b1) ;}return a1;}
TP F bigMod(F a,F b,S mod){a%=mod;F res=1;while(b>0){if(b&1)res=((long long)res*a)%mod;a=((long long)a*a)%mod;b>>=1;}return res;}

inline int modAdd(ll _a,ll _b,ll mod){if(_a<0){_a+=mod;}if(_b<0){_b+=mod;}if(_a+_b>=mod)return (_a+_b-mod);return (_a + _b);}
inline int modMul(ll _a,ll _b,ll mod){if(_a<0){_a+=mod;}if(_b<0){_b+=mod;}return (_a*_b)%mod;}
inline int modInv(ll a,ll mod){ return bigMod(a,mod-2,mod) ; }*/
/** Functions End **/

/** Direction Array **//*
const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;*/
/** Direction Array ends **/

const int lim = 2e5 + 5 ;
const int blk = 2500 ;

struct query{
    int l, r, t, idx ;
    query(){}
    query(int _l,int _r,int _t,int _idx){
        l=_l, r=_r, t=_t, idx=_idx ;
    }
    bool operator < (const query& ob) const{
        if((l/blk) == (ob.l/blk)){
            if((r/blk) == (ob.r/blk)) return t < ob.t ;
            return r < ob.r ;
        }
        return l < ob.l ;
    }
};

struct update{
    int pos, old, cur ;
    update(){}
    update(int _pos,int _old,int _cur){
        pos=_pos, old=_old, cur=_cur ;
    }
} ;

int nxt, n, q, arr[lim] ;
int curL, curR, f[lim], fp[lim] ;
map<int,int> mp ;

vector<query> Q ;
vector<update> U ;
vector<int> ans ;

inline void Add(int i){
    int el = arr[i] ;
    fp[ f[el] ]--, f[el]++, fp[ f[el] ]++ ;
}
inline void Remove(int i){
    int el = arr[i] ;
    fp[ f[el] ]--, f[el]--, fp[ f[el] ]++ ;
}

void upd(int pos,int x){
    if(pos >= curL && pos <= curR){
        Remove(pos) ;
        arr[pos] = x ;
        Add(pos) ;
    }
    else arr[pos] = x ;
}

inline int get(int val){
    if(mp.count(val)) return mp[val] ;
    return mp[val] = ++nxt ;
}

void Mo(){
    sort(all(Q)) ;
    int tm = SZ(U) ;
    curL = 0, curR = -1 ;
    for(auto q: Q){
        while(tm < q.t) tm++, upd(U[tm-1].pos, U[tm-1].cur) ;
        while(tm > q.t) upd(U[tm-1].pos, U[tm-1].old), tm-- ;

        while(curL > q.l)      
            Add(--curL) ;
        while(curR < q.r)     
            Add(++curR) ;
        while(curL < q.l)      
            Remove(curL++) ;
        while(curR > q.r) 
            Remove(curR--) ;
        int cur = 1 ;
        while(fp[cur] > 0) cur++ ;
        ans[ q.idx ] = cur ;
    }
}

int solve(){
    cin>> n >> q ;
    for(int i = 0; i < n; i++){
        cin>> arr[i] ;
        arr[i] = get(arr[i]) ;
    }

    int q_cnt = 0 ;
    for(int i = 0; i < q; i++){
        int tp ;
        cin>> tp ;
        if(tp == 1){
            int l, r ;
            cin>> l >> r ;
            l--, r-- ;
            Q.push_back(query(l, r, SZ(U), q_cnt++)) ;
        }
        else{
            int p, x ;
            cin>> p >> x ;
            p-- ;
            x = get(x) ;
            U.push_back(update(p, arr[p], x)) ;
            arr[p] = x ;
        }
    }

    ans.resize(SZ(Q)) ;
    Mo() ;

    for(int el: ans) cout<< el << nl ;

    return 0 ;
}

/* problem link : https://codeforces.com/problemset/problem/940/F */

int main(){
    FastRead ;
    E_File ;
    int t = 1,cs = 0 ;
    //scanf("%d", &t) ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}