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

/** Functions Start **/
TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }/*
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
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;*/
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;
/** Direction Array ends **/


int n ;
vector<string> grid(9) ;
vector<pii > pawn ;

int bfs(int sx,int sy,int dx,int dy){
    queue<pii > q ;
    q.push({sx, sy}) ;
    int dis[8][8] ;
    for(int i=0; i<8; i++) for(int j=0; j<8; j++)
        dis[i][j] = 1e9 ;
    dis[sx][sy] = 0 ;

    while(!q.empty()){
        int x = q.front().ff ;
        int y = q.front().ss ;
        q.pop() ;

        for(int i=0; i<8; i++){
            int nx = x + drK[i], ny = y + dcK[i] ;
            if(nx<0||nx>7||ny<0||ny>7|| grid[nx][ny] == 'K' || grid[nx][ny] == 'p')
                continue ;
            if(nx==dx && ny == dy) return dis[x][y] + 1 ;
            if(grid[nx][ny] == 'P') continue ;
            if(dis[nx][ny] > dis[x][y] + 1){
                dis[nx][ny] = dis[x][y] + 1 ;
                q.push({nx, ny}) ;
            }
        }
    }
    return -1 ;
}


int dp[8][8][65][(1<<8)+5] ;

int func(int x,int y,int rem,int mask){
    if(mask == (1<<SZ(pawn)) - 1 ) return 1 ;
    int &ans = dp[x][y][rem][mask] ;
    if(ans != -1) return ans ;

    ans = 0 ;
    for(int i=0; i<SZ(pawn); i++){
        if(getBit(mask, i)) continue ;
        int nx = pawn[i].ff, ny = pawn[i].ss ;
        int dis = bfs(x,y,nx,ny) ;
        if(dis != -1 && dis <= rem){
            grid[nx][ny] = '.' ;
            ans = (ans || func(nx,ny,rem-dis, setBit(mask,i))) ;
            grid[nx][ny] = 'P' ;
        }
    }

    return ans ;
} 

void reset(){
    pawn.clear() ;
    NEG(dp) ;
}


int solve(){
    reset() ;

    cin>> n ;
    for(int i=0; i<8; i++)
        cin>> grid[i] ;

    pii src ;

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(grid[i][j] == 'k'){
                src = mp(i, j) ;
            }
            else if(grid[i][j] == 'P'){
                pawn.pb(mp(i, j)) ;
            }
        }
    }


    if(func(src.ff, src.ss, n, 0)) cout<< "Yes\n" ;
    else cout<< "No\n" ;

    return 0 ;
}


int main(){

    int t = 1,cs = 0 ;
    //scanf("%d", &t) ;
    cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}