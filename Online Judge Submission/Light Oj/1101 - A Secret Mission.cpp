#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &value: cont)
#define     show(val)           cout<< #val << " -> " << val << endl
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs << ": "
#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;

#define lim 50005

struct data{
    int u,v,w ;
};

vector<int> adj[lim],cost[lim];
vector<data> edge ;
int p[lim],dept[lim],temp[lim],dis[lim] ;
int par[lim][17], mx[lim][17];

void reset(){
    for(int i=0; i<lim; i++){
        adj[i].clear() ;
        cost[i].clear() ;
        temp[i] = -1 ;
        dept[i] = -1 ;
        dis[i] = 0 ;
        p[i] = i ;
    }
    edge.clear() ;
    memset(par,-1,sizeof par) ;
    memset(mx,-1,sizeof mx) ;
}


bool cmp(data a,data b){
    return a.w < b.w ;
}

int findP(int n){
    if(p[n] == n) return n ;
    return p[n] = findP(p[n]) ;
}

void kruskal(int n){
    sort(all(edge),cmp) ;
    int cnt = 0 ;
    for(int i=0; i<edge.size() && cnt < n-1; i++){
        int u = edge[i].u ;
        int v = edge[i].v ;
        int c = edge[i].w ;
        u = findP(u) ;
        v = findP(v) ;
        if(u != v){
            p[v] = u ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
            cost[u].pb(c) ;
            cost[v].pb(c) ;
            cnt++ ;
        }

    }
}

void dfs(int u,int from,int cnt){
    temp[u] = from ;
    dept[u] = cnt ;

    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i] ;
        if(dept[v] == -1){
            dis[v] = cost[u][i] ;
            dfs(v,u,cnt+1) ;
        }
    }
}

void build(int n){
    dfs(1,1,0) ;
    for(int i=1; i<=n; i++){
        par[i][0] = temp[i] ;
        mx[i][0] = dis[i] ;
    }

    for(int j=1; (1<<j)<n; j++){
        for(int i=1; i<=n; i++)
            if(par[i][j-1] != -1){
                int tt = par[i][j-1] ;
                par[i][j] = par[tt][j-1] ;
                mx[i][j] = max(mx[i][j-1],mx[tt][j-1]) ;
            }
    }
}

int query(int u,int v){
    if(dept[u] < dept[v])
        swap(u,v) ;
    int lg=log2(dept[u]) ;

    int ans = 0 ;
    for(int i=lg; i>=0; i--){
        if(dept[u]-(1<<i) >= dept[v]){
            ans = max(ans,mx[u][i]) ;
            u = par[u][i] ;
        }
    }
    if(u == v) return ans ;

    for(int i=lg; i>=0; i--){
        if(par[u][i] != -1 && par[u][i] != par[v][i]){
            ans = max(ans,mx[u][i]) ;
            ans = max(ans,mx[v][i]) ;
            u = par[u][i] ;
            v = par[v][i] ;
        }
    }
    ans = max(ans,dis[u]) ;
    ans = max(ans,dis[v]) ;
    return ans ;
}


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0 ;
    scanf("%d",&t) ;

    while(t--){
        reset() ;
        int n,m ;
        scanf("%d%d",&n,&m) ;
        for(int i=0; i<m; i++){
            data tt ;
            scanf("%d%d%d",&tt.u,&tt.v,&tt.w) ;
            edge.pb(tt) ;
        }

        kruskal(n) ;
        build(n) ;

        int q ;
        scanf("%d",&q) ;
        printf("Case %d:\n",++cs) ;
        while(q--){
            int u,v ;
            scanf("%d%d",&u,&v) ;
            int ans = query(u,v) ;

            printf("%d\n",ans) ;
        }
    }

    return 0;
}



