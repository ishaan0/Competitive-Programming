#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ;

vector< pair<int,int> > adj[lim] ;
int dis[lim], par[lim] ;

void dijkstra_set(int src){
    using pii = pair<int,int> ;
    set< pii > s ;
    fill(dis, dis+lim, 1e9) ;
    memset(par, -1, sizeof par) ;

    dis[src] = 0 ;
    s.insert({0, src}) ;    // first -> distance , second -> node

    while(!s.empty()){
        int u = ( s.begin() )->second ;
        s.erase(s.begin()) ;
        cerr<< u << "\n" ;
        for(pii nd: adj[u]){
            int v = nd.first , w = nd.second ;

            if(dis[u] + w < dis[v]){
                s.erase({dis[v], v}) ;
                dis[v] = dis[u] + w ;       // path relaxation
                par[v] = u ;                // parent node info
                s.insert({dis[v], v})    ;    // insert updated node info
            }
        }
    }
}


void dijkstra_pq(int src){
    using pii = pair<int,int> ;
    priority_queue< pii, vector<pii >, greater<pii > > pq ;
    fill(dis, dis+lim, 1e9) ;
    memset(par, -1, sizeof par) ;

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
                par[v] = u ;
                pq.push({dis[v], v}) ;
            }
        }
    }
}


vector<int> get_path(int des){
    if(des < 0 || des >= lim){
        cout<< "invalid !!" ;
        exit(0) ;
    }

    vector<int> res ;
    for(int i = des; i != -1; i = par[i])
        res.push_back( i ) ;
    reverse(res.begin(), res.end()) ;

    return res ;
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

    dijkstra_set(src) ;
    
    if(dis[dest] != 1e9){     
        vector<int> arr = get_path(6) ;
        for(int i=0; i<arr.size(); i++)
            cout<< arr[i] << " " ;
        cout<< "\n" ;
    }
    else cout<< "No path possible !!" ;
    
    return 0 ;
}