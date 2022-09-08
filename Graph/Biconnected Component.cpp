#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ; 

int timer, root, timeIn[lim], low[lim] ;
vector<int> adj[lim] ;
vector< vector<int> > components ;
stack<int> stk ;
bool vis[lim] ;

/*
    Biconnected component - BCC
    Each component is largest connected graph which doesn't contain any articulation
    point.
*/


void dfs(int u,int par){
    vis[u] = 1 ;
    timeIn[u] = low[u] = ++timer ;
    if(adj[u].size() == 0){
        components.push_back( vector<int>(1, u) ) ;
        return ;
    }
    stk.push(u) ;

    for(int v: adj[u]){
        if(v == par) continue ;
        if(!vis[v]){
            dfs(v, u) ;
            low[u] = min(low[u], low[v]) ;
            if(u == root || low[v] >= timeIn[u]){
                components.push_back( vector<int>(1, u) ) ;
                while(true){
                    int x = stk.top() ;
                    stk.pop() ;
                    components.back().push_back( x ) ;
                    if(x == v) break ;
                }
            }
            else low[u] = min(low[u], timeIn[v]) ;
        }
    }
}

int main(){
    int n, m ;
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u, v ;
        cin>> u >> v ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }

    root = 1 ;
    dfs(root, -1) ;

    for(int i=0; i<components.size(); i++){
        cout<< "compoment " << i << " : " ;
        for(int j=0; j<components[i].size(); j++)
            cout<< components[i][j] << " " ;
        cout<< "\n" ;
    }
    
    return 0 ;
}