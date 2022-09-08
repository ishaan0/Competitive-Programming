#include<bits/stdc++.h>
using namespace std ;

/*
    This will form a bridge tree. A bridge tree is a tree where each node is
    subgraph some node which do not have any bridge. And bridge tree's edge are
    normal graph's bridges. 
*/


const int lim = 2e4 + 5 ;

vector<pair<int,int> > adj[lim] ;

namespace BridgeTree{
    int timeIn[lim], low[lim], disc_t, vComp ;
    bool vis[lim], isBridge[lim] ;
    vector<int> bridgeTree[lim], component[lim] ;
    queue<int> q[lim] ;

    void init(int n){
        for(int i = 0; i < lim; i++){
            adj[i].clear() ;
            bridgeTree[i].clear() ;
            component[i].clear() ;
            vis[i] = isBridge[i] = 0 ;
            while(!q[i].empty()) q[i].pop() ;
        }
        disc_t = 0 ;
        vComp = 1 ;
    }

    void dfs1(int u,int p = -1){ /// It will find all the bridges ( Tarjan's algorithm )
        vis[u] = 1 ;
        timeIn[u] = low[u] = ++disc_t ;

        for(pair<int,int> nd: adj[u]){
            int v = nd.first, eId = nd.second ;
            if(v == p) continue ;
            if(!vis[v]){
                dfs1(v, u) ;
                low[u] = min(low[u], low[v]) ;
                if(low[v] > timeIn[u]) isBridge[eId] = 1 ;
            }
            else low[u] = min(low[u], timeIn[v]) ;
        }
    }

    void dfs2(int src){ // here we used dfs + bfs both. bfs for same component, dfs for another component 
        int uComp = vComp ;
        q[uComp].push(src) ;
        vis[src] = 1 ;

        while(!q[uComp].empty()){
            int u = q[uComp].front() ;
            q[uComp].pop() ;
            component[uComp].push_back(u) ;

            for(pair<int,int> nd: adj[u]){
                int v = nd.first, eId = nd.second ;
                if(vis[v]) continue ;

                if(isBridge[eId]){
                    vComp++ ;
                    bridgeTree[uComp].push_back(vComp) ;
                    bridgeTree[vComp].push_back(uComp) ;
                    dfs2(v) ;
                }
                else{
                    vis[v] = 1 ;
                    q[uComp].push(v) ;
                }
            }

        }
    }
}

using namespace BridgeTree ;


int main(){
    int n, m ;
    cin>> n >> m ;

    init(n) ;

    for(int i = 0; i < m; i++){
        int u, v ;
        cin>> u >> v ;
        u++, v++ ;
        adj[u].push_back({v, i}) ;
        adj[v].push_back({u, i}) ;
    }

    dfs1(1, -1) ;
    for(int i = 0; i <= n; i++) vis[i] = 0 ;
    dfs2(1) ;
    
    int cnt = 0 ;
    for(int i = 0; i <= n; i++) if(bridgeTree[i].size() == 1) cnt++ ;

    cout<< (cnt+1)/2 << "\n" ;

    return 0 ;
}