#include<bits/stdc++.h>
using namespace std ;
 
/*
    complexity: e * loge
    varified: https://cses.fi/problemset/task/1675/
*/

struct DSU{
    int n ;
    vector<int> par, _rank ;
    
    DSU(int n){
        this->n = n ;
        par.resize(n+5) ;
        _rank.resize(n+5) ;
        iota(par.begin(), par.end(), 0) ;
        fill(_rank.begin(), _rank.end(), 1) ;
    }
    int find_par(int u){
        if(par[u] == u) return u ;
        return par[u] = find_par(par[u]) ;
    }
    bool union_set(int u,int v){
        int up = find_par(u) ;
        int vp = find_par(v) ;
        if(up == vp) return false ;
 
        if(_rank[vp] > _rank[up]) swap(up, vp) ;
        else if(_rank[vp] == _rank[up]) _rank[up]++ ;
        par[vp] = up ;
        return true ;
    }
};
 
vector<array<int, 3> > edges ; // ( u, v, w ) 
 
 
long long kruskal(int n){
    sort(edges.begin(), edges.end(), [](array<int, 3> a,array<int, 3> b){ return a[2] < b[2] ;}) ;
    DSU dsu(n) ;
    long long edge_cnt = 0, sum = 0 ;
 
    for(array<int, 3> ed: edges){
        int u = ed[0], v = ed[1], w = ed[2] ;
        if(dsu.union_set(u, v) == false) continue ;
        edge_cnt++ ;
        sum += w ;
        if(edge_cnt == n-1) break ;
    }
    if(edge_cnt != n-1) return -1 ;
    return sum ;
}
 

int main(){
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) ;

    int n, m ;
    cin>> n >> m ;
    for(int i = 0; i < m; i++){
        int u, v, w ;
        cin>> u >> v >> w ;
        edges.push_back({u, v, w}) ;
    }
 
    long long sum = kruskal(n) ;

    
    if(sum != -1) cout<< sum << "\n" ;
    else cout<< "IMPOSSIBLE\n" ;
    
    return 0 ;
}