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

vector<int> adj[100005] ;
stack<int> ans ;
bool vis[100005] ;
int v,e ;

void DFS(int src){
    if(vis[src]) return  ;
    vis[src] = true ;
    for(int node: adj[src])
        DFS(node) ;
    ans.push(src) ;
}

void dfs2(int src){
    if(vis[src]) return  ;
    vis[src] = true ;
    for(int node: adj[src])
        dfs2(node) ;
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
    cin>>t ;

    while(t--){
        cin>> v >> e ;
        for(int i=0; i<e; i++){
            int x,y ;
            cin>> x>> y ;
            adj[x].pb(y) ;
        }

        memset(vis, 0, sizeof(vis)) ;
        int cnt = 0 ;
        for(int i=1; i<=v; i++){
            if(!vis[i])
                DFS(i);
        }

        memset(vis, 0 , sizeof(vis)) ;
        while(!ans.empty()){
            int node = ans.top() ;
            ans.pop() ;
            if(!vis[node]){
                cnt++ ;
                dfs2(node) ;
            }
        }

        cout<< cnt << endl ;
        for(int i=0; i<100005; i++)
            adj[i].clear() ;
    }


    return 0;
}


