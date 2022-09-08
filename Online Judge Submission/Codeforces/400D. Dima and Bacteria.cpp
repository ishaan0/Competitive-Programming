#include<bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;
*/

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     memz(cont)          memset(cont, 0, sizeof cont)
#define     memn(cont)          memset(cont, -1, sizeof cont)
#define     Case                cout<< "Case "<< ++cs <<": "
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
/*
int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
int const drH[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
int const dcH[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;
*/
const ll lim1 = 1e5+5 ;
const ll lim2 = 5e2+5 ;

ll n , m , k ;
vector<ll> adj[lim1],comp(lim1) ;
vector<bool> vis(lim1) ;
ll mat[lim2][lim2], c[lim2] ;

inline ll getId(ll x){
    ll pos = lower_bound(c+1,c+k+1,x) - c ;
    return pos ;
}

void dfs(ll u,ll grp){
    if(vis[u]) return ;
    vis[u] = 1 ;
    comp[u] = grp ;
    for(ll v: adj[u])
        dfs(v,grp) ;
}

void warshall(){
    for(int x=1; x<=k; x++){
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                mat[i][j] = min(mat[i][j], mat[i][x]+mat[x][j]) ;
            }
        }
    }
}

void solve(){
    cin>> n >> m >> k ;

    for(int i=1; i<=k; i++){
        cin>> c[i] ;
        c[i] += c[i-1] ;
        for(int j=1; j<=k; j++)
            mat[i][j] = 1e9 ;
    }

    for(int i=1; i<=m; i++){
        ll u,v,x ;
        cin>> u >> v >> x ;
        ll uu = getId(u), vv = getId(v) ;
        mat[uu][vv] = min(mat[uu][vv], x) ;
        mat[vv][uu] = min(mat[vv][uu], x) ;
        if(x == 0){
            adj[u].pb(v) ;
            adj[v].pb(u) ;
        }
    }

    ll grp = 0 ;
    for(int i=1; i<=n; i++){
        if(!vis[i])
            dfs(i,grp++) ;
    }

    bool flag = true ;
    for(int i=1; flag && i<=k; i++){
        mat[i][i] = 0 ;
        ll val = -1 ;
        for(int j = c[i-1]+1; flag && j<=c[i]; j++){
            if(val == -1) val = comp[j] ;
            else if(val != comp[j]){
                flag = false ;
                break ;
            }
        }
    }

    if(flag){
        cout<< "Yes\n" ;
        warshall() ;
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                if(mat[i][j] >= 1e9) cout<< "-1 " ;
                else cout<< mat[i][j] << " " ;
            }
            cout<< "\n" ;
        }
    }
    else cout<< "No\n" ;

}


int main()
{
    Boost;

    int t = 1,cs = 0 ;
    //cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}

