#include<bits/stdc++.h>
using namespace std ;


const int lim = 1e4 + 5 ; 

vector<int> adj[lim], costs[lim], indexx[lim] ;
int baseArray[lim], ptr, chainNo ;
int chainInd[lim], chainHead[lim], posInBase[lim] ;
int depth[lim], pa[lim][20], otherEnd[lim], sbtr[lim] ;
int sa[4*lim] ;

void reset(int n){
    for(int i=0; i<=n; i++){
        adj[i].clear() ;
        costs[i].clear() ;
        indexx[i].clear() ;
        chainHead[i] = -1 ;
        for(int j=0; j<20; j++) pa[i][j] = -1 ;
    }   
    ptr = chainNo = 0 ;
}

#define left    (iter<<1)+1
#define right   (iter<<1)+2

inline void mrg(int iter){
    sa[iter] = max(sa[left], sa[right]) ;
}

void build_tree(int iter,int lo,int hi){
    if(lo == hi){
        sa[iter] = baseArray[lo] ;
        return ;
    }
    int mid = (lo + hi)>>1 ;
    build_tree(left, lo, mid) ;
    build_tree(right, mid+1, hi) ;
    mrg(iter) ;
}

void update_tree(int iter,int lo,int hi,int qi,int val){
    if(qi < lo || qi > hi) return ;
    else if(qi<= lo && hi <= qi){
        sa[iter] = val ;
        return ;
    }
    int mid = (lo + hi)>>1 ;
    update_tree(left, lo, mid, qi, val) ;
    update_tree(right, mid+1, hi, qi, val) ;
    mrg(iter) ;
}

int query_tree(int iter,int lo,int hi,int qi,int qj){
    if(qi > hi || qj < lo) return INT_MIN ;
    else if(qi <= lo && hi <= qj) return sa[iter] ;
    int mid = (lo + hi)>>1 ;
    int L = query_tree(left, lo, mid, qi, qj) ;
    int R = query_tree(right,mid+1, hi, qi, qj) ;
    return max(L, R) ;
}

void dfs(int u,int par,int _depth=0){
    pa[u][0] = par , depth[u] = _depth, sbtr[u] = 1 ;

    for(int i=0; i<(int)adj[u].size(); i++){
        int v = adj[u][i] ;
        if(v == par) continue ;
        otherEnd[ indexx[u][i] ] = v ;
        dfs(v, u, _depth+1) ;
        sbtr[u] += sbtr[v] ;
    }
}

void build_lca(int n){
    for(int j=1; (1<<j)<n; j++){
        for(int i=0; i<n; i++){
            if(pa[i][j-1] != -1)
                pa[i][j] = pa[ pa[i][j-1] ][j-1] ;
        }
    }
}

int get_lca(int u,int v){
    if(depth[u] < depth[v])
        swap(u,v) ;
    int lg = log2(depth[u]) ;
    for(int i=lg; i>=0; i--){
        if(depth[u]-(1<<i) >= depth[v])
            u = pa[u][i] ;
    }
    if(u == v) return u ;
    for(int i=lg; i>=0; i--){
        if(pa[u][i] != -1 && pa[u][i] != pa[v][i]){
            u = pa[u][i] ;
            v = pa[v][i] ;
        }
    }

    return pa[u][0] ;
}

void build_hld(int u,int cost,int par){
    if(chainHead[ chainNo ] == -1)
        chainHead[ chainNo ] = u ;
    chainInd[ u ] = chainNo ;
    posInBase[ u ] = ptr ;
    baseArray[ ptr++ ] = cost ;

    int mx = -1, bg = -1, ncost = -1 ;
    for(int i=0; i<(int)adj[u].size(); i++){
        int v = adj[u][i] ;
        if(v == par) continue ;
        if(sbtr[v] > mx){
            bg = v ;
            mx = sbtr[v] ;
            ncost = costs[u][i] ;
        }
    }

    if(bg != -1) build_hld(bg, ncost, u) ;

    for(int i=0; i<(int)adj[u].size(); i++){
        int v = adj[u][i] ;
        if(v == par || v == bg) continue ;
        chainNo++ ;
        build_hld(v, costs[u][i], u) ;
    }
}

int query_hld(int u,int v){
    if(u == v) return 0 ;
    int uchain , vchain = chainInd[v] , ans = -1 ;

    while(1){
        uchain = chainInd[u] ;
        if(uchain == vchain){
            if(u == v) break ;
            int temp = query_tree(0, 0, ptr-1, posInBase[v]+1, posInBase[u]) ;
            ans = max(ans, temp) ;
            break ;
        }
        int temp = query_tree(0, 0, ptr-1, posInBase[ chainHead[uchain] ], posInBase[u]) ;
        ans = max(ans, temp) ;
        u = chainHead[uchain] ;
        u = pa[u][0] ;
    }
    return ans ;
}


void query(int u,int v){
    int lca = get_lca(u, v) ;
    int ans =  max(query_hld(u, lca), query_hld(v, lca)) ;
    printf("%d\n", ans) ;
}

void change(int i,int val){
    int u = otherEnd[i] ;
    update_tree(0, 0, ptr-1, posInBase[u], val) ;
}



int main(){
    int t ;
    scanf("%d", &t) ;

    while(t--){
        int n ;
        scanf("%d", &n) ;
        reset(n) ;

        for(int i=0; i<n-1; i++){
            int u, v, c ;
            scanf("%d %d %d", &u, &v, &c) ;
            u--, v-- ;
            adj[u].push_back( v ) ;
            costs[u].push_back( c ) ;
            indexx[u].push_back( i ) ;

            adj[v].push_back( u ) ;
            costs[v].push_back( c ) ;
            indexx[v].push_back( i ) ;
        }

        dfs(0, -1) ;
        build_hld(0, -1, -1) ;
        build_tree(0, 0, ptr-1) ;
        build_lca(n) ;

        while(1){
            char str[15] ;
            scanf("%s", str) ;
            if(str[0] == 'D') break ;

            int a, b;
            scanf("%d %d", &a, &b) ;

            if(str[0] == 'Q') query(a-1, b-1) ;
            else  change(a-1, b) ;
            
        }

    }


    
    return 0 ;
}