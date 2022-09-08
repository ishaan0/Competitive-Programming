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


/*
    Problem link: https://lightoj.com/problem/substring-frequency-ii
*/

struct aho_corasick{
    const int max_c = 26 ;
    int N, P ;
    vector< vector<int> > next, out, GO ;
    vector<int> link, out_link ; 

    aho_corasick() : N(0), P(0){ node(); }

    int node(){
        next.emplace_back(max_c, 0) ;
        GO.emplace_back(max_c, -1) ;
        link.emplace_back(0) ;
        out_link.emplace_back(0) ;
        out.emplace_back(0) ;
        return N++ ;
    }

    inline int get(char c){ return c-'a'; }

    int add_pattern(const string& pat){
        int u = 0 ;
        for(char c: pat){
            if(!next[u][ get(c) ]) next[u][ get(c) ] = node() ;
            u = next[u][ get(c) ] ;
        }
        out[u].push_back(P) ;
    
        return P++ ;
    }
    // total number charecter in dictionary
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
    // amortized O(1)
    int go(int u,char c){
        if(GO[u][ get(c) ] != -1) return GO[u][ get(c) ] ;
        if(u && !next[u][ get(c) ]) GO[u][ get(c) ] = go(link[u], c) ;
        else GO[u][ get(c) ] = next[u][ get(c) ] ;
        return GO[u][ get(c) ] ;
    }
    // O( total match + text size )
    vector<int> search_pattern(const string& text,int n){
        int u = 0 ;
        vector<int> freq(n) ;
        for(char c: text){
            u = go(u, c) ;
            for(int v = u; v; v = out_link[v]){
                for(int id: out[v]) freq[id]++ ;
            }
        }
        return freq ;
    }

} ;


int solve(){
    int n ;
    string str ;
    cin>> n >> str ;

    aho_corasick aho ;

    for(int i = 0; i < n; i++){
        string pat ;
        cin>> pat ;
        aho.add_pattern(pat) ;
    }

    aho.compute() ;
    vector<int> freq = aho.search_pattern(str, n) ;
    
    for(int el: freq) cout<< el << nl ;

    return 0 ;
}


int main(){
    // file_io("input.in", "output.out") ;
    FastRead ;
    E_File ;
    int t = 1,cs = 0 ;
    //scanf("%d", &t) ;
    cin>> t ;
    while(t--){
        cout<< "Case "<< ++cs << ":\n" ;
        solve() ;
    }

    return 0;
}