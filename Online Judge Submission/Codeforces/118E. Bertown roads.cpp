#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs <<": "
#define     inf                 LLONG_MIN
#define     INF                 LLONG_MAX
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

int const lim = 1e5+5 ;

vector<int> adj[lim] ;
vector<pii > edges ;
bool vis[lim], bridge ;
int in[lim], low[lim], timer ;
int vis2[lim] ;

void dfs1(int u,int par){
    vis[u] = true ;
    in[u] = low[u] = ++timer ;

    for(int v: adj[u]){
        if(v == par) continue ;
        if(!vis[v]){
            dfs1(v,u) ;
            low[u] = min(low[u],low[v]) ;
            if(low[v] > in[u]) bridge = true ;
        }
        else low[u] = min(low[u], in[v]) ;
    }
}

void dfs2(int u,int par){
    //dbg(u,par) ;
    vis2[u] = 1 ;
    for(int v: adj[u]){
        if(v == par) continue ;
        if(vis2[v] == 2) continue ;
        edges.pb(mp(u,v)) ;
        if(vis2[v] == 0) dfs2(v,u) ;
    }
    vis2[u] = 2 ;
}

void reset(){
    for(int i=0; i<lim; i++)
        adj[i].clear() ;
    edges.clear() ;
    memset(vis,0,sizeof vis) ;
    memset(in,0,sizeof in) ;
    memset(low,0,sizeof low) ;
    timer = 0 ;
}

void solve(){
    reset() ;
    int n,m ;
    cin>> n >> m ;
    for(int i=0; i<m; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }
    dfs1(1,-1) ;
    if(bridge) cout<< "0" << endl ;
    else{
        memset(vis2,0,sizeof vis2) ;
        dfs2(1,-1) ;
        foreach(edges) cout<< val.ff << " " << val.ss << endl ;
    }
}


int main()
{
    Boost;

    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t = 1,cs = 0 ;
    //cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}

