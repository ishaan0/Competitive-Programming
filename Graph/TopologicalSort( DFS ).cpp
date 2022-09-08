#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define lim 10000

/// Complexity O(V+E)
/// Here we are using time method
/// If a node comes first it will have maximum finishing time
/// So we just need to store the node according
/// to their finishing time ...

/// Topological sort is possible when graph is DAG
/// DAG: Directed Acyclic Graph

vector<int> adj[lim] ;
vector<int> visited(lim) ;
stack<int> ordered ;
int v,e ;


bool DFS(int src){
    if(visited[src] == 1) return true ;
    else if(visited[src] == 2) return false ;

    visited[src] = 1 ;
    bool ans = false ;
    for(int node: adj[src])
        ans |= DFS(node) ;
    visited[src] = 2 ;
    ordered.push(src) ;
    return ans ;
}


int main(){

    cin>>v >>e ;
    for(int i=0; i<e; i++){
        int x,y ;
        cin>> x >>y ;
        adj[x].pb(y) ;
    }

    for(int i=0; i<v; i++){
        if(visited[i]==0 && DFS(i)){
            cout<< "Cycle detected" << endl ;
            return 0 ;
        }
    }

    while(!ordered.empty()){
        cout<< ordered.top() << " " ;
        ordered.pop() ;
    }
    cout<< endl ;

    return 0 ;
}

