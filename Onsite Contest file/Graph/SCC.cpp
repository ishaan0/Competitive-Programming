#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e6 + 5 ;

vector<int> adj[lim] ;

namespace scc{
    vector<int> rev[lim], sup[lim] ;
    vector<int> comp(lim), order ;
    bool vis[lim] ;

    void init(int n){
        for(int i = 0; i <= n; i++){
            adj[i].clear() ;
            rev[i].clear() ;
            sup[i].clear() ;
            vis[i] = 0 ;
            comp[i] = -1 ;
        }
        order.clear() ;
    }

    void dfs_1(int u){
        vis[u] = 1 ;
        for(int v: adj[u]){
            if(vis[v]) continue ;
            dfs_1(v) ;
        }
        order.push_back( u ) ;
    }

    void dfs_2(int u,int cnt){
        vis[u] = 1 ;
        comp[u] = cnt ;
        
        for(int v: rev[u]){
            if(vis[v]) continue ;
            dfs_2(v, cnt) ;
        }
    }

    void kosaraju(int n){
        for(int i=1; i<=n; i++) 
            if(!vis[i]) dfs_1(i) ;

        fill(vis, vis+n+1, 0) ;
        reverse(order.begin(), order.end()) ;

        int cnt = 0 ;
        for(int u: order){
            if(vis[u]) continue ;
            dfs_2(u, ++cnt) ;
        }
    }

    void build_super(int n){
        for(int u=1; u<=n; u++){
            for(int v: adj[u]){
                if(comp[u] != comp[v] && comp[u] != -1 && comp[v] != -1)
                    sup[ comp[u] ].push_back( comp[v] ) ;
            }
        }
    }
}

using namespace scc ;

int main(){
    int n, m ;
    cin>> n >> m ;
    init(n) ;

    for(int i = 0; i < m; i++){
        int u, v ;
        cin>> u >> v ;
        adj[u].push_back(v) ;
        rev[v].push_back(u) ;
    }

    kosaraju(n) ;
    build_super(n) ;

    
    
    return 0 ;
}