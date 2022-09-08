
/// query time : q * logn^2
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


namespace sa{
const int lim = 1e5 + 3 ; 
    int n ;
    string str ;
    vector<int> SA, _rank, lcp ;
    int table[20][lim] ;
    vector<int> segtree[4*lim] ;

    void count_sort(){
        vector<int> cnt(n) ;
        for(int i: _rank)
            cnt[i]++ ;

        vector<int> SA_new(n), left_idx(n) ;
        left_idx[0] = 0 ;

        for(int i=1; i<n; i++)
            left_idx[i] = left_idx[i-1] + cnt[i-1] ;

        for(int i: SA){
            int id = _rank[i] ;
            SA_new[ left_idx[id] ] = i ;
            left_idx[id]++ ;  
        }
        SA = SA_new ;
    }

    void build_suffix_array(){
        vector<pair<char, int> > arr(n) ;
        for(int i=0; i<n; i++)
            arr[i] = {str[i], i} ;
        sort(arr.begin(), arr.end()) ;

        for(int i=0; i<n; i++) SA[i] = arr[i].second ;
        _rank[ SA[0] ] = 0 ;

        for(int i=1; i<n; i++){
            _rank[ SA[i] ] = _rank[ SA[i-1] ] ;
            if(arr[i].first != arr[i-1].first)
                _rank[ SA[i] ]++ ;
        }

        for(int k=0; (1<<k) < n; k++){
            for(int i=0; i<n; i++)
                SA[i] = ( SA[i] - (1<<k) + n ) % n ;
            count_sort() ;

            vector<int> _rank_new(n) ;
            _rank_new[ SA[0] ] = 0 ;

            for(int i=1; i<n; i++){
                pair<int,int> prev = { _rank[ SA[i-1] ], _rank[ (SA[i-1] + (1<<k))%n ] } ;
                pair<int,int> cur = { _rank[ SA[i] ], _rank[ (SA[i] + (1<<k))%n ] } ;

                _rank_new[ SA[i] ] = _rank_new[ SA[i-1] ] ;
                if(cur != prev) _rank_new[ SA[i] ]++ ;
            }
            _rank = _rank_new ;
        }
    }

    void build_lcp(){
        int k = 0 ;
        for(int i=0; i<n-1; i++){
            int pi = _rank[i] ;
            int j = SA[ pi-1 ] ; 
            while(i+k<n && j+k<n && str[ i+k ] == str[ j+k ]) k++ ;
            lcp[ pi ] = k ;
            k = max(0, k-1) ;
        }
    }

    void build_sparse(){
        for(int i=0; i<n; i++)
            table[0][i] = lcp[i] ;

        for(int i=1; (1<<i)<=n; i++){
            for(int j=0; j+(1<<i)<=n; j++){
                int x = table[i-1][j] ;
                int y = table[i-1][j+(1 << (i-1))] ;
                table[i][j] = min(x, y) ;
            }
        }
    }

    void build_segtree(int iter,int lo,int hi){
        if(lo == hi){
            segtree[iter].push_back( SA[lo] ) ;
            return ;
        }
        int mid = lo + (hi - lo)/2 ;
        build_segtree(2*iter+1, lo, mid) ;
        build_segtree(2*iter+2, mid+1, hi) ;
        merge(all(segtree[2*iter+1]), all(segtree[2*iter+2]), back_inserter(segtree[iter])) ;
    }

    void init(){
        str.push_back( '$' ) ;
        n = SZ(str) ;
        CLR(table) ;
        SA.clear() ;
        _rank.clear() ;
        lcp.clear() ;
        SA.resize(n) ;
        _rank.resize(n) ;
        lcp.resize(n) ;
        build_suffix_array() ;
        build_lcp() ;
        build_sparse() ;
        for(int i=0; i<4*lim; i++) segtree[i].clear() ; 
        build_segtree(0, 0, n-1) ;
    }

    
    int query_segtree(int iter,int lo,int hi,int qi,int qj,int val){
        if(qj < lo || qi > hi) return 0 ;
        if(qi <= lo && hi <= qj){
            int ans = upper_bound(all(segtree[iter]), val) - segtree[iter].begin() ;
            return ans ;
        }
        int mid = lo + (hi - lo)/2 ;
        int lft = query_segtree(2*iter+1, lo, mid, qi, qj, val) ;
        int rgt = query_segtree(2*iter+2, mid+1, hi, qi, qj, val) ;
        return (lft + rgt) ;
    }

    int query_sparse(int lo,int hi){
        if(hi < lo) swap(lo, hi) ;
        int i = log2(hi-lo+1) ;
        int x = table[i][lo] ;
        int y = table[i][hi-(1<<i)+1] ;     
        return min(x, y) ;
    }

    int b_srch_1(int lo,int hi,int id,int len){
        int ans = -1 ;
        if(lo > hi) return ans ;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2 ;
            if(query_sparse(mid, id) >= len){
                ans = mid ;
                hi = mid - 1 ;
            }
            else lo = mid + 1 ;
        }
        return ans ;
    }
    int b_srch_2(int lo,int hi,int id,int len){
        int ans = -1 ;
        if(lo > hi) return ans ;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2 ;
            if(query_sparse(id, mid) >= len){
                ans = mid ;
                lo = mid + 1 ;
            }
            else hi = mid - 1 ;
        }
        return ans ;
    }

    int get_ans(int a,int b,int c,int d){
        if(d-c+1 > b-a+1) return 0 ;

        int lft = b_srch_1(0, _rank[c], _rank[c], d-c+1) ;
        int rgt = b_srch_2(_rank[c]+1, n-1, _rank[c]+1, d-c+1) ;
        
        if(lft == -1) lft = _rank[c]+1 ;
        if(rgt == -1) rgt = _rank[c] ;
        lft-- ;

        int x = query_segtree(0, 0, n-1, lft, rgt, b-(d-c+1)+1) ;
        int y = query_segtree(0, 0, n-1, lft, rgt, a-1) ;
        
        return x - y ;
    }

    

}




int main(){
    FastRead ;
    int t = 1,cs = 0 ;
    cin>> t ;

    while(t--){
        cin>> sa::str ;

        sa::init() ;
        
        int q ;
        cin>> q ;

        while(q--){
            int a, b, c, d ;
            cin>> a >> b >> c >> d  ;
            cout<< sa::get_ans(a-1,b-1,c-1,d-1) << "\n" ;
        }
    }

    return 0;
}


/* --------------------------------------------------------------------------------------- */


/// query time : q * logn

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


const int lim = 1e5 + 5 ; 


struct _data{
    int l, r, val, pos ;
    _data(){l=r=val=pos=0;}
    _data(int _l,int _r,int _val,int _pos){
        l = _l, r = _r, val = _val, pos = _pos ;
    }
};

vector<_data> values ;
vector<int> sol[lim] ;

namespace sa{
    int n ;
    string str ;
    vector<int> SA, _rank, lcp ;
    int table[20][lim] ;
    
    void count_sort(){
        vector<int> cnt(n) ;
        
        for(int i=0; i<n; i++)
            cnt[ _rank[i] ]++ ;

        vector<int> SA_new(n), left_idx(n) ;
        left_idx[0] = 0 ;

        for(int i=1; i<n; i++)
            left_idx[i] = left_idx[i-1] + cnt[i-1] ;

        for(int i=0; i<n; i++){
            int id = _rank[SA[i]] ;
            SA_new[ left_idx[id] ] = SA[i] ;
            left_idx[id]++ ;  
        }
        SA = SA_new ;
    }

    void build_suffix_array(){
        vector< pair<char, int> > arr(n) ;
        for(int i=0; i<n; i++)
            arr[i] = {str[i], i} ;
        sort(arr.begin(), arr.end()) ;

        for(int i=0; i<n; i++) SA[i] = arr[i].second ;
        _rank[ SA[0] ] = 0 ;

        for(int i=1; i<n; i++){
            _rank[ SA[i] ] = _rank[ SA[i-1] ] ;
            if(arr[i].first != arr[i-1].first)
                _rank[ SA[i] ]++ ;
        }

        for(int k=0; (1<<k) < n; k++){
            for(int i=0; i<n; i++)
                SA[i] = ( SA[i] - (1<<k) + n ) % n ;
            count_sort() ;


            vector<int> _rank_new(n) ;
            _rank_new[ SA[0] ] = 0 ;

            for(int i=1; i<n; i++){
                pair<int,int> prev = { _rank[ SA[i-1] ], _rank[ (SA[i-1] + (1<<k))%n ] } ;
                pair<int,int> cur = { _rank[ SA[i] ], _rank[ (SA[i] + (1<<k))%n ] } ;

                _rank_new[ SA[i] ] = _rank_new[ SA[i-1] ] ;
                if(cur != prev) _rank_new[ SA[i] ]++ ;
            }
           _rank = _rank_new ;
        }
    }

    void build_lcp(){
        int k = 0 ;
        for(int i=0; i<n-1; i++){
            int pi = _rank[i] ;
            int j = SA[ pi-1 ] ; 
            while(i+k<n && j+k<n && str[ i+k ] == str[ j+k ]) k++ ;
            lcp[ pi ] = k ;
            k = max(0, k-1) ;
        }
    }

    void build_sparse(){
        for(int i=0; i<n; i++)
            table[0][i] = lcp[i] ;

        for(int i=1; (1<<i)<=n; i++){
            for(int j=0; j+(1<<i)<=n; j++){
                int x = table[i-1][j] ;
                int y = table[i-1][j+(1 << (i-1))] ;
                table[i][j] = min(x, y) ;
            }
        }
    }


    void init(){
        str.push_back( '$' ) ;
        n = SZ(str) ;
        SA.clear() ;
        _rank.clear() ;
        lcp.clear() ; 
        SA.resize(n) ;
        _rank.resize(n) ;
        lcp.resize(n) ;
        CLR(table) ;

        build_suffix_array() ;
        build_lcp() ;
        build_sparse() ;
        values.clear() ;

    }


    inline int query_sparse(int lo,int hi){
        if(hi < lo) swap(lo, hi) ;
        int i = log2(hi-lo+1) ;
        int x = table[i][lo] ;
        int y = table[i][hi-(1<<i)+1] ;     
        return min(x, y) ;
    }

    inline int b_srch_1(int lo,int hi,int id,int len){
        int ans = -1 ;
        if(lo > hi) return ans ;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2 ;
            if(query_sparse(mid, id) >= len){
                ans = mid ;
                hi = mid - 1 ;
            }
            else lo = mid + 1 ;
        }
        return ans ;
    }
    inline int b_srch_2(int lo,int hi,int id,int len){
        int ans = -1 ;
        if(lo > hi) return ans ;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2 ;
            if(query_sparse(id, mid) >= len){
                ans = mid ;
                lo = mid + 1 ;
            }
            else hi = mid - 1 ;
        }
        return ans ;
    }

    void get_ans(int a,int b,int c,int d,int id){
        if(d-c+1 > b-a+1){
            sol[id].push_back( 0 ) ;
            sol[id].push_back( 0 ) ;
            return ;
        }

        int lft = b_srch_1(0, _rank[c], _rank[c], d-c+1) ;
        int rgt = b_srch_2(_rank[c]+1, n-1, _rank[c]+1, d-c+1) ;
        
        if(lft == -1) lft = _rank[c]+1 ;
        if(rgt == -1) rgt = _rank[c] ;
        lft-- ;

        values.push_back( _data(lft+1, rgt+1, b-(d-c+1)+2, id) ) ;
        values.push_back( _data(lft+1, rgt+1, a, id) ) ;
        
    }

    void print_suffix(){
        cout<< "Suffixes :\n" ;
        for(int i=0; i<n; i++)
            cout<< SA[i] << " " << str.substr(SA[i], n-SA[i]) << "\n" ;
    }

    void print_lcp(){
        cout<< "LCP :\n" ;
        for(int i=0; i<n; i++)
            cout<< lcp[i] << "\n" ;
    }

}


ll bit[lim] ;

inline void update(int i,ll val){
    while(i <= sa::n){
        bit[i] += val ;
        i += i & (-i) ;
    }
}

inline ll query(int i){
    ll sum = 0 ;
    while(i>=1){
        sum += bit[i] ;
        i -= i & (-i) ;
    }
    return sum ;
}

bool cmp(_data a,_data b){
    if(a.val == b.val) return a.l < b.l ;
    return a.val < b.val ;
}

int main(){
    FastRead ;
    int t = 1,cs = 0 ;
    cin>> t ;

    while(t--){
        cin>> sa::str ;

        sa::init() ;

        int q ;
        cin>> q ;

        for(int i=0; i<=q; i++) sol[i].clear() ;

        for(int i=0; i<q; i++){
            int a, b, c, d ;
            cin>> a >> b >> c >> d  ;
           sa::get_ans(a-1,b-1,c-1,d-1,i) ;
        }

        CLR(bit) ;

        for(int i=0; i<sa::n; i++)
            values.push_back( _data(0, i+1, sa::SA[i]+1, 0) ) ;

        sort(all(values), cmp) ;

        for(int i=0; i<SZ(values); i++){
            if(values[i].l == 0){  // array element
                update(values[i].r, 1) ;
            }
            else{   /// query
                int ans = query(values[i].r) - query(values[i].l - 1) ;
                sol[ values[i].pos ].push_back( ans ) ;
            }
        }

        for(int i=0; i<=q; i++) if(SZ(sol[i]) == 2){
            if(sol[i][0] < sol[i][1]) swap(sol[i][0], sol[i][1]) ;
            cout<< sol[i][0] - sol[i][1] << "\n" ;
        }

    }

    return 0;
}