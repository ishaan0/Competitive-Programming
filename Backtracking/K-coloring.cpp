#include<bits/stdc++.h>
using namespace std ;

int node,edge,k ;
vector<int> adj[1000] ;
int color[1000] ;

bool isUsable(int u,int c){
    for(int v: adj[u])
        if(color[v] == c) return false ;
    return true ;
}

bool coloring(int u){
    if(u>node) return true ;

    for(int i=1; i<=k; i++){
        if(isUsable(u,i)){
            color[u] = i ;
            if(coloring(u+1))
                return true ;
            color[i] = 0 ;
        }
    }
    return false ;
}

int main(){

    cin>> node >> edge >> k ;
    for(int i=0; i<edge; i++){
        int u,v ;
        cin>>u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    memset(color,0,sizeof color) ;
    if(coloring(1)){
        cout<< "All node colors: ";
        for(int i=1; i<=node; i++)
           cout<< color[i] << " " ;
        cout<< endl ;
    }
    else
        cout<< "Not possible" << endl ;

    return 0 ;
}
