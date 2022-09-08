#include<bits/stdc++.h>
using namespace std ;
#define lim 10000
#define pb push_back

vector<int> adj[lim] ;
vector<bool> vis(lim) ;

/// complexity ( V + E )

/// dfs Recursive
void dfs_recursive(int u){
    vis[u] = true ;
    for(int v: adj[u]){
        if(vis[v]) continue ;
        dfs(v) ;
    }
}

vector<int> time_in(lim, -1), time_out(lim, -1) ;
int timer, cycle ;

void dfs_timer(int u){
    time_in[u] = timer++ ;
    vis[u] = 1 ;
    for(int v: adj[u]){
        if(vis[v]) continue ;
        dfs_timer(v) ;
    }
    time_out[u] = timer++ ;
}

void dfs_edge_classification(int u){
    time_in[u] = timer++ ;
    vis[u] = 1 ;
    for(int v: adj[u]){
        if(vis[u]){     // already visited node

            if(time_out[v] == -1)   // v is ancestor of u. found back edge
                cycle = 1 ;
            else if(time_in[u] < time_in[v]) // v is decendant of u, found forward edge
                ;
            else ;      // found cross edge
        }
        else dfs_edge_classification(v) ;
    }
    time_out[u] = timer++ ;
}

int main(){

    

    return 0 ;
}
