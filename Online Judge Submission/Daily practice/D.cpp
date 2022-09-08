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



// const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
// const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;

const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1} ;
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1} ;

int solve(){
    int n, m, p, q, c[8] ;
    pii s, d ;

    cin>> n >> m >> p >> q ;
    cin>> s.ff >> s.ss >> d.ff >> d.ss ;
    for(int i = 0; i < 8; i++)
        cin>> c[i] ;
        
    vector< pair<pii, ll> > grid[n+5][m+5] ;
    bool blockCell[n+5][m+5] ;
    ll dis[n+5][m+5][9] ;


    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            blockCell[i][j] = 0 ;
            for(int k = 0; k < 9; k++)
                dis[i][j][k] = 1e18 ;
        }
    }

    for(int i = 0; i < p; i++){
        pii u, v ;
        ll w ;
        cin>> u.ff >> u.ss >> v.ff >> v.ss >> w ;
        grid[u.ff][u.ss].push_back({v, w}) ;
    }


    for(int i = 0; i < q; i++){
        pii u ;
        cin>> u.ff >> u.ss ;
        blockCell[u.ff][u.ss] = 1 ;
    }


    using piii = pair<ll, pair<pii, int>>  ;
    priority_queue< piii, vector<piii >, greater<piii > > pq ;

    
    pq.push({0, {s, 9}}) ;
    for(int i = 0; i < 8; i++)
        dis[s.ff][s.ss][i] = 0 ;


    while(!pq.empty()){
        piii temp = pq.top() ;
        pq.pop() ;
        ll wt = temp.ff, dir = temp.ss.ss ;
        pii u = temp.ss.ff ;
        // dbg(wt, u, dir)
        ll mn = dis[u.ff][u.ss][0] ;
        for(int i = 0; i < 9; i++)
            mn = min(mn, dis[u.ff][u.ss][i]) ;
        if(wt > mn) 
            continue ;

        for(int i = 0; i < 8; i++){
            pll v ;
            v.ff = u.ff + dr[i] ;
            v.ss = u.ss + dc[i] ;

            if(v.ff<=0 || v.ff>n || v.ss<=0 || v.ss>m || blockCell[v.ff][v.ss])
                continue ;

            ll tempWeight = (i == dir) ? 0 : c[i] ;
            // ll mn = dis[u.ff][u.ss][0] ;
            // for(int j = 0; j < 9; j++) 
            //     mn = min(mn, dis[u.ff][u.ss][j]) ;

            if(mn + c[i] <= dis[v.ff][v.ss][i]){
                dis[v.ff][v.ss][i] = mn + c[i] ;
                pq.push({dis[v.ff][v.ss][i], {v, i}}) ;
            }

            if(dis[u.ff][u.ss][i] <= dis[v.ff][v.ss][i]){
                dis[v.ff][v.ss][i] = dis[u.ff][u.ss][i] ;
                if(u.ff == s.ff && u.ss == s.ss) 
                    dis[v.ff][v.ss][i] += c[i] ;
                pq.push({dis[v.ff][v.ss][i], {v, i}}) ;
            }
        }

        for(auto val: grid[u.ff][u.ss]){
            ll mnn = dis[u.ff][u.ss][0] ;
            for(int j = 0; j < 9; j++)
                mnn = min(mnn, dis[u.ff][u.ss][j]) ;

            if(mnn+val.ss <= dis[val.ff.ff][val.ff.ss][8]){
                dis[val.ff.ff][val.ff.ss][8] = mnn+val.ss ;
                pq.push({dis[val.ff.ff][val.ff.ss][8], {val.ff, 9}}) ;
            }
        }

    }

    ll mn = dis[d.ff][d.ss][0] ;
    for(int i = 0; i < 9; i++) 
        mn = min(mn, dis[d.ff][d.ss][i]) ;

    if(mn == 1e18) printf("-1\n") ;
    else printf("%lld\n", mn) ;


    return 0 ;
}


int main(){
    // file_io("input.in", "output.out") ;
    // FastRead ;
    E_File ;
    int t = 1,cs = 0 ;
    //scanf("%d", &t) ;
    scanf("%d", &t) ;

    while(t--){
        printf("Case %d: ", ++cs) ;
        solve() ;
    }

    return 0;
}