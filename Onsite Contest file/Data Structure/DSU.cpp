#include<bits/stdc++.h>
using namespace std ;

/*
    Disjoint Set Unio (DSU) is used to merge multiple set
    and get to know two elements set are same set or not in 
    efficient way .
*/

struct DSU{
    int n ;
    vector<int> par, _rank ;
    vector<bool> component ;
    // O(n)
    DSU(int n){
        this->n = n ;
        par.resize(n+5) ;
        _rank.resize(n+5) ;
        iota(par.begin(), par.end(), 0) ;
        fill(_rank.begin(), _rank.end(), 1) ;
    }
    // O(1)
    int find_par(int u){
        if(par[u] == u) return u ;
        return par[u] = find_par(par[u]) ;
    }
    // O(1)
    void union_set(int u,int v){
        int up = find_par(u) ;
        int vp = find_par(v) ;
        if(up == vp) return ;

        if(_rank[vp] > _rank[up]) swap(up, vp) ;
        else if(_rank[vp] == _rank[up]) _rank[up]++ ;
        par[vp] = up ;
    }
    // O(n)
    int comp_count(){
        int ret = 0 ;
        component.resize(n+5) ;
        for(int i=1; i<=n; i++)
            component[ find_par(i) ] = 1 ;
        for(int i=1; i<=n; i++) if(component[i])
            ret++ ;
        return ret ;
    }
};


int main(){
    int n, q ;
    cin>> n >> q ;

    DSU dsu(n) ;
    while(q--){
        int tp, u, v ;
        cin>> tp >> u >> v ;
        if(tp){
            if(dsu.find_par(u) == dsu.find_par(v)) cout<< "1\n" ;
            else cout<< "0\n" ;
        }
        else{
            dsu.union_set(u, v) ;
        }
    }

    
    return 0 ;
}