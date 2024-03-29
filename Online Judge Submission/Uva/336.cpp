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
#define     left                (2*node)
#define     right               (2*node+1)
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

TS inline T MOD(T a){ return (a%mod + mod) %mod ; }
TP inline F modAdd(F a,S b){ return ( MOD(a) + MOD(b) ) %mod ; }
TP inline F modSub(F a,S b){ return ( MOD(MOD(a)-MOD(b)) ) %mod ; }
TP inline F modMul(F a,S b){ return ( MOD(a) * MOD(b) ) %mod ; }
TS inline T modInv(T a){ return bigMod(a,mod-2) ; }*/
/** Functions End **/

/** Direction Array **//*
const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;*/
/** Direction Array ends **/


const int lim = 35 ;

vector<int> adj[lim] ;
int dis[lim] ;
int n ;

void bfs(int src){
    queue<int> q ;
    q.push(src) ;
    dis[src] = 0 ;
    
    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;

        for(int v: adj[u]){
            if(dis[v] != -1) continue ;
            dis[v]  = dis[u] + 1 ;
            q.push(v) ;
        }
    }

}

int solve(){
    int cs = 0 ;
    while(cin>> n){
        if(n == 0) break ;
        for(int i=0; i<lim; i++) adj[i].clear() ;

        map<int,int> m ;
        int idx = 1 ;
        
        for(int i=0; i<n; i++){
            int u, v ;
            cin>> u >> v ;

            if(!m.count(u)) m[u] = idx++ ;
            if(!m.count(v)) m[v] = idx++ ;
            u = m[u] ;
            v = m[v] ;

            adj[u].pb(v) ;
            adj[v].pb(u) ;
        }
        
        int u, ttl ;
        while(cin>> u >> ttl){
            if(u==0 && ttl==0) break ;
            int pu = u ;
            
            int ans = 0 ;
            if(m.count(u)){
                pu = m[u] ;
                memn(dis) ;
                bfs(pu) ;
                for(auto el: m)
                    if(dis[el.ss]==-1 || dis[el.ss]>ttl) ans++ ;
            }
            cout<< "Case "<<++cs<<": "<<ans<<" nodes not reachable from node "<<u<<" with TTL = "<<ttl<<".\n" ;
        }
    }



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