#include<bits/stdc++.h>
using namespace std ;
#define lim 1000 ;
int const inf = 1e8 ;

/*
    Bellman Ford algorithm used to detect negetive cycle
    complexity : O( V*E )
*/

vector<tuple<int,int,int> > edges ;
int dis[lim] ;
int n,e ;

bool bellman_Ford(int src){
    fill(dis, dis+n, inf) ;
    dis[src] = 0 ;

    for(int i=1; i<n; i++){
        bool relaxed = false ;
        for(auto edg: edges){
            int u,v,w ;
            tie(u,v,w) = edg ;
            if(dis[u] == inf) continue ;
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u]+w ;
                relaxed = true ;
            }
        }
        if(!relaxed) break ;
    }

    /// if we able to do another relaxation then there is a negative cycle so return true .
    for(auto edg: edges){
        int u,v,w ;
        tie(u,v,w) = edg ;
        if(dis[u]+w < dis[v])
            return true ;
    }
    
    return false ;
}

int main(){

    cin>> n >> e ;
    for(int i=0; i<e; i++){
        int u,v,w ;
        cin>> u >> v >> w;
        edges.push_back(make_tuple(u,v,w)) ;
    }

    if(bellman_Ford(1)){
        cout<< "Negative edge cycle present." << endl ;
        return 0 ;
    }

    int q ;
    cin>> q ;
    while(q--){
        int v ;
        cin>> v ;
        cout<< d[v] << endl ;
    }

    return 0 ;
}
