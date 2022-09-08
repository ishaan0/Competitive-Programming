#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ;

vector< pair<int,int> > adj[lim] ;
int dis1[lim], dis2[lim] ;



void dijkstra(int src){
    using pii = pair<int,int> ;
    priority_queue< pii, vector<pii >, greater<pii > > pq ;
    fill(dis1, dis1+lim, 1e9) ;
    fill(dis2, dis2+lim, 1e9) ;

    pq.push({0, src}) ;
    dis1[src] = 0 ;

    while(!pq.empty()){
        int u = pq.top().second, d = pq.top().first ;
        pq.pop() ;

        if(d > dis2[u]) continue ;

        for(pii nd: adj[u]){
            int v = nd.first, w = nd.second ;
            
            if(d + w < dis1[v]){
                dis2[v] = dis1[v] ;
                dis1[v] = d + w ;
                pq.push({dis1[v], v}) ;
            }
            else if(d + w < dis2[v]){
                dis2[v] = d + w ;
                pq.push({dis2[v], v}) ;
            }
        }
    }
}



int main(){
    int n, m ;
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u, v, w ;
        cin>> u >> v >> w ;
        adj[u].push_back( {v, w} ) ;
        adj[v].push_back( {u, w} ) ;
    }

    int src, dest ;
    cin>> src >> dest ;

    dijkstra(src) ;
    
    cout<< dis1[dest] << " " << dis2[dest] << "\n" ;

    return 0 ;
}