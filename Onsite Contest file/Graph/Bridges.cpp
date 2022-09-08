#include<bits/stdc++.h>
using namespace std ;

/**
    Time          : O(V+E)
    discover[]    : Discovery time of all node .
    low[]         : Discovery time of ancestor
                    which is also descendant .
    bridges       : all edge which are also bridge .
    vis[]         : mark visited node .
*/

const int lim = 1e5 + 5 ;

vector<int> adj[lim] ;

namespace ap{
    vector<pair<int,int> > bridges ;
    bool vis[lim] ;
    int timeIn[lim], low[lim], disc_t ;

    void init(int n){
        for(int i = 0; i <= n; i++){
            adj[i].clear() ;
            timeIn[i] = low[i] = vis[i] = 0 ;
        }
        bridges.clear() ;
        disc_t = 0 ;
    }

    void dfs(int u,int p){
        vis[u] = 1 ;
        timeIn[u] = low[u] = ++disc_t ;

        for(int v: adj[u]){
            if(v == p) continue ;
            if(!vis[v]){
                dfs(v, u) ;

                low[u] = min(low[u], low[v]) ;
                if(low[v] > timeIn[u]){
                    int uu = u, vv = v ;
                    if(vv < uu) swap(uu, vv) ;
                    bridges.push_back( make_pair(uu, vv) ) ;
                }
            }
            else low[u] = min(low[u], timeIn[v]) ;
        }
    }
}

using namespace ap ;

int main(){
    int n,m ;
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }

    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs(i,-1) ;
        

    cout<< "Bridges are : \n" ;
    for(pair<int,int> p: bridges)
        cout<< p.first << " " << p.second << "\n" ;


    
    return 0 ;
}