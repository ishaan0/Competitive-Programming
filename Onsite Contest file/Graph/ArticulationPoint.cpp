#include<bits/stdc++.h>
using namespace std ;

/**
    It is also called cut vertex
    Time          : O(V+E)
    discover[]    : Discovery time of all node .
    low[]         : Discovery time of ancestor
                    which is also descendant .
    cut           : all vertex which are cut vertex are true.
    vis[]         : mark visited node .
*/

const int lim = 1e5 + 5 ;
vector<int> adj[lim] ;

namespace ap{
    bool vis[lim], cut[lim] ;
    int timeIn[lim], low[lim] ;
    int disc_t ;

    void init(int n){
        for(int i = 0; i <= n; i++){
            adj[i].clear() ;
            timeIn[i] = low[i] = 0 ;
            vis[i] = cut[i] = 0 ;
        }
        disc_t = 0 ;
    }

    void dfs(int u,int p = -1){
        vis[u] = 1 ;
        timeIn[u] = low[u] = ++disc_t ;
        int child = 0 ;

        for(int v: adj[u]){
            if(v == p) continue ;
            if(!vis[v]){
                child++ ;
                dfs(v, u) ;

                low[u] = min(low[u], low[v]) ;
                if(p != -1 && low[v] >= timeIn[u])
                    cut[u] = 1 ;
            }
            else low[u] = min(low[u], timeIn[v]) ;
        }
        if(p == -1 && child > 1) cut[u] = 1 ;
    }
}

using namespace ap ;

int main(){
    int n,m ;
    cin>> n >> m ;

    init(n) ;

    for(int i=0; i<m; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }

    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs(i,-1) ;

    cout<< "Articulation points are : " ;
    for(int i=1; i<=n; i++) if(cut[i])
        cout<< i << " " ;
    cout<< "\n" ;


    
    return 0 ;
}