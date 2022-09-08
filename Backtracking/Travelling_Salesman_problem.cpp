#include<bits/stdc++.h>
using namespace std ;

int n,m ;
int graph[20][20] ;
bool vis[30] ;

int TSP(int u,int cnt){
    if(cnt == n)
        return graph[u][1] ;

    int ans = INT_MAX ;
    for(int v=0; v<n; v++){
        int w = graph[u][v] ;
        if(!vis[v]){
            vis[v] = true ;
            int temp = w + TSP(v,cnt+1) ;
            vis[v] = false ;
            ans = min(ans,temp) ;
        }
    }
    return ans ;
}

int main(){
    cin>> n >> m;
    for(int i=0; i<m; i++){
        int u,v ;
        cin>> u>> v ;
        graph[u] = v ;
        graph[v] = u ;
    }
    memset(vis,0,sizeof vis) ;
    cout<< "Total cost: " << TSP(1,1) ;

    return 0 ;
}
