#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs <<": "
#define     PI                  3.1415926535897932384
#define     eps                 1e-9
#define     inf                 LLONG_MIN
#define     INF                 LLONG_MAX
#define     mp                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

/** Debugging Tool **/
TS void show(const T& v) {    cerr << v << ' ' ;}
TM void show(const T1& first,const T2&... rest){show(first);show(rest...);}
TP ostream& operator<<(ostream& os,const pair<F,S>& p){return os<<"("<<p.ff<<", "<<p.ss<<")";}
TS ostream& operator<<(ostream& os,const vector<T>& v){os << "{"; typename vector< T >::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if( it != v.begin() )os<<", ";os<<*it;}return os<<"}";}
TS ostream& operator<<(ostream& os,const set<T>& v){os<<"[";typename set<T>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
TP ostream& operator<<(ostream& os,const map<F,S>& v){os<<"[";typename map<F,S>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<it->ff<<" = "<<it->ss;}return os<<"]";}
/** Ends **/

int const lim = 1e5+5 ;
ll const mod = 1e9+7 ;

vector<int> adj[lim],rev[lim] ;
bool vis[lim] ;
int n,m,mn,cnt,cost[lim] ;
stack<int> ordered ;

void dfs1(int u){
    if(vis[u]) return ;
    vis[u] = true ;
    for(int v: adj[u])
        dfs1(v) ;
    ordered.push(u) ;
}

void dfs2(int u){
    if(vis[u]) return  ;
    vis[u] = true ;
    for(int v: rev[u])
        dfs2(v) ;
    if(cost[u] < mn){
        mn = cost[u] ;
        cnt = 1 ;
    }
    else if(cost[u] == mn)
        cnt++ ;
}

void solve(){
    cin>> n ;
    for(int i=1; i<=n; i++)
        cin>> cost[i] ;
    cin>> m ;
    for(int i=1; i<=m; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        rev[v].pb(u) ;
    }

    memset(vis,0,sizeof vis) ;
    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs1(i) ;

    ll ans = 0, way = 1 ;
    memset(vis,0,sizeof vis) ;
    while(!ordered.empty()){
        int u = ordered.top() ;
        ordered.pop() ;
        mn = INT_MAX ;
        cnt = 0 ;
        if(!vis[u]){
            dfs2(u) ;
            ans += mn ;
            if(cnt>1)
            way = (way*cnt)%mod ;
        }
    }

    cout<< ans << " " << way << endl ;
}


int main()
{
    Boost;

    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t = 1,cs = 0 ;
    //cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}


