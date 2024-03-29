#include<bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;
*/

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     memz(cont)          memset(cont, 0, sizeof cont)
#define     memn(cont)          memset(cont, -1, sizeof cont)
#define     Case                cout<< "Case "<< ++cs <<": "
#define     PI                  3.1415926535897932384
#define     pf                  printf
#define     sf                  scanf
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

const double eps = 1e-9 ;
/*
int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
int const drH[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
int const dcH[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;
*/
const int lim = 2e5+5 ;
int n,m,cnt ;
vector<int> adj[lim], arr ;

void bfs(){
    vector<int> inDegree(n+1) ;

    for(int i=1; i<=n; i++){
        for(int v: adj[i]){
            inDegree[v]++ ;
        }
    }

    queue<int> q;
    for(int i=1; i<=n; i++)
        if(inDegree[i] == 0)
            q.push(i) ;

    cnt = 0 ;
    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;
        arr.pb(u) ;
        for(int v: adj[u]){
            inDegree[v]-- ;
            if(inDegree[v] == 0)
                q.push(v) ;
        }
        cnt++ ;
    }
}


void reset(){
    for(int i=0; i<lim; i++)
        adj[i].clear() ;
    arr.clear() ;
}

void solve(){
    reset() ;
    sf("%d%d",&n,&m) ;
    vector<pii > ans ;

    for(int i=0; i<m; i++){
        int type,u,v ;
        sf("%d%d%d",&type,&u,&v) ;
        ans.pb(mp(u,v)) ;
        if(type) adj[u].pb(v) ;
    }

    bfs() ;
    if(cnt < n){
        pf("NO\n") ;
        return ;
    }

    pf("YES\n") ;

    
    vector<int> order(n+1,-1) ;

    for(int i=0; i<n; i++)
        order[ arr[i] ] = i ;
    

    foreach(ans){
        int u = val.ff, v = val.ss ;
        if(order[u] > order[v])
            swap(u,v) ;
        pf("%d %d\n",u,v) ;
    }
}


int main()
{
    //Boost;

    int t = 1,cs = 0 ;
    sf("%d",&t) ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}

