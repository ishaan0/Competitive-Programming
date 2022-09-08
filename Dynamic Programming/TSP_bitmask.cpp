#include<bits/stdc++.h>
using namespace std ;

int node,edge,target ;
int adj[20][20] ;
int dp[16][(1<<16)+100] ;

int setBit(int n,int pos){ return (n|(1<<pos)); }
bool checkBit(int n,int pos){ return (bool)(n&(1<<pos)); }
int toogleBit(int n,int pos){ return (n^(1<<pos)); }

/// memory : O(n*2^n)   time : O(n*n*2^n)
int TSP(int u,int mask){
    if(mask == target) return adj[u][0] ;
    int &ans = dp[u][mask] ;
    if(ans != -1) return ans ;
    ans = INT_MAX ;
    for(int v=0; v<node; v++){
        int w = adj[u][v] ;
        if(!checkBit(mask,v))
            ans = min(ans,w+TSP(v,setBit(mask,v))) ;
    }
    return ans ;
}

int main(){
    cin>> node >> edge ;
    for(int i=0; i<node; i++)
        fill(adj[i], adj[i]+node,1e6) ;

    for(int i=0; i<edge; i++){
        int u,v,w ;
        cin>> u >> v >> w ;
        adj[u][v] = w ;
        adj[v][u] = w ;
    }

    memset(dp,-1,sizeof dp) ;
    target = (1<<node)-1 ;
    int ans = TSP(0,1) ;
    cout<< ans << endl ;

    return 0 ;
}
