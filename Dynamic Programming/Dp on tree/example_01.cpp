#include<bits/stdc++.h>
using namespace std ;
#define     ll          long long

/*
    Dp on tree example
    We are given a tree of n node and those node have some value assigned .
    we need to pick a set of node from that tree such that we have maximum
    sum of node value and we cannot pick two adjacent node .
*/

const ll lim = 1e5 + 5 ; 

int n, dp[lim][2] ;
vector<int> adj[lim], arr(lim) ;

void dfs(int u,int p){
    dp[u][0] = 0 ;
    dp[u][1] = arr[u] ;
    for(int v: adj[u]){
        if(v == p) continue ;
        dfs(v, u) ;
        dp[u][0] += max(dp[v][0], dp[v][1]) ;   /// without taking current node
        dp[u][1] += dp[v][0] ;                  /// taking current node
    }
}

int main(){
    cin>> n ;
    for(int i=1; i<=n; i++)
        cin>> arr[i] ;
    
    for(int i=0; i<n-1; i++){
        int u, v ;
        cin>> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    dfs(1, 0) ;
    cout<< max(dp[1][0], dp[1][1]) << "\n" ;
    
    return 0 ;
}