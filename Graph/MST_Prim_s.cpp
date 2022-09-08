#include<bits/stdc++.h>
using namespace std ;

/*
    Prim's algorithm is used when there are more edges .
    Time : ( V + E ) * logV
*/

const int lim = 1e5 + 5 ;

int n , m ;
vector<pair<int,int> > adj[lim] ;
int mat[lim][lim] ;     // adjacency matrix for dense graph
int cost[lim] ;
bool vis[lim] ;

/// Used for more dense graph
/// Time : n^2
int prim_dense(){
    memset(vis, 0, sizeof vis) ;
    fill(cost, cost+lim, 1e9) ;

    int sum = 0 ;
    cost[1] = 0 ;   // let it be starting node

    for(int i=0; i<n; i++){
        int u = -1 ;
        for(int j=1; j<=n; j++)
            if(!vis[j] && (u==-1 || cost[j] < cost[u]))
                u = j ;

        if(cost[u] == 1e9) return -1 ;
        vis[u] = 1 ;
        sum += cost[u] ;

        for(int v=1; v<=n; v++)
            cost[v] = min(cost[v], mat[u][v]) ;
        
    }
    return sum ;
}


/// used for sparse graph
/// Time : ( V + E ) * logV
int prim_sparse(){
    using pii = pair<int,int> ;
    priority_queue< pii, vector<pii>, greater<pii> > pq ;
    memset(vis, 0, sizeof vis) ;
    fill(cost, cost+lim, 1e9) ;

    int sum = 0 ;
    pq.push({0, 1}) ;
    cost[1] = 0 ;

    while(!pq.empty()){
        int u = pq.top().second, d = pq.top().first ;
        pq.pop() ;
        if(vis[ u ]) continue ;
        vis[ u ] = 1 ;
        sum += d ;

        for(pii nd: adj[u]){
            int v = nd.first , w = nd.second ;
            if(vis[ v ]) continue ;
            cost[v] = min(cost[v], w) ;
            pq.push({cost[v], v}) ;
        }
    }
    return sum ;
}

int main(){
    cin>> n >> m ;
    for(int i=0; i<m; i++){
        int u, v, w ;
        cin>> u >> v >> w ;
        adj[u].push_back({v, w}) ;
        adj[v].pb({u, w}) ;
    }

    cout<< prim_dense() << "\n" ;
    cout<< prim_sparse() << "\n" ;
    
    return 0 ;
}