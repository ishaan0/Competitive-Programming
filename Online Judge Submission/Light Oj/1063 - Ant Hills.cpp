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
vector<int> adj[lim] ;
bool vis[lim],used[lim];
int disc[lim],low[lim],par[lim];
int tt,arti;

void articulation(int u){
    vis[u] = true ;
    disc[u] = low[u] = ++tt ;
    int child = 0 ;

    for(int v: adj[u]){
        if(!vis[v]){
            par[v] = u ;
            child++ ;
            articulation(v) ;

            low[u] = min(low[v],low[u]) ;
            if(par[u] == -1 && child>1 && !used[u])
                arti++,used[u]=true ;
            if(par[u] != -1 && low[v] >= disc[u] && !used[u])
                arti++,used[u]=true ;
        }
        else if(par[u] != v)
            low[u] = min(low[u],disc[v]) ;
    }
}

void init(){
    for(int i=0; i<lim; i++){
        adj[i].clear() ;
        vis[i] = 0 ;
        disc[i] = 0 ;
        par[i]  = -1 ;
        low[i] = 0 ;
        used[i] = 0 ;
    }
    arti = 0 ;
    tt=0 ;
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
    cin>> t ;

    while(t--){
        int n,m ;
        cin>> n >>m ;
        init() ;
        for(int i=0; i<m; i++){
            int u,v ;
            cin>> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
        }

        for(int i=1; i<=n; i++)
            if(!vis[i])
                articulation(i) ;
        Case ;
        cout<< arti << endl ;

    }

    return 0;
}


