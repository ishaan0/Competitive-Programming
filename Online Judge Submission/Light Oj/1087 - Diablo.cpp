#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;


#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     mem(c1,c2)          memset(c1, c2, sizeof c1)
#define     sz(cont)            (int)(cont).size()
#define     sq(x)               ((x) * (x))
#define     Case                cout<< "Case "<< ++cs << ": "
#define     PI                  3.1415926535897932384
#define     mp                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;
typedef     pair <ll , ll >             pll ;

/** Debugging Tool **/
TS void show(const T& v) {    cerr << v << ' ' ;}
TM void show(const T1& first,const T2&... rest){show(first);show(rest...);}
TP ostream& operator<<(ostream& os,const pair<F,S>& p){return os<<"("<<p.ff<<", "<<p.ss<<")";}
TS ostream& operator<<(ostream& os,const vector<T>& v){os << "{"; typename vector< T >::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if( it != v.begin() )os<<", ";os<<*it;}return os<<"}";}
TS ostream& operator<<(ostream& os,const set<T>& v){os<<"[";typename set<T>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
TP ostream& operator<<(ostream& os,const map<F,S>& v){os<<"[";typename map<F,S>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<it->ff<<" = "<<it->ss;}return os<<"]";}
/** Ends **/


const double eps = 1e-9 ;
const ll mod = 1e9+7 ;

/** Functions Start **//*
TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }
TP inline F resetBit(F mask, S pos) { return mask &= (~((F)1 << pos)) ; }
TP inline F toggleBit(F mask, S pos){ return mask ^= ((F)1 << pos) ; }

ll egcd(ll a,ll b,ll &x,ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1;ll gcd=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return gcd;}
ll bigMod(ll a,ll b){a%=mod;ll res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}

inline ll MOD(ll a){ return (a%mod + mod) %mod ; }
inline ll modAdd(ll a,ll b){ return MOD( MOD(a) + MOD(b) ) ; }
inline ll modSub(ll a,ll b){ return MOD( MOD(a) - MOD(b) ) ; }
inline ll modMul(ll a,ll b){ return MOD( MOD(a) * MOD(b) ) ; }
inline ll modInv(ll a){ return bigMod(a,mod-2) ; }*/
/** Functions End **/

/** Direction Array **//*
const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;*/
/** Direction Array ends **/

#define     left     2*iter
#define     right    2*iter+1


const ll lim = 1e5 + 5e4 + 100 ; 

int n , q ;
int arr[lim], segtree[4 * lim] ;

inline void mrg(int iter){
    segtree[iter] = segtree[left] + segtree[right] ;
}
int query(int iter,int lo,int hi,int kth){
    if(lo == hi) return lo ;
    int mid = lo + (hi - lo)/2 ;
    if(segtree[left] >= kth)
        return query(left, lo, mid, kth) ;
    else
        return query(right, mid+1, hi, kth-segtree[left]) ;
}


void update(int iter,int lo,int hi,int qi,int val){
    if(qi < lo || qi > hi) return ;
    if(lo == hi){
        segtree[iter] += val ;
        return ;
    }
    int mid = lo + (hi-lo)/2 ;
    update(left, lo, mid, qi, val) ;
    update(right, mid+1, hi, qi, val) ;
    mrg(iter) ;
}

int solve(){
    mem(segtree, 0) ;
    mem(arr, 0) ;

    scanf("%d %d", &n, &q) ;
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]) ;

    int x = n + q ;
    
    for(int i=1; i<=n; i++)
        update(1, 1, x, i, 1) ;

    int cnt = n ;
    while(q--){
        getchar() ;
        char tp ;
        int d ;
        scanf("%c %d", &tp, &d) ;
        
        if(tp == 'c'){
            if(d > cnt){
                printf("none\n") ;
                continue ;
            }
            int idx = query(1, 1, x, d) ;
            printf("%d\n", arr[idx]) ;
            update(1, 1, x, idx, -1) ;
            cnt-- ;
        }
        else{
            arr[++n] = d ;
            update(1, 1, x, n, 1) ;
            cnt++ ;
        }
    }

    return 0 ;
}


int main()
{
    int t = 1,cs = 0 ;
    scanf("%d", &t) ;

    while(t--){
        printf("Case %d:\n", ++cs) ;
        //Case ;
        solve() ;
    }

    return 0;
}