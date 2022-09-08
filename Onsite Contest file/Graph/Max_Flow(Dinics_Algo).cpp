#include<bits/stdc++.h>
using namespace std ;

const int lim = 3e4+5 ;

namespace max_flow{ // dinic's algorithm
    const long long INF = 1e18 ;
    const int edgeSize = 1e5 + 5 ;
    struct Edge {
        int u, v ;
        long long cap, flow ;
        Edge(){}
        Edge(int a,int b,long long c,long long f){
            u = a, v = b, cap = c, flow = f ;
        }
    };

    vector<int> adj[edgeSize] ;
    vector<Edge> E ;
    int n, s, t, ptr[lim], len[lim], dis[lim], Q[lim] ;

    inline void init(int nodes,int source,int sink){
        int x = E.size() ;
        x /= 2 ;
        E.clear() ;
        memset(len, 0, sizeof(len[0])*(n+3)) ;
        n = nodes, s = source, t = sink ;
        for(int i=0; i<=x; i++)
            adj[i].clear() ;
    }
    
    inline void addEdge(int a,int b,int c){
        adj[a].push_back( E.size() ) ;
        E.push_back( Edge(a, b, c, 0) ) ;
        len[a]++ ;
        adj[b].push_back( E.size() ) ;
        E.push_back( Edge(b, a, 0, 0) ) ;
        len[b]++ ;
    }

    inline bool bfs(){
        int i, j, k, id, f = 0, l = 0 ;
        memset(dis, -1, sizeof(dis[0]) * (n+3)) ;

        dis[s] = 0, Q[l++] = s ;
        while(f < l && dis[t] == -1){
            i = Q[f++] ;
            for(k = 0; k < len[i]; k++){
                id = adj[i][k] ;
                if(dis[ E[id].v ] == -1 && E[id].flow < E[id].cap){
                    Q[l++] = E[id].v ;
                    dis[ E[id].v ] = dis[i] + 1 ;
                }
            }
        }
        return (dis[t] != -1) ;
    }

    long long dfs(int i,long long f){
        if(i == t || !f) return f ;
        while(ptr[i] < len[i]){
            int id = adj[i][ ptr[i] ] ;
            if(dis[ E[id].v ] == dis[i] + 1){
                long long x = dfs(E[id].v, min(f, E[id].cap-E[id].flow)) ;
                if(x){
                    E[id].flow += x, E[id ^ 1].flow -= x ;
                    return x ;
                }
            }
            ptr[i]++ ;
        }
        return 0 ;
    }

    long long dinic(){
        long long res = 0 ;

        while(bfs()){
            memset(ptr, 0, sizeof(ptr[0]) * (n+3)) ;
            while(long long f = dfs(s, INF))
                res += f ;
        }
        return res ;
    }
}

namespace nodeflow{
    void init(int n,int s,int t,vector<int>& capacity){
        max_flow::init(2*n, 2*s, 2*t+1) ;
        for(int i=0; i<n; i++)
            max_flow::addEdge(2*i, 2*i+1, capacity[i]) ;
    }

    void addEdge(int a,int b,int c){
        max_flow::addEdge(2*a+1, 2*b, c) ;
    }

    long long dinic(){
        return max_flow::dinic() ;
    }
}


int main(){
    int n, m ;
    cin>> n >> m ;

    int s = 0, t = n-1 ;
    max_flow::init(n, s, t) ;

    for(int i=0; i<m; i++){
        int u, v, w ;
        cin>> u >> v >> w ;
        u--, v-- ;
        max_flow::addEdge(u, v, w) ;
    }

    cout<< max_flow::dinic() << "\n" ;
    
    return 0 ;
}