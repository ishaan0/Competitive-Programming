#include<bits/stdc++.h>
using namespace std ;


/*
    We can find Strongly Connected Component ( SCC ) in two algorithm
        1. Kosaraju's algorithm
        2. Tarjan's algorithm
    Both algorithm's complexity O(V + E)
*/


namespace scc{
    const int lim = 1e5 + 5 ; 

    vector<int> adj[lim], rev[lim], sup[lim] ;
    vector<int> comp(lim), order ;
    int vis[lim], timeIn[lim], low[lim], timer, cmp_cnt ;
    stack<int> stk ;

    void dfs_1(int u){
        vis[u] = 1 ;
        for(int v: adj[u]){
            if(vis[v]) continue ;
            dfs_1(v) ;
        }
        order.push_back( u ) ;
    }

    void dfs_2(int u,int cnt){
        vis[u] = 1 ;
        comp[u] = cnt ;
        for(int v: rev[u]){
            if(vis[v]) continue ;
            dfs_2(v, cnt) ;
        }
    }

    void dfs_3(int u){
        vis[u] = 1 ;
        timeIn[u] = low[u] = ++timer ;
        stk.push(u) ;

        for(int v: adj[u]){
            if(!vis[v]){
                dfs_3(v) ;
                if(vis[v] == 1) low[u] = min(low[u], low[v]) ;
            }
            else if(vis[v] == 1) low[u] = min(low[u], timeIn[v]) ;
        }

        if(timeIn[u] == low[u]){
            cmp_cnt++ ;
            cout<< "SCC no. " << cmp_cnt << " : " ;

            while(true){
                int x = stk.top() ;
                stk.pop() ;
                vis[x] = 2 ;
                cout<< x << " " ;
                if(u == x) break ;
            }
            cout<< "\n" ;
        }
    }

    void scc_kosaraju(int n){
        order.clear() ;
        memset(vis, 0, sizeof vis) ;
        for(int i=1; i<=n; i++) if(!vis[i])
            dfs_1(i) ;
        memset(vis, 0, sizeof vis) ;
        reverse(order.begin(), order.end()) ;
        int cnt = 0 ;
        for(int u: order){
            if(vis[u]) continue ;
            dfs_2(u, ++cnt) ;
        }
    }

    void scc_tarjan(int n){
        memset(vis, 0, sizeof vis) ;
        for(int i=1; i<=n; i++) if(!vis[i])
            dfs_3(i) ;
    }


    void build_super(int n){
        for(int u=1; u<=n; u++){
            for(int v: adj[u]){
                if(comp[u] != comp[v])
                    sup[ comp[u] ].push_back( comp[v] ) ;
            }
        }
    }

    void reset(){
        for(int i=0; i<lim; i++){
            adj[i].clear() ;
            rev[i].clear() ;
            sup[i].clear() ;
            comp[i] = order[i] = vis[i] = 0 ;
        }
        timer = 0 ;
    }
}


int main(){
    scc::reset() ;

    int n, m ;
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u, v ;
        cin>> u >> v ;
        scc::adj[u].push_back( v ) ;
        scc::rev[v].push_back( u ) ;
    }

    scc::scc_kosaraju(n) ;
    scc::build_super(n) ;
    scc::scc_tarjan(n) ;


    return 0 ;
}