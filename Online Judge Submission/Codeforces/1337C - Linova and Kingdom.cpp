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
#define     ed                  "\n"

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;
const int lim = 2e5+5 ;

int n,k ;
vector<int> adj[lim] ;
vector<int> des[lim] ;

int dfs(int from,int u,int lvl){
    int sum = 0 ;
    for(int v: adj[u]){
        if(v != from)
            sum += dfs(u,v,lvl+1) ;
    }
    des[lvl].pb(sum) ;
    return sum+1 ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif


    cin>> n >> k ;

    for(int i=0; i<n-1; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }

    dfs(0,1,0) ;
    ll sum = 0 ;
    vector<ll> ans ;
    for(int i=n; i>=1; i--){
        for(int j=0; j<des[i].size(); j++){
            ll temp = (ll)i - des[i][j] ;
            ans.pb(temp) ;
        }
    }

    sort(rall(ans)) ;
    for(int i=0; i<k; i++)
        sum += ans[i] ;

    cout<< sum << endl ;

    return 0;
}


