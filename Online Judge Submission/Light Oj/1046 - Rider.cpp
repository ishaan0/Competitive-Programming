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

TP inline F amin(F &a,S b){if(b<a)a=b;return a;}
TP inline F amax(F &a,S b){if(b>a)a=b;return a;}

const double eps = 1e-9 ;
const ll mod = 1e9+7 ;

/** Functions Start **//*
TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }
TP inline F resetBit(F mask, S pos) { return mask &= (~((F)1 << pos)) ; }
TP inline F toggleBit(F mask, S pos){ return mask ^= ((F)1 << pos) ; }

TS T egcd(T a,T b,T &x,T &y){if(b==0){x=1;y=0;return a;}T x1,y1;T gcd=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return gcd;}
TP F bigMod(F a,S b){a%=mod;F res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}

TS inline T modAdd(T a,T b){ return (a+b >= mod) ? (a+b-mod) : (a+b) ; }
TS inline T modSub(T a,T b){ return (a-b < 0) ? (a-b+mod) : (a+b) ; }
TS inline T modMul(T a,T b){ return ((a%mod) * (b%mod)) % mod ; }
TS inline T modInv(T a){ return bigMod(a,mod-2) ; }
/** Functions End **/

/** Direction Array **//*
int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;*/
int const drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
int const dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;
/** Direction Array ends **/


string grid[12] ;
int n, m, dis[12][12], temp[12][12], cnt[12][12] ;
bool vis[12][12] ;

void bfs(int sr,int sc,int d){
    memz(vis) ;
    memz(temp) ;
    queue<pii > q ;
    q.push({sr,sc}) ;
    vis[sr][sc] = 1 ;
    cnt[sr][sc]++ ;
    while(!q.empty()){
        pii tmp = q.front() ;
        q.pop() ;
        int ur = tmp.ff, uc = tmp.ss ;
        for(int i=0; i<8; i++){
            int vr = ur + drK[i] ;
            int vc = uc + dcK[i] ;
            if(vr<0||vc<0||vr>=n||vc>=m) continue ;
            if(vis[vr][vc]) continue ;
            vis[vr][vc] = 1 ;
            temp[vr][vc] = temp[ur][uc] + 1 ;
            dis[vr][vc] += (temp[vr][vc]/d) + ( (temp[vr][vc]%d!=0) ? 1 : 0 ) ;
            cnt[vr][vc]++ ;
            q.push({vr,vc}) ;
        }
    }
}



int solve(){
    memz(dis) ;
    memz(cnt) ;

    cin>> n >> m ;
    
    for(int i=0; i<n; i++) cin>> grid[i] ;

    int tt = 0 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] != '.'){
                bfs(i,j,grid[i][j]-'0') ;
                tt++ ;
            }
        }
    }

    int mn = 1e9 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(cnt[i][j] == tt)
                amin(mn, dis[i][j]); 
        }
    }

    if(mn == 1e9) cout<< "-1\n" ; 
    else cout<< mn << "\n" ;

    return 0 ;
}


int main()
{
    //Boost ;
    int t = 1,cs = 0 ;
    //sf("%d",&t) ;
    cin>> t ;
    while(t--){
        cout<< "Case " << ++cs << ": " ;
        //Case ;
        solve() ;
    }

    return 0;
}