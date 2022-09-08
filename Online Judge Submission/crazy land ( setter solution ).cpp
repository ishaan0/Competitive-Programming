#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ; 

vector<int> adj[lim] ;
int n, m, ans, type[lim] ;

void dfs(int u,int par = -1,int cnt = 0){
    if(type[u] == 1) cnt++ ;
    else if(type[u] == 2) cnt = 0 ;

    for(int v: adj[u]){
        if(v == par) continue ;
        if(cnt == m && type[v] == 2) 
            dfs(v, u, cnt) ;
        else if(cnt != m) dfs(v, u, cnt) ;
    }

    if(adj[u].size() == 1) ans++ ;
}


int main(){
    scanf("%d %d", &n, &m) ;
    for(int i = 1; i <= n; i++)
        scanf("%d", &type[i]) ;

    for(int i = 0; i < n-1; i++){
        int u, v ;
        scanf("%d %d", &u, &v) ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }

    dfs(1) ;

    printf("%d\n", ans) ;
    
    return 0 ;
}