#include<bits/stdc++.h>
using namespace std ;
#define lim 10000
#define pb push_back

vector<int> adj[lim] ;
vector<bool> visited(lim) ;

/// complexity ( V + E )

/// dfs Recursive
void dfsRecursive(int src){
    if(visited[src]) return ;
    visited[src] = true ;

    for(auto &node: adj[src])
        dfs(node) ;
}


int main(){
    int node, component=0 ;

    /// Traverse through all node
    /// If any node found not visited
    /// That will be a component
    for(int i=1; i<=node; i++){
        if(!visited[i]){
            dfs(i) ;
            component++ ;
        }
    }

    cout<< "Total component : " << component << endl ;

    return 0 ;
}

