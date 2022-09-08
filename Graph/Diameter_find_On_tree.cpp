#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define lim 10000

vector<int> adj[lim] ;
bool vis[lim] ;
int src2,dis ;

void DFS(int src,int cnt){
    if(vis[src]) return ;
    vis[src] = true ;
    for(int node: adj[src])
        DFS(node,cnt+1) ;
    if(cnt >= dis){
        src2 = src ;
        dis = cnt ;
    }
}


int main(){

    int v,e ;
    cin>> v >> e ;

    int src,src2 ;
    for(int i=0; i<e; i++){
        int x,y ;
        cin>> x >>y ;
        src = x ;
        adj[x].pb(y) ;
        adj[y].pb(x) ;
    }
    dis= 0 ;
    memset(vis, 0, sizeof(vis)) ;
    DFS(src,0) ;

    dis = 0 ;
    src = src2 ;
    memset(vis, 0, sizeof(vis)) ;
    DFS(src,0) ;

    cout<< "The diameter is between: "<<src<<" and "<<src2<< " is: "<<dis<<endl;

    return 0 ;
}
