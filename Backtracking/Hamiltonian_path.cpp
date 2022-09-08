#include<bits/stdc++.h>
using namespace std ;

int node,edge ;
vector<int> adj[1000]
bool vis[1000] ;

bool isPath(int u,int cnt){
    if(cnt == node) return true ;

    for(int &v: adj[u]){
        if(!vis[v]){
            vis[v] = true ;
            if(isPath(v,cnt+1))
                return true ;
            vis[v] = false ;
        }
    }
    return false ;
}


int main(){

    cin>> node >> edge ;
    for(int i=0; i<node; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    bool flag = false ;
    memset(vis,0,sizeof vis) ;
    for(int i=1; i<=node; i++){
        vis[i] = true ;
        if(isPath(i,1)){
            flag = true ;
            break ;
        }
        vis[i] = false ;
    }

    if(flag) cout<< "Hamiltonian path possible" << endl ;
    else cout<< "Not possible" << endl ;

    return 0 ;
}
