#include<bits/stdc++.h>
using namespace std ;

/*
    Question : 
    A graph will be given where each node will have some color in it .
    Now you have to ans some query which will like 
    u c ; where u is node and c is color . So you need to tell
    how many c color is in the subtree of node u .
*/

/*
    Solution : 
    A naive soluton is to run a dfs for every node in each query which is costly .
    So we will do dsu on tree which is basically a small to large trick or 
    heavy light trick . Where we will find color count for each node by bruteforce
    it's small child and for big child the count will be saved in map .
    In this problem we calculate all query in offline .

    time : O( nlogn )
*/



const ll lim = 1e5 + 5 ; 

int n, q, t ;
vector<int> adj[lim] ;
vector<pair<int,int> > query[lim] ;
int color[lim], sbtr[lim], order[lim], vrtx[lim], ans[lim] ;
unordered_map<int,int> cnt ;

void dfs_1(int u,int p){
    sbtr[u] = 1 ;
    order[u] = t , vrtx[t] = u , t++ ;
    for(int v: adj[u]){
        if(v == p) continue ;
        dfs_1(v, u) ;
        sbtr[u] += sbtr[v] ;
    }
}

void dfs_2(int u,int p,int keep){
    int mx = -1, bg = -1 ;
    for(int v: adj[u]){
        if(v == p) continue ;
        if(sbtr[v] > mx) mx = sbtr[v] , bg = v ;
    }

    for(int v: adj[u]){
        if(v == p || v == bg) continue ;
        dfs_2(v, u, 0) ;
    }
    if(bg != -1) dfs_2(bg, u, 1) ;

    for(int v: adj[u]){
        if(v == p || v == bg) continue ;
        for(int i=order[v]; i<order[v]+sbtr[v]; i++){
            int x = vrtx[i] ;
            cnt[ color[x] ]++ ;
        }
    }
    cnt[ color[u] ]++ ;

    for(int i=0; i<query[u].size(); i++){
        int c = query[u][i].first , idx = query[u][i].second ;
        ans[idx] = cnt[ c ] ;
    }

    if(!keep) cnt.clear() ;
}

int main(){
    cin>> n ;
    for(int i=0; i<n; i++){
        int u, v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }
    for(int i=1; i<=n; i++)
        cin>> color[i] ;

    cin>> q ;
    for(int i=0; i<q; i++){
        int u, c ;
        cin>> u >> c ;
        query[u].push_back({c, i}) ;
    }

    dfs_1(1, 0) ;
    dfs_2(1, 0, 1) ;

    for(int i=0; i<q; i++) cout<< ans[i] << " " ;
    cout<< "\n" ;
    
    return 0 ;
}