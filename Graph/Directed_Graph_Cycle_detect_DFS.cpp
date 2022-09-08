#include<bits/stdc++.h>
using namespace std ;
#define lim 10000
#define pb push_back

vector<int> adj[lim] ;
vector<int> visited(lim,-1) ;

/// Visited will contain 3 color
/// -1 -> Node is not visited
/// 0  -> Node is visted but present in Stack
/// 1  -> Node is visited and out of stack

/// If we found any Node has color 0 .. there will be a back edge
/// If any Back Edge present there will be a cycle

bool dfs(int src){
    if(visited[src] == 0) return true;
    else if(visited[src] == 1) return false ;

    visited[src] = 0 ;
    bool ans = false ;

    for(auto &node: adj[src])
        ans = dfs(node) ;

    visited[src] = 1 ;
    return ans ;
}

void addEdge(int u, int v){
    adj[u].pb(v) ;
}


int main(){

    addEdge(1,2) ;
    addEdge(1,3) ;
    addEdge(2,3) ;
    addEdge(3,4) ;
    addEdge(4,2) ;
    if(dfs(1)) cout<< "cycle found" <<endl ;
    else cout<< "Not found" << endl ;

    return 0 ;
}

