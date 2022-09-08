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
#define lim 200005

vector<int> adj[lim] ;
int p[lim] ;
bool vis[lim] ;
int node,dis ;

void DFS(int src, int cnt){
    vis[src] = true ;
    if(cnt >= dis){
        node = src ;
        dis = cnt ;
    }
    for(int v: adj[src]){
        if(!vis[v]){
            p[v] = src ;
            DFS(v,cnt+1) ;
        }
    }
}



//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,a,b,c;
    cin>> n ;

    for(int i=0; i<n-1; i++){
        int u,v ;
        cin>>u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }

    dis = -1 ;
    p[1] = -1 ;
    memset(vis,0,sizeof(vis)) ;
    DFS(1,0) ;
    a = node ;

    dis = -1 ;
    p[a] = -1 ;
    memset(vis,0,sizeof(vis)) ;
    DFS(a,0) ;
    b = node ;

    int ans = dis ;
    int temp = b ;
    memset(vis,0,sizeof(vis)) ;
    vis[a] = true ;
    vis[b] = true ;
    while(p[temp] != -1){
        vis[p[temp]] = true ;
        temp = p[temp] ;
    }

    dis = 0 ;
    temp = b ;
    while(p[temp] != -1){
        if(p[temp] == a || p[temp] == b){
            temp = p[temp] ;
            continue ;
        }
        DFS(p[temp],0) ;
        temp = p[temp] ;
    }

    c = node ;
    ans += dis ;

    cout<< ans << endl ;
    cout<<a<<" "<<b<<" "<<c << endl ;

    return 0;
}


