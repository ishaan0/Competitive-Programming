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

#define lim 10005

vector<pii > adj[lim] ;
int dept[lim],temp[lim] ;
int par[lim][17] ;
ll dis[lim] ;

void dfs(int u,int from,int cnt){
    temp[u] = from ;
    dept[u] = cnt ;
    for(pii v: adj[u])
    if(v.ff != from){
        dis[v.ff] = dis[u] + (ll)v.ss ;
        dfs(v.ff,u,cnt+1) ;
    }
}

void build(int n){
    dfs(1,-1,0) ;
    for(int i=1; i<=n; i++)
        par[i][0] = temp[i] ;

    for(int j=1; (1<<j)<n; j++){
        for(int i=1; i<=n; i++)
            if(par[i][j-1] != -1)
                par[i][j] = par[ par[i][j-1] ][j-1] ;
    }
}

int lca(int u,int v){
    if(dept[u] < dept[v])
        swap(u,v) ;
    int lg=1 ;
    while((1<<(lg+1)) <= dept[u])
        lg++ ;
    for(int i=lg; i>=0; i--){
        if(dept[u]-(1<<i) >= dept[v])
            u = par[u][i] ;
    }

    if(u == v) return u ;

    for(int i=lg ; i>=0; i--){
        if(par[u][i] != -1 && par[u][i] != par[v][i]){
            u = par[u][i] ;
            v = par[v][i] ;
        }
    }
    return temp[u] ;
}

ll getDis(int u,int v){
    int a = lca(u,v) ;
    ll sum = dis[u] + dis[v] - (2*dis[a]) ;
    return sum ;
}

int getKth(int u,int v,int k){
    int a = lca(u,v) ;
    if(u == a){
        int d = dept[v]-dept[u]+1 ;
        k = d-k+1 ;
        swap(u,v) ;
    }
    else if(v != a && k > (dept[u]-dept[a]+1)){
        int d = dept[u]+dept[v]-(2*dept[a])+1 ;
        k = d-k+1 ;
        swap(u,v) ;
    }

    int lg= 1 ;
    while((1<<(lg+1)) <= dept[u])
        lg++ ;
    k-- ;

    for(int i=lg; i>=0; i--){
        if((1<<i) <= k){
            u = par[u][i] ;
            k -= (1<<i) ;
        }
    }
    return u ;
}

void reset(){
    for(int i=0; i<lim; i++){
        adj[i].clear() ;
        temp[i] = -1 ;
        dept[i] = -1 ;
        dis[i] = 0 ;
    }
    memset(par,-1,sizeof par) ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>> t ;

    while(t--){
        reset() ;
        int  n ;
        string str ;
        cin>> n ;
        for(int i=0; i<n-1; i++){
            int u,v ,w ;
            cin>>u >> v >> w;
            adj[u].pb(mk(v,w)) ;
            temp[v] = u ;
        }
        build(n) ;
        while(true){
            cin>> str ;
            if(str == "DONE") break ;
            ll ans = 0 ;
            if(str == "DIST"){
                int u,v ;
                cin>> u >> v ;
                ans = getDis(u,v) ;
            }
            else if(str == "KTH"){
                int u,v,k ;
                cin>> u >> v >> k ;
                ans = getKth(u,v,k) ;
            }
            cout<< ans << endl << endl ;
        }
    }

    return 0;
}




