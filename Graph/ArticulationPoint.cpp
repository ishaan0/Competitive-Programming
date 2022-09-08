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


namespace ap{
    const int max_n = 1e5 ;

    vector<int> adj[max_n] ;
    bool vis[max_n], cut[max_n] ;
    int discover[max_n], low[max_n] ;
    int disc_t, root = 1 ;

    void dfs(int u,int p){
        vis[u] = 1 ;
        discover[u] = low[u] = ++disc_t ;
        int child = 0 ;

        for(int v: adj[u]){
            if(v == p) continue ;
            if(!vis[v]){
                child++ ;
                dfs(v, u) ;

                low[u] = min(low[u], low[v]) ;
                if(p != root && low[v] >= discover[u])
                    cut[u] = 1 ;
            }
            else low[u] = min(low[u], discover[v]) ;
        }
        if(p == root && child > 1) cut[u] = 1 ;
    }

    void reset(){
        for(int i=0; i<max_n; i++){
            adj[i].clear() ;
            discover[i] = low[i] =  0 ;
            vis[i] = cut[i] = 0 ; 
        }
        disc_t = 0 ;
    }
}


int main(){
    int n,m ;
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u,v ;
        cin>> u >> v ;
        ap::adj[u].push_back( v ) ;
        ap::adj[v].push_back( u ) ;
    }

    for(int i=1; i<=n; i++)
        if(!ap::vis[i]){
            root = i ;
            ap::dfs(root,-1) ;
        }

    cout<< "Articulation points are : " ;
    for(int i=1; i<=n; i++) if(ap::cut[i])
        cout<< i << " " ;
    cout<< "\n" ;


    
    return 0 ;
}