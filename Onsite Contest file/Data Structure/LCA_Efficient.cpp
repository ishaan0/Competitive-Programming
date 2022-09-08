#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ;

vector<int> adj[lim] ;

template<typename T>
struct RMQ{ // 0 based
    vector<vector<T> > table ;
    T kInf = numeric_limits<T>::max() ;

    RMQ(){}
    RMQ(const vector<T>& arr){
        build(arr) ;
    }

    void build(const vector<T>& arr){
        int n = arr.size() ;
        table.assign(1, arr) ;
        for(int i = 0; (1<<(i+1)) <= n; i++){
            table.push_back(vector<T>(n)) ;
            for(int j = 0; j+(1<<(i+1)) <= n; j++)
                table[i+1][j] = min(table[i][j], table[i][j+(1<<i)]) ;
        }
    }

    T query(int lo,int hi){
        if(hi < lo) return kInf ;
        int i = 31 - __builtin_clz(hi-lo+1) ;
        return min(table[i][lo], table[i][hi-(1<<i)+1]) ;
    }
};

namespace LCA{  // 0 based
    int n, timer ;
    vector<int> in, out, depth ;
    vector<pair<int,int> > euler ;
    RMQ<pair<int,int> > rmq ;

    void dfs(int u,int d=0){
        euler[timer] = {d, u} ;
        in[u] = timer++, depth[u] = d ;
        for(int v: adj[u]){
            if(in[v] != -1) continue ;
            dfs(v, d+1) ;
            euler[timer++] = {d, u} ;
        }
        out[u] = timer ;
    }

    void build(int m){
        n = m, timer = 0 ; 
        in.assign(n, -1), out.assign(n, -1) ;
        depth.assign(n, 0), euler.assign(2*n, make_pair(0, 0)) ;
        dfs(0) ;
        rmq.build(euler) ;
    }

    int query(int u,int v){
        u = in[u], v = in[v] ;
        if(u > v) swap(u, v) ;
        return rmq.query(u, v).second ;
    }

    int dist(int u,int v){
        return depth[u]+depth[v]-(depth[query(u, v)]<<1) ;
    }
}

using namespace LCA ;

int main(){
    int n ;
    cin>> n ;

    for(int i = 0; i < n-1; i++){
        int u, v ;
        cin>> u >> v ;
        u--, v-- ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    build(n) ;

    cout<< query(3, 5) << endl ;
    cout<< dist(3, 6) << endl ;

    /*
        7
        1 2
        2 3
        3 4
        1 5
        5 6
        6 7
    */

    return 0 ;
}