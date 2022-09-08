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


struct aho_corasick{
    const int max_c = 10 ;
    int N, P ;
    vector< vector<int> > next, out ;
    vector<int> link, out_link ; 

    aho_corasick() : N(0), P(0){ node(); }

    int node(){
        next.emplace_back(max_c, 0) ;
        link.emplace_back(0) ;
        out_link.emplace_back(0) ;
        out.emplace_back(0) ;
        return N++ ;
    }

    inline int get(char c){ return c-'0'; }

    int add_pattern(string pat){
        int u = 0 ;
        for(char c: pat){
            if(!next[u][ get(c) ]) next[u][ get(c) ] = node() ;
            u = next[u][ get(c) ] ;
        }
        out[u].push_back(P) ;
    
        return P++ ;
    }

    void compute(){
        queue<int> q ;
        q.push(0) ;

        while(!q.empty()){
            int u = q.front(); q.pop() ;
            for(int c = 0; c < max_c; c++){
                int v = next[u][c] ;
                if(!v) next[u][c] = next[ link[u] ][c] ;
                else{
                    link[v] = u ? next[ link[u] ][c] : 0 ;
                    out_link[v] = out[ link[v] ].empty() ? out_link[ link[v] ] : link[v] ;
                    q.push(v) ;
                }
            }
        }
    }

    int go(int u,char c){
        while(u && !next[u][ get(c) ]) u = link[u] ;
        return next[u][ get(c) ] ;
    }

    vector<int> search_pattern(string text){
        int u = 0 ;
        vector<int> occurance ;
        vector<bool> freq(N+5, 1) ;
        for(char c: text){
            u = go(u, c) ;
            for(int v = u; v; v = out_link[v]){
                if(freq[v]){
                    for(int id: out[v]) occurance.push_back(id) ;
                    freq[v] = 0 ;
                }
            }
        }
        return occurance ;
    }

} ;


ll l, r, k, n ;
char str[20] ;
vector<int> digit ;
ll dp[20][2][1200][2] ;

aho_corasick aho ;

ll func(int pos,int flag,int state,int isSmall){
    // dbg(pos, flag, state, isSmall)
    if(pos == SZ(digit)) return flag ;
    ll &ans = dp[pos][flag][state][isSmall] ;
    // if(pos==1 && flag==0 && state==0 && isSmall==0){
    //     dbg(ans)
    // }
    // if(isSmall && ans != -1) return ans ;
    if(ans != -1) return ans ;
    ans = 0 ;
    int lim = isSmall ? 9 : digit[pos] ;

    for(int i = 0; i <= lim; i++){
        // dbg(pos, i)
        int n_flag = flag ;
        int nd = aho.go(state, (char)(i+'0')) ;
        if(aho.out[ nd ].size() > 0) n_flag = 1 ;
        if(aho.out[ aho.out_link[nd] ].size() > 0) n_flag = 1 ;
        ans += func(pos+1, n_flag, nd, isSmall||(i<lim)) ;
        // dbg(pos, i, ans)
    }
    // if(isSmall) return dp[pos][flag][state] = ans ;
    return ans ;
}


ll getAns(ll n){
    digit.clear() ;
    while(n > 0){
        digit.push_back(n % 10) ;
        n /= 10 ;
    }
    reverse(all(digit)) ;
    memset(dp, -1, sizeof dp) ;
    return func(0, 0, 0, 0) ;
}

int solve(){
    scanf("%lld %lld %lld %lld", &l, &r, &k, &n) ;

    for(int i = 0; i < n; i++){
        scanf("%s", str) ;
        aho.add_pattern(str) ;
    }

    ll x = getAns(l-1) ;
    // dbg(getAns(r))
    if(getAns(r)-x < k) printf("no such number\n") ;
    else{
        ll lo = l, hi = r ;
        while(lo < hi){
            ll mid = lo + (hi - lo)/2LL ;
            if(getAns(mid)-x >= k) hi = mid ;
            else lo = mid + 1 ;
        }

        printf("%lld\n", hi) ;
    }

    return 0 ;
}


int main(){
    // FastRead ;
    E_File ;
    int t = 1,cs = 0 ;
    //scanf("%d", &t) ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}