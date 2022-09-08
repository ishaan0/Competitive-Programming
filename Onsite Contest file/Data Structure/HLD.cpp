#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ;

int chainNo, ptr, arr[lim], parent[lim] ;
int chainInd[lim], chainHead[lim] ;
int posInBase[lim], sbtr[lim] ;

vector<int> adj[lim], baseArray[lim] ;

#define     left    (iter<<1)
#define     right   (left | 1)
#define     mid     (lo + ((hi - lo)>>1))
template<typename T>
struct SegmentTree_lazy{ // 0 based
    int n ;
    vector< pair<T,T> > segtree ;
    SegmentTree_lazy(){}
    SegmentTree_lazy(int n,vector<T>& arr){
        init(n, arr) ;
    }
    void init(int n,vector<T>& arr){
        this->n = n ;
        segtree.assign(4*n+10, make_pair(0, 0)) ;
        build(1, 0, n-1, arr) ;
    }
    inline void mrg(int iter){          // Change
        segtree[iter].first = segtree[left].first + segtree[right].first ; 
        segtree[iter].second = 0 ;  
    }
    void build(int iter,int lo,int hi,vector<T>& arr){
        if(lo == hi){
            segtree[iter] = {arr[lo], 0} ; 
            return ;
        }
        build(left, lo, mid, arr) ;
        build(right, mid+1, hi, arr) ;
        mrg(iter) ;
    }
    inline void lazy_update(int iter,int lo,int hi,T x){
        segtree[iter].first += (hi-lo+1LL) * x ;     // Change
        segtree[iter].second += x ;
    }
    inline void push_down(int iter,int lo,int hi){
        lazy_update(left,lo,mid,segtree[iter].second) ;
        lazy_update(right,mid+1,hi,segtree[iter].second) ;
        segtree[iter].second = 0 ;                   // Change
    }
    void update(int iter,int lo,int hi,int qi,int qj,T x){
        if(lo > qj || hi < qi) return ;
        if(qi <= lo && hi <= qj){
            lazy_update(iter,lo,hi,x) ;
            return ;
        }
        push_down(iter,lo,hi) ;
        update(left,lo,mid,qi,qj,x) ;
        update(right,mid+1,hi,qi,qj,x) ;
        mrg(iter) ;
    }
    void update(int qi,int qj,T x){
        update(1, 0, n-1, qi, qj, x) ;
    }
    T query(int iter,int lo,int hi,int qi,int qj){
        if(lo > qj || hi < qi) return 0 ;           // Change
        if(qi <= lo && hi <= qj) return segtree[iter].first ;
        push_down(iter,lo,hi) ;
        T L = query(left,lo,mid,qi,qj) ;
        T R = query(right,mid+1,hi,qi,qj) ;
        mrg(iter) ;
        return L + R ;           // Change
    }
    T query(int qi,int qj){
        return query(1, 0, n-1, qi, qj) ;
    }
} ;
SegmentTree_lazy<int> seg[lim] ;

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
    void dfs(int u,int p=-1,int d=0){
        euler[timer] = {d, u}, sbtr[u] = 1 ;
        in[u] = timer++, depth[u] = d, parent[u] = p ;
        for(int v: adj[u]){
            if(in[v] != -1) continue ;
            dfs(v, u, d+1) ;
            sbtr[u] += sbtr[v] ;
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
}

void build_hld(int u,int par){
    if(chainHead[ chainNo ] == -1)
        chainHead[ chainNo ] = u ;
    chainInd[ u ] = chainNo ;
    
    baseArray[chainNo].push_back(arr[u]) ;
    posInBase[ u ] = ptr++ ;

    int mx = -1, bg = -1, ncost = -1 ;
    for(int i=0; i<(int)adj[u].size(); i++){
        int v = adj[u][i] ;
        if(v == par) continue ;
        if(sbtr[v] > mx){
            bg = v ;
            mx = sbtr[v] ;
        }
    }

    if(bg != -1) build_hld(bg, u) ;

    for(int i=0; i<(int)adj[u].size(); i++){
        int v = adj[u][i] ;
        if(v == par || v == bg) continue ;
        chainNo++ ;
        ptr = 0 ;
        build_hld(v, u) ;
    }
}

long long query_hld(int u,int v){
    if(u == v) return 0 ;
    long long uchain , vchain = chainInd[v] , ans = 0 ;

    while(1){
        uchain = chainInd[u] ;
        if(uchain == vchain){
            if(u == v) break ;
            long long temp = seg[uchain].query(1, 0, (int)baseArray[uchain].size()-1, posInBase[v], posInBase[u]) ;
            ans += temp ;
            break ;
        }
        long long temp = seg[uchain].query(1, 0, (int)baseArray[uchain].size()-1, posInBase[ chainHead[uchain] ], posInBase[u]);
        ans += temp ;
        u = chainHead[uchain] ;
        u = parent[u] ;
    }
    return ans ;
}
long long query(int u,int v){
    int lca = LCA::query(u, v) ;
    long long ans =  query_hld(u, lca) + query_hld(v, lca) ;
    return ans ;
}

void update_hld(int u,int v){
    if(u == v) return ;
    int uchain , vchain = chainInd[v] ;

    while(1){
        uchain = chainInd[u] ;
        if(uchain == vchain){
            if(u == v) break ;
            seg[uchain].update(1, 0, (int)baseArray[uchain].size()-1, posInBase[v], posInBase[u], 1) ;
            break ;
        }
        seg[uchain].update(1, 0, (int)baseArray[uchain].size()-1, posInBase[ chainHead[uchain] ], posInBase[u], 1);
        u = chainHead[uchain] ;
        u = parent[u] ;
    }
}
void update(int u,int v){
    int lca = LCA::query(u, v) ;
    update_hld(u, lca) ;
    update_hld(v, lca) ;
}


// At first call this function
void reset(int n){
    for(int i=0; i<=n; i++){
        adj[i].clear() ;
        baseArray[i].clear();
        chainHead[i] = parent[i] = -1 ;
    }   
    LCA::rmq.table.clear() ;
    chainNo = ptr = 0 ;
}

// Then call this fuction
void init(int n){
    LCA::build(n) ;
    build_hld(0, -1) ;
    for(int i = 0; i <= chainNo; i++)
        seg[i].init(baseArray[i].size(), baseArray[i]) ;
}

int main(){
    int n ;
    cin>> n ;

    reset(n) ;
    for(int i = 0; i < n-1; i++){
        int u, v ;
        cin>> u >> v ;
        u--, v-- ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    for(int i = 0; i < n; i++) cin>> arr[i] ;
    init(n) ;

    int q ;
    cin>> q ;

    while(q--){
        int tp ;
        cin>> tp ;
        if(tp == 1){
            int u, v ;
            cin>> u >> v ;
            u--, v-- ;
            cout<< query(u, v) << endl ;
        }
        else{
            int u, v ;
            cin>> u >> v ;
            u--, v-- ;
            update(u, v) ;
        }
    }
    
    return 0 ;
}