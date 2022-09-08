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

vector<pii> adj[105] ;
vector<bool> visited(105) ;
bool found ;

void dfs(int src, int dest, int col){
    if(src == dest){
        found = true ;
        return ;
    }
    visited[src] = true ;
    for(auto &val: adj[src]){
        pii node = val ;
        if(!visited[node.ff] && node.ss == col && !found)
            dfs(node.ff,dest,col) ;
    }
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n ,m ;
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int a,b,c ;
        cin>> a >>b >>c ;
        adj[a].pb(mk(b,c)) ;
        adj[b].pb(mk(a,c)) ;
    }

    int q ;
    cin>> q ;

    for(int i=0; i<q; i++){
        int u,v ;
        cin>> u >> v ;
        int ans = 0 ;
        for(int j=1; j<=m; j++){
            found = false ;
            visited.clear() ;
            visited.resize(105) ;
            dfs(u,v,j) ;
            if(found) ans++ ;
        }

        cout<< ans << endl ;
    }

    return 0;
}



