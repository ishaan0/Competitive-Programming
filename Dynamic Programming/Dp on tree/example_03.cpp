#include<bits/stdc++.h>
using namespace std ;
#define     ll      long long

/*
    Dp on tree example
    We are given a tree of N node . we need to find number of all 
    possible subgraph present on that tree .
*/

const ll lim = 1e5 + 5 ; 


int n, dp[lim] ;
vector<int> adj[lim] ;

void dfs(int u,int p){
    dp[u] = 1 ;
    for(int v: adj[u]){
        if(v == p) continue ;
        dfs(v, u) ;
        dp[u] *= (1 + dp[v]) ;          /// taking dp[v] subgraph and without taking
    }
}

int main(){
    cin>> n ;

    for(int i=0; i<n-1; i++){
        int u, v ;
        cin>> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    dfs(1, 0) ;

    int ans = 0 ;
    for(int i=1; i<=n; i++) ans += dp[i] ;  /// sum to get all possible subgraph

    cout<< ans << "\n" ;
    
    return 0 ;
}