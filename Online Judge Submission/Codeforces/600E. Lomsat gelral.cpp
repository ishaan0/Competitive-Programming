#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back

const ll lim = 1e5 + 5 ; 

int n, q, t ;
vector<int> adj[lim] ;
vector<pair<int,int> > query[lim] ;
int color[lim], sbtr[lim], order[lim], vrtx[lim] ;
ll ans[lim] ;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pair<uint64_t,uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

ll mx_c, sum ;
unordered_map<int,int,custom_hash> cnt ;

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
            if(cnt[ color[x] ] > mx_c){
                mx_c = cnt[ color[x] ] ;
                sum = color[x] ;
            }
            else if(cnt[ color[x] ] == mx_c)
                sum += color[x] ;
        }
    }
    cnt[ color[u] ]++ ;
    if(cnt[ color[u] ] > mx_c){
        mx_c = cnt[ color[u] ] ;
        sum = color[u] ;
    }
    else if(cnt[ color[u] ] == mx_c)
        sum += color[u] ;

    ans[u] = sum ;

    if(!keep){
        cnt.clear() ;
        mx_c = sum = 0 ;
    }
}

int main(){
    cnt.reserve(1024) ;
    cnt.max_load_factor(0.25) ;

    cin>> n ;
    for(int i=1; i<=n; i++)
        cin>> color[i] ;
    for(int i=0; i<n-1; i++){
        int u, v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }

    dfs_1(1, -1) ;
    dfs_2(1, -1, 0) ;

    for(int i=1; i<=n; i++)
        cout<< ans[i] << " " ;
    cout<< "\n" ;
    
    return 0 ;
}