#include<bits/stdc++.h>
using namespace std ;
#define pb push_back

vector<int> adj[100000] ;
vector<bool> visited(100000) ;
vector<int> parent(100000,-1) ;

void addEdge(int u, int v){
    adj[u].pb(v) ;
    adj[v].pb(u) ;
}

bool BFS(int src){
    queue<int> q ;
    q.push(src) ;
    parent[src] = -1 ;
    visited[src] = true ;

    while(!q.empty()){
        int cur = q.front() ;
        q.pop() ;

        for(int i: adj[cur]){
            if(!visited[i]){
                parent[i] = cur ;
                visited[i] = true ;
                q.push(i) ;
            }
            else if(parent[cur] != i)
                return true ;
        }
    }

    return false ;
}

bool isCycle(int n){
    for(int i=1; i<=n; i++)
        if(!visited[i] && BFS(i))
            return true ;
    return false ;
}

int main(){

    addEdge(1,3) ;
    addEdge(2,3) ;
    addEdge(1,4) ;
    addEdge(3,4) ;
    addEdge(1,5) ;

    if(isCycle(5))
        cout<< "Cycle present" << endl ;
    else cout<< "no cycle" << endl ;

    return 0 ;
}
