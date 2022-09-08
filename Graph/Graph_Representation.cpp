#include<bits/stdc++.h>
using namespace std ;
#define lim 10000

/// adjacency matrix in O(n^2) memory with weight
int adjMatrix[lim][lim] ;

void setMatrix(int u, int v, int w){
    adjMatrix[u][v] = w ;
    adjMatrix[v][u] = w ;
}

/// adjacency list in O(n^2) memory with weight
vector<int> adjList[lim], weight[lim] ;

void setList(int u, int v, int w){
    adjList[u].push_back(v) ;
    adjList[v].push_back(u) ;
    weight[u].push_back(w) ;
    weight[v].push_back(w) ;
}

int main(){

    int u, v, w ;
    for(int i=0; i<5; i++){
        cin>> u>> v >> w ;
        setMatrix(u,v,w) ;
        setList(u,v,w) ;
    }

    return 0 ;
}
