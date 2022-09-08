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

#define lim 1005

vector<int> adj[lim] ;
int level[lim],temp[lim] ;
int par[lim][20] ;
int n ;

void reset(){
    for(int i=0; i<n; i++){
        adj[i].clear() ;
        level[i] = -1 ;
        temp[i] = -1 ;
    }
    memset(par,-1,sizeof par) ;
}

void dfs(int from,int u,int cnt){
    level[u] = cnt ;
    temp[u] = from ;
    for(int v: adj[u])
        if(v != from) dfs(u,v,cnt+1) ;
}

void build(){
    dfs(-1,1,0) ;
    for(int i=1; i<=n; i++)
        par[i][0] = temp[i] ;
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i<=n; i++){
            if(par[i][j-1] != -1)
                par[i][j] = par[ par[i][j-1] ][j-1] ;
        }
    }
}

int lca(int u,int v){
    if(level[u] < level[v])
        swap(u,v) ;
    int lg = log2(level[u]) ;

    for(int i=lg; i>=0; i--)
        if(level[u]-(1<<i) >= level[v])
            u = par[u][i] ;
    if(u == v) return u ;

    for(int i=lg; i>=0; i--){
        if(par[u][i] != -1 && par[u][i] != par[v][i]){
            u = par[u][i] ;
            v = par[v][i] ;
        }
    }

    return temp[u] ;
}


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0;
    cin>> t ;

    while(t--){
        reset() ;
        cin>> n ;
        for(int i=1; i<=n; i++){
            int cnt ;
            cin>> cnt ;
            while(cnt--){
                int v ;
                cin>> v ;
                adj[i].pb(v) ;
            }
        }
        build() ;
        int q ;
        cin>> q ;
        cout<< "Case " << ++cs << ":" << endl ;
        while(q--){
            int u,v ;
            cin>> u>> v ;
            int ans = lca(u,v) ;
            cout<< ans << endl ;
        }
    }


    return 0;
}





