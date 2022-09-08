#include<bits/stdc++.h>
using namespace std ;

/**
    It is also called cut vertex
    Time          : O(V+E)
    discover[]    : Discovery time of all node .
    low[]         : Discovery time of ancestor
                    which is also descendant .
    bridges       : all edge which are also bridge .
    vis[]         : mark visited node .
*/


namespace ap{
    const int max_n = 1e5 ;

    vector<int> adj[max_n] ;
    vector<pair<int,int> > bridges ;
    bool vis[max_n] ;
    int discover[max_n], low[max_n] ;
    int disc_t ;

    void dfs(int u,int p){
        vis[u] = 1 ;
        discover[u] = low[u] = ++disc_t ;

        for(int v: adj[u]){
            if(v == p) continue ;
            if(!vis[v]){
                dfs(v, u) ;

                low[u] = min(low[u], low[v]) ;
                if(low[v] > discover[u]){
                    int uu = u, vv = v ;
                    if(vv < uu) swap(uu, vv) ;
                    bridges.push_back( make_pair(uu, vv) ) ;
                }
            }
            else low[u] = min(low[u], discover[v]) ;
        }
    }

    void reset(){
        for(int i=0; i<max_n; i++){
            adj[i].clear() ;
            discover[i] = low[i] =  0 ;
            vis[i] = 0 ; 
        }
        disc_t = 0 ;
        bridges.clear() ;
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
        if(!ap::vis[i])
            ap::dfs(i,-1) ;
        

    cout<< "Bridges are : \n" ;
    for(pair<int,int> p: ap::bridges)
        cout<< p.first << " " << p.second << "\n" ;


    
    return 0 ;
}