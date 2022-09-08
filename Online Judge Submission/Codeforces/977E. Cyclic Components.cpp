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
const int lim = 2e5+5 ;

vector<int> adj[lim] ;
vector<bool> visited(lim) ;

void addEd(int u, int v){
    adj[u].pb(v) ;
    adj[v].pb(u) ;
}

bool dfs(int src){
    if(visited[src]) return true ;
    visited[src] = true ;
    bool ans = (adj[src].size() == 2) ? true : false ;
    for(auto &val: adj[src])
        ans = (ans & dfs(val)) ;
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

    int n,m ;
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u,v ;
        cin>> u >> v ;
        addEd(u,v) ;
    }

    int ans = 0 ;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(dfs(i)) ans++ ;
        }
    }

    cout<< ans << endl ;

    return 0;
}



