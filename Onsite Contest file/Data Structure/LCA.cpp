#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ;

vector<int> adj[lim] ;


namespace LCA{  // 1 based graph
    const int lg = 18 ;
    int n, table[lim][lg+1] ;
    int depth[lim] ;


    void dfs(int u,int par = 0){
        table[u][0] = par, depth[u] = depth[par] + 1 ;
        for(int i = 1; i <= lg; i++)
            table[u][i] = table[ table[u][i-1] ][i-1] ;
        for(int v: adj[u]){
            if(v == par) continue ;
            dfs(v, u) ;
        }
    }

    void build(int m){
        n = m ;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= lg; j++)
                table[i][j] = 0 ;
        dfs(1) ;
    }

    int query(int u,int v){
        if(depth[u] < depth[v]) swap(u, v) ;
        for(int i = lg; i >= 0; i--)
            if(depth[table[u][i]] >= depth[v]) u = table[u][i] ;
        if(u == v) return u ;
        for(int i = lg; i >= 0; i--)
            if(table[u][i] != table[v][i]) u = table[u][i], v = table[v][i] ;
        return table[u][0] ;
    }

    int kth(int u,int k){
        assert(k >= 0) ;
        for(int i = 0; i <= lg; i++)
            if(k & (1<<i)) u = table[u][i] ;
        return u ;
    }

    int dist(int u,int v){
        int l = query(u, v) ;
        return depth[u] + depth[v] - (depth[l] << 1) ;
    }

    int go(int u,int v,int k){
        int l = query(u, v) ;
        int d = depth[u] + depth[v] - (depth[l] << 1) ;
        assert(k <= d) ;
        if(depth[l]+k <= depth[u]) return kth(u, k) ;
        k -= depth[u] - depth[l] ;
        return kth(v, depth[v] - depth[l] - k) ;
    }

}

using namespace LCA ;

int main(){
    int n ;
    cin>> n ;

    for(int i = 0; i < n-1; i++){
        int u, v ;
        cin>> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    build(n) ;

    cout<< query(4, 2) << endl ;
    cout<< kth(4, 2) << endl ;
    cout<< dist(4, 7) << endl ;
    cout<< go(4, 7, 2) << endl ;

    /* Input graph
        7
        1 2
        2 3
        3 4
        1 5
        5 6
        6 7
    */
    
    return 0 ;
}