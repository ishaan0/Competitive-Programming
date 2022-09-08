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
#define     memz(cont)          memset(cont, 0, sizeof cont)
#define     memn(cont)          memset(cont, -1, sizeof cont)
#define     pcnt                __builtin_popcount
#define     pcntll              __builtin_popcountll
#define     sz(cont)            (int)(cont).size()
#define     sq(x)               ((x) * (x))
#define     Case                printf("Case %d: ",++cs)
#define     PI                  3.1415926535897932384
#define     pf                  printf
#define     sf                  scanf
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

TP inline F amin(F &a,S b){ if(b<a) a=b ; return a ; }
TP inline F amax(F &a,S b){ if(b>a) a=b ; return a ; }

const double eps = 1e-9 ;
const ll mod = 1e9+7 ;

/** Functions Start **//*
TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }
TP inline F resetBit(F mask, S pos) { return mask &= (~((F)1 << pos)) ; }
TP inline F toggleBit(F mask, S pos){ return mask ^= ((F)1 << pos) ; }

TS T egcd(T a,T b,T &x,T &y){if(b==0){x=1;y=0;return a;}T x1,y1;T gcd=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return gcd;}
TP F bigMod(F a,S b){a%=mod;F res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}

TP inline F modAdd(F a,S b){ return ( (a%mod)+(b%mod) ) %mod ; }
TP inline F modSub(F a,S b){ return ( (a%mod)-(b%mod)+mod ) %mod ; }
TP inline F modMul(F a,S b){ return ( (a%mod)*(b%mod) ) %mod ; }
TS inline T modInv(T a){ return bigMod(a,mod-2) ; }*/
/** Functions End **/

/** Direction Array **//*
const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;*/
/** Direction Array ends **/


const int lim = 1e5+5 ;

int table[20][lim][6], arr[lim][6] ;
int ans[6] ;
int n, m, k ;

void build(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            table[0][i][j] = arr[i][j] ;
    for(int i=1; (1<<i)<=n; i++){
        for(int j=0; (j+(1<<i)-1)<n; j++){
            for(int kk=0; kk<m; kk++){
                int x = table[i-1][j][kk] ;
                int y = table[i-1][j+(1<<(i-1))][kk] ;
                table[i][j][kk] = max(x, y) ;
            }
        }
    }
}

ll query(int l,int r){
    int i = log2(r-l+1) ;
    ll val = 0 ;
    for(int j=0; j<m; j++){
        int x = table[i][l][j] ;
        int y = table[i][r-(1<<i)+1][j] ;
        val += (ll)max(x,y) ;
    }
    return val ;
}

void update(int l,int r){
    int i = log2(r-l+1) ;
    for(int j=0; j<m; j++){
        int x = table[i][l][j] ;
        int y = table[i][r-(1<<i)+1][j] ;
        ans[j] = max(x,y) ;
    }
    
}


int solve(){
    sf("%d %d %d", &n, &m, &k) ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            sf("%d", &arr[i][j]) ;
    }

    build() ;

    int len = 0 ;
    for(int i=0; i<n; i++){
        int lo = 0, hi = i ;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            ll val = query(mid,i) ;
            if(val <= k){
                hi = mid - 1 ;
                if(i-mid+1 > len){
                    len = i - mid + 1 ;
                    update(mid,i) ;
                }
            }
            else lo = mid + 1 ;
        }
    }

    for(int i=0; i<m; i++){
        if(i) pf(" ") ;
        pf("%d", ans[i]) ;
    }
    pf("\n") ;

    return 0 ;
}


int main()
{
    //Boost ;
    int t = 1,cs = 0 ;
    //sf("%d",&t) ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}