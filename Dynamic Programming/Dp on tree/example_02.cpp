#include<bits/stdc++.h>
using namespace std ;
#define     ll      long long

/*
    Dp on tree example
    We are given a tree of N node . And each node has a value assigned .
    we need to find a path where node sum is maximum .
*/

const ll lim = 1e5 + 5 ; 

// dp[u] = maximum chain start from u node to its subtree

int n, dp[lim], ans ;
vector<int> adj[lim], arr(lim) ;

void dfs(int u,int p){
    int mx1 = 0 , mx2 = 0 ;
    
    for(int v: adj[u]){
        if(v == p) continue ;
        dfs(v, u) ;
        if(dp[v] > mx1) mx2 = mx1 , mx1 = dp[v] ;
        else if(dp[v] > mx2) mx2 = dp[v] ;
    }

    dp[u] = arr[u] + mx1 ;                  /// get maximum chain
    int add_chain = arr[u] + mx1 + mx2 ;    /// add two maximum chain by u node
    ans = max({ans, dp[u], add_chain}) ;    /// updating answer
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

    ans = 0 ; /// set ans = -inf when atleast one node need to add

    dfs(1, 0) ;
    cout<< ans << "\n" ;
    
    return 0 ;
}