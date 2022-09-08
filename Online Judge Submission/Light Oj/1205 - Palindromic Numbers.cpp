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


ll n, m ;
ll dp[2][2][2][20][20] ;
vector<int> digit ;


ll func(int isSmall,int isBig,int st,int i,int j){
    if(i > j) return (st && (isSmall || !isBig)) ;
    ll &ans = dp[isSmall][isBig][st][i][j] ;
    if(ans != -1) return ans ;

    ans = 0 ;
    int last = (isSmall) ? 9 : digit[i] ;

    if(i == j){
        if(isSmall || !isBig)
            return ans = last + 1 ;
        return last ;
    }

    if(st){
        for(int d=0; d<=last; d++)
            ans += func(isSmall | (d<digit[i]), (isBig | (d>digit[j]))&&(d>=digit[j]), 1, i+1, j-1) ;
    }
    else{
        ans += func(1, 0, 0, i+1, j) ;
        for(int d=1; d<=last; d++)
            ans += func(isSmall | (d<digit[i]), (isBig | (d>digit[j]))&&(d>=digit[j]), 1, i+1, j-1) ;
    }
    return ans ;
}


ll get_ans(ll n){
    if(n < 0) return 0 ;
    if(n < 10) return n + 1 ;

    digit.clear() ;
    while(n != 0){
        digit.pb(n%10) ;
        n /= 10 ;
    }
    mem(dp, -1) ;
    reverse(all(digit)) ;
    
    return func(0,0,0,0,sz(digit)-1) ;
}

int solve(){
    scanf("%lld %lld", &n, &m) ;
    if(n > m) swap(n, m) ;
    
    printf("%lld\n", get_ans(m) - get_ans(n-1)) ;

    return 0 ;
}


int main()
{
    int t = 1,cs = 0 ;
    scanf("%d", &t) ;

    while(t--){
        printf("Case %d: ", ++cs) ;
        solve() ;
    }

    return 0;
}