#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e3 + 5 ;

int n, m, dis[lim] ;
vector<pair<int,int> > adj[lim] ;


void dijkstra(int src){
	using pii = pair<int,int> ;
    priority_queue< pii, vector<pii >, greater<pii > > pq ;
    vector<int> dis(n+5, 1e9) ;

    pq.push({0, src}) ;
    dis[src] = 0 ;

    while(!pq.empty()){
        int u = pq.top().second, d = pq.top().first ;
        pq.pop() ;

        if(d > dis[u]) continue ;

        for(pii nd: adj[u]){
            int v = nd.first, w = nd.second ;

            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w ;
                pq.push({dis[v], v}) ;
            }
        }
    }
}

int main(){



    
    return 0 ;
}