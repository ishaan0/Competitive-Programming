#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e2 + 5 ;

namespace max_flow{ // edmond's karp

    vector<int> adj[lim] ;
    int capacity[lim][lim] ;

    int bfs(int src,int sink,vector<int>& par){
        fill(par.begin(), par.end(), -1) ;
        par[src] = -2 ;
        queue<pair<int,int> > q ;
        q.push({src, 1e9}) ;

        while(!q.empty()){
            int u = q.front().first, flow = q.front().second ;
            q.pop() ;

            for(int v: adj[u]){
                if(par[v] == -1 && capacity[u][v]){
                    par[v] = u ;
                    int new_flow = min(flow, capacity[u][v]) ;
                    if(v == sink) return new_flow ;
                    q.push({v, new_flow}) ;
                }
            }
        }
        return 0 ;
    }

    int edmonds_karp(int src,int sink,int n){
        int flow = 0, new_flow = 0 ;
        vector<int> par(n+5) ;

        while(new_flow = bfs(src, sink, par)){
            flow += new_flow ;
            for(int v = sink; v != src; v = par[v]){
                int u = par[v] ;
                capacity[u][v] -= new_flow ;
                capacity[v][u] += new_flow ;
            }
        }

        return flow ;
    }

    void addEdge(int u,int v,int w){
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
        capacity[u][v] += w ;
    }

    void reset(int n){
        for(int i = 0; i <= n; i++){
            adj[i].clear() ;
            for(int j = 0; j <= n; j++)
                capacity[i][j] = 0 ;
        }
    }
}

using namespace max_flow ;

int main(){
    int n, m ;
    cin>> n >> m ;

    for(int i = 0; i < m; i++){
        int u, v, w ;
        cin>> u >> v >> w ;
        addEdge(u, v, w) ;
    }

    int src, sink ;
    cin>> src >> sink ;

    cout<< edmonds_karp(src, sink, n) << endl ;

    
    return 0 ;
}

/*
    6 9
    0 1 7
    0 2 4
    2 1 3
    1 3 5 
    1 4 3
    2 4 2
    3 5 8
    4 5 5
    4 3 3
    0 5

*/