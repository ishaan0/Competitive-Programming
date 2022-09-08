#include<bits/stdc++.h>
using namespace std ;

/*
    complexity: (v + e) * logv 
    varified : https://cses.fi/problemset/task/1675/
*/

const int lim = 1e5 + 5 ;

int n, m ;
long long cost[lim] ;
bool vis[lim] ;

vector<pair<int,int> > adj[lim] ;

long long prims(int src){
    using pll = pair<long long,long long> ;
    priority_queue< pll, vector<pll>, greater<pll> > pq ;
    memset(vis, 0, sizeof vis) ;
    fill(cost, cost+lim, 1e18) ;

    long long sum = 0, nodes = 0 ;
    pq.push({0, src}) ;
    cost[src] = 0 ;

    while(!pq.empty()){
        long long u = pq.top().second, d = pq.top().first ;
        pq.pop() ;
        if(vis[ u ]) continue ;

        nodes++ ;
        vis[ u ] = 1 ;
        sum += d ;

        for(pair<int,int> nd: adj[u]){
            long long v = nd.first , w = nd.second ;
            if(vis[ v ]) continue ;
            cost[v] = min(cost[v], w) ;
            pq.push({cost[v], v}) ;
        }
    }
    if(nodes != n) return -1 ;
    return sum ;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) ;

    cin>> n >> m ;

    for(int i = 0; i < m; i++){
        int u, v, w ;
        cin>> u >> v >> w ;
        adj[u].push_back({v, w}) ;
        adj[v].push_back({u, w}) ;
    }

    long long ans = prims(1) ;

    if(ans == -1) cout<< "IMPOSSIBLE\n" ;
    else cout<< ans << "\n" ;
    
    return 0 ;
}