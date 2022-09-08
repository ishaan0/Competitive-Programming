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
vector<int> d1,dn ;
int n,m,k ;

void bfs(int src,vector<int>& d){
    d.resize(n+1) ;
    foreach(d)
        value = INT_MAX ;
    queue<int> q ;
    d[src] = 0 ;
    q.push(src) ;

    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;
        for(int v: adj[u]){
            if(d[v] == INT_MAX){
                d[v] = d[u] + 1 ;
                q.push(v) ;
            }
        }
    }
}


bool cmp(int u,int v){
    return (d1[u] + dn[v]) < (d1[v] + dn[u]) ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif


    cin>> n >> m>> k ;
    unordered_set<int> s ;
    vector<int> arr(k) ;
    foreach(arr){
        cin>> value ;
        s.insert(value) ;
    }

    bool flag = false ;
    for(int i=0; i<m; i++){
        int u,v ;
        cin>> u >> v ;
        if(s.count(u) && s.count(v)) flag = true ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }


    bfs(1,d1) ;
    if(flag){
        cout<< d1[n] << endl ;
        return 0;
    }
    bfs(n,dn) ;
    sort(all(arr),cmp) ;

    int ans = 0, mxd1 = -1e9 ;
    foreach(arr){
        ans = max(ans,dn[value]+mxd1+1) ;
        mxd1 = max(mxd1,d1[value]) ;
    }

    ans = min(ans,d1[n]) ;
    cout<< ans << endl ;

    return 0;
}


