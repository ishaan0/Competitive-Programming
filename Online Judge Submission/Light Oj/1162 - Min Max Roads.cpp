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

#define lim 100005

int par[lim][20] , mx[lim][20], mn[lim][20] ;
int temp[lim], dept[lim],dis[lim] ;
vector<pii > adj[lim] ;

void reset(){
    for(int i=0; i<lim; i++){
        adj[i].clear() ;
        temp[i] = -1 ;
        dept[i] = -1 ;
        dis[i] = 0 ;
    }
    memset(par,-1,sizeof par) ;
    memset(mx,-1,sizeof mx) ;
    memset(mn,-1,sizeof mn) ;
}

void dfs(int u,int from,int cnt){
    temp[u] = from ;
    dept[u] = cnt ;
    for(pii v: adj[u])
        if(v.ff != from){
            dis[v.ff] = v.ss ;
            dfs(v.ff,u,cnt+1) ;
        }
}

void build(int n){
    dfs(1,-1,0) ;
    for(int i=1; i<=n; i++){
        par[i][0] = temp[i] ;
        mn[i][0] = dis[i] ;
        mx[i][0] = dis[i] ;
    }

    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i<=n; i++){
            if(par[i][j-1] != -1){
                int tt = par[i][j-1] ;
                par[i][j] = par[tt][j-1] ;
                mn[i][j] = min(mn[i][j-1],mn[tt][j-1]) ;
                mx[i][j] = max(mx[i][j-1],mx[tt][j-1]) ;
            }
        }
    }
}

pii query(int u,int v){
    if(dept[u] < dept[v])
        swap(u,v) ;
    int lg = log2(dept[u]) ;

    pii ans(INT_MAX,INT_MIN) ;
    for(int i=lg; i>=0; i--){
        if(dept[u]-(1<<i) >= dept[v]){
            ans.ff = min(ans.ff,mn[u][i]) ;
            ans.ss = max(ans.ss,mx[u][i]) ;
            u = par[u][i] ;
        }
    }

    if(u == v) return ans ;
    for(int i=lg; i>=0; i--){
        if(par[u][i]!=-1 && par[u][i] != par[v][i]){
            ans.ff = min(ans.ff,mn[u][i]) ;
            ans.ff = min(ans.ff,mn[v][i]) ;
            ans.ss = max(ans.ss,mx[u][i]) ;
            ans.ss = max(ans.ss,mx[v][i]) ;
            u = par[u][i] ;
            v = par[v][i] ;
        }
    }

    ans.ff = min(ans.ff,dis[u]) ;
    ans.ff = min(ans.ff,dis[v]) ;
    ans.ss = max(ans.ss,dis[u]) ;
    ans.ss = max(ans.ss,dis[v]) ;
    return ans ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ,cs=0 ;
    scanf("%d",&t) ;

    while(t--){
        reset() ;
        int n,q ;
        scanf("%d",&n) ;
        for(int i=0; i<n-1; i++){
            int u,v,w ;
            scanf("%d%d%d",&u,&v,&w) ;
            adj[u].pb(mk(v,w)) ;
            adj[v].pb(mk(u,w)) ;
        }
        build(n) ;
        printf("Case %d:\n",++cs) ;
        scanf("%d",&q) ;
        while(q--){
            int u,v ;
            scanf("%d%d",&u,&v) ;
            pii ans = query(u,v) ;
            printf("%d %d\n",ans.ff,ans.ss) ;
        }
    }

    return 0;
}



