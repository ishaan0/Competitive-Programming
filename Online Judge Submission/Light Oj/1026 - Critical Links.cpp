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
bool vis[lim], used[lim] ;
vector<pii > arti ;
int disc[lim],low[lim],par[lim],tt ;

void articulation(int u){
    vis[u] = true ;
    disc[u] = low[u] = ++tt ;

    for(int v: adj[u]){
        if(!vis[v]){
            par[v] = u ;
            articulation(v) ;

            low[u] = min(low[u],low[v]) ;
            if(low[v] > disc[u]){
                int uu=u ;
                int vv=v ;
                if(uu>vv) swap(uu,vv) ;
                arti.pb(mk(uu,vv)) ;
            }
        }
        else if(v != par[u])
            low[u] = min(low[u],disc[v]) ;
    }
}

void init(){
    for(int i=0; i<lim; i++){
        adj[i].clear() ;
        vis[i] = 0 ;
        par[i] = -1 ;
        disc[i] = 0 ;
        low[i] = 0 ;
        used[i] = 0 ;
    }
    arti.clear() ;
    tt = 0 ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0 ;
    scanf("%d",&t) ;

    while(t--){
        int n ;
        scanf("%d",&n) ;
        init() ;
        for(int i=0; i<n; i++){
            int u,k ;
            scanf("%d (%d) ",&u,&k) ;
            used[u] = true ;
            for(int j=0; j<k; j++){
                int temp ;
                scanf("%d",&temp) ;
                adj[u].pb(temp) ;
                //adj[temp].pb(u) ;
                used[temp] = true ;
            }
        }

        for(int i=0; i<lim; i++){
            if(used[i] && !vis[i])
                articulation(i) ;
        }

        int sz = arti.size() ;
        printf("Case %d:\n",++cs) ;
        printf("%d critical links\n",sz) ;

        sort(all(arti)) ;
        foreach(arti)
            printf("%d - %d\n",value.ff , value.ss) ;

    }

    return 0;
}

