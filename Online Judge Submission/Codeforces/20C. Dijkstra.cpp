#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &value: cont)
#define     show(val)           cout<< #val << " -> " << val << endl
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs << ": "
#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;
#define lim 100005
#define inf INT_MAX

vector<pii> adj[lim] ;
int dis[lim],p[lim] ;
int n,m ;
bool vis[lim] ;

void dijkstra(int src){
    priority_queue<pii ,vector<pii>,greater<pii> > pq ;
    for(int i=0; i<lim; i++) dis[i] = inf ;
    pq.push(mk(0,src)) ;
    dis[src] = 0 ;

    while(!pq.empty()){
        pii temp = pq.top() ;
        pq.pop() ;
        int u = temp.ss ;
        if(u == n) return ;
        vis[u] = true ;
        for(pii node: adj[u]){
            int v = node.ss ;
            int w = node.ff ;
            if(!vis[v] && dis[u]+w < dis[v]){
                p[v] = u ;
                dis[v] = dis[u]+w ;
                pq.push(mk(dis[v],v)) ;
            }
        }
    }
}

void path(int x){
    if(p[x] == -1)
        cout<< 1 << " " ;
    else{
        path(p[x]) ;
        cout<< x << " " ;
    }
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif


    cin>> n >> m ;
    for(int i=0; i<m; i++){
        int a,b,w ;
        cin>>a >> b >> w ;
        adj[a].pb(mk(w,b)) ;
        adj[b].pb(mk(w,a)) ;
    }
    memset(p,0,sizeof(p)) ;
    memset(vis,0, sizeof(vis)) ;
    p[1] = -1 ;
    dijkstra(1) ;

    if(dis[n] == inf) cout<< "-1" <<endl ;
    else{
        path(n) ;
        cout<< endl ;
    }

    return 0;
}

