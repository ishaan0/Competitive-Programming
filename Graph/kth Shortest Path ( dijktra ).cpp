#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ; 
const int k = 2 ;

vector<pair<int,int> > adj[lim] ;
vector<int> dis[lim] ;

void dijkstra_kth(int src){
    using pii = pair<int,int> ;
    priority_queue< pii, vector<pii >, greater<pii > > pq ;
    for(int i=0; i<lim; i++) dis[i].clear() ;

    pq.push({0, src}) ;
    while(!pq.empty()){
        int u = pq.top().second, d = pq.top().first ;
        pq.pop() ;

        if(dis[u].size() == 0) dis[u].push_back( d ) ;
        else if(dis[u].back() != d) dis[u].push_back( d ) ;

        if(dis[u].size() > k) continue ;

        for(pii nd: adj[u]){
            int v = nd.first, w = nd.second ;
            if(dis[v].size() >= k) continue ;
            pq.push({d + w, v}) ;
        }

    }
}


int main(){
    int n , m ;
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u, v, w ;
        cin>> u >> v >> w ;
        adj[u].push_back( {v, w} ) ;
        adj[v].push_back( {u, w} ) ;
    }

    int src, dest ;
    cin>> src >> dest ;

    dijkstra_kth(src) ;

    for(int i=0; i<dis[dest].size(); i++) cout<< dis[dest][i] << " " ;
    
    return 0 ;
}