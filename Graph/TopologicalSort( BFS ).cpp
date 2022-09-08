#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ; 

vector<int> adj[lim], order ;
int n, m ;

void topological_sort(){
    vector<int> indegree(n+1) ;
    for(int i=1; i<=n; i++){
        for(int v: adj[i]) indegree[v]++ ;
    }
    
    queue<int> q ;
    for(int i=1; i<=n; i++) if(!indegree[i])
        q.push(i) ;

    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;
        order.push_back( u ) ;
        for(int v: adj[u]){
            indegree[v]-- ;
            if(!indegree[v])
                q.push(v) ;
        }
    }

    if(order.size() != n)
        cout<< "Cycle present\n" ;
    else{
        cout<< "ordered nodes : " ;
        for(int val: order) cout<< val << " " ;
        cout<< "\n" ;
    }
}

int main(){
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u, v ;
        cin>> u >> v ;
        adj[u].push_back( v ) ;
    }

    topological_sort() ;

    return 0 ;
}