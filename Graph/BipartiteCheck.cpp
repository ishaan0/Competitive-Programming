#include<bits/stdc++.h>
using namespace std ;
#define lim 10000
#define pb push_back
#define white -1
#define red 0
#define blue 1

vector<int> adj[lim] ;
vector<int> color(lim) ;

/// White : Node is not visited yet
/// Red   : Node is visited and Red colored
/// Blue  : Node is visited and Blue colored

bool BFS(int src){
    queue<int> q ;
    q.push(src) ;
    color[src] = Red ;

    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;
        for(int v: adj[u]){
            if(color[v] == white){
                if(color[u] == red)
                    color[v] = blue ;
                else color[v] = red ;
            }
            else if(color[u] == color[v])
                return false ;
        }
    }
    return true ;
}

void addEdge(int u, int v){
    adj[u].pb(v) ;
    adj[v].pb(u) ;
}

int main(){
    addEdge(1,2) ;
    addEdge(1,3) ;
    addEdge(2,4) ;
    addEdge(4,3) ;

    if(BFS(1)) cout<< "Graph is Bipartite" << endl ;
    else cout<< "NOT" << endl ;

    return 0 ;
}

