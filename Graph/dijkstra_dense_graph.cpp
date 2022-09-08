#include<bits/stdc++.h>
using namespace std ;

cosnt int inf = 1e9 ;
const int lim = 1e3 + 5 ; 
vector< pair<int,int> > adj[lim] ;

void dijkstra(int src,int n){
    vector<int> dis(n+1, inf) ;
    vector<bool> vis(n+1, 0) ;
    dis[src] = 0 ;

    for(int i=0; i<n; i++){
        int u = -1 ;
        for(int j=1; j<=n; j++)
            if(!vis[j] && (u == -1 || dis[j] < dis[u]))
                u = j ;
        if(dis[u] == inf) break ;
        vis[u] = 1 ;

        for(pair<int,int> nd: adj[u]){
            int v = nd.first, w = nd.second ;
            dis[v] = min(dis[v], dis[u] + w) ;
        }

    }
}


int main(){
    int n, m ;
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u, v, w ;
        cin>> u >> v >> w ;
        adj[u].push_back( {v, w} ) ;
        adj[v].push_back( {u, w} ) ;
    }

    dijkstra(1, n) ;
    
    return 0 ;
}