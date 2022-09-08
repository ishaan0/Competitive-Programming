#include<bits/stdc++.h>
using namespace std ;
#define lim 10000
#define pb push_back
#define INF 1000000000


/**
    Find shortest path in O(V+E) time
    work on unweighted graph only
    and it calculate shortest path for single source
    multiple destination . 
    complexity ( V + E )
*/

vector<int> adj[lim], dis(lim, -1), par(lim, -1) ;

void BFS(int src){
    queue<int> q ;
    dis[src] = 0 ;

    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;
        for(int v: adj[u]){
            if(dis[v] != -1) continue ;
            dis[v] = dis[u] + 1 ; // storing distance
            par[v] = u ;     // storing parent to get path
            q.push(v) ;
        }
    }

}

void get_path(int dest){
    if(dis[dest] == -1){
        cout<< "No Path present !!!\n" ;
        return ;
    }
    vector<int> path ;
    for(int v = dest; v != -1; v = par[v])
        path.pb(v) ;
    reverse(path.begin(), path.end()) ;
    for(int i=0; i<path.size(); i++) 
        cout<< path[i] << " " ;
    cout<< "\n" ;
}

int main(){

    int n, m ;
    cin>> n >> m ;
    for(int i=0; i<m; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }

    bfs(1) ;
    cout<< "Distance from 1 to 5 is " << dis[5] << "\n" ;
    get_path(5) ;

    return 0 ;
}
