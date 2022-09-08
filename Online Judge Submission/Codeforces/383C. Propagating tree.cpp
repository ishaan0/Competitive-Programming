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
#define     Case                cout<< "Case "<< ++cs << ": "
#define     inf                 LONG_LONG_MIN
#define     INF                 LONG_LONG_MAX
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

/// NOT Solved ...

ll const lim = 2e5+5 ;

vector<int> adj[lim] ;
int level[lim],arr[lim] ;
pair<ll,ll> tree[4*lim] ;

void dfs(int from,int u,int lvl){
    level[u] = lvl ;
    for(int v; adj[u])
        if(v != from) dfs(u,v,lvl+1) ;
}

void update(int node,int lo,int hi,int qi,int qj,int val){
    if(qj<lo || qi>hi) return ;
    else if(qi<=lo && hi<=qj){
        tree[node].ff += (hi-lo+1)*val ;
        tree[node].ss += val ;
    }
    int mid = lo+(hi-lo)/2 ;
    update(2*node,lo,mid,qi,qj,val) ;
    update(2*node+1,mid+1,hi,qi,qj,val) ;
    tree[node].ff = tree[2*node].ff + tree[2*node+1].ff + (hi-lo+1)*tree[node].ss ;
}

ll query(int node,int lo,int hi,int qi,int qj,int carry=0){
    if(qj<lo || qi>hi) return ;
    else if(qi<=lo && hi<=qj)
        return tree[node].ff+(hi-lo+1)*carry ;
    int mid = lo+(hi-lo)/2 ;
    ll lft = query(2*node,lo,mid,qi,qj,tree[node].ss+val) ;
    ll rgt = query(2*node+1,mid+1,hi,qi,qj,tree[node].ss+val) ;
    return lft+rgt ;
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
    for(int i=1; i<=n; i++)
        cin>> arr[i] ;
    for(int i=1; i<n; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }
    dfs(0,1,1) ;
    int mx = -1 ;
    for(int i=0; i<lim; i++)
        mx = max(mx,level[i]) ;
    while(m--){
        int chk,x,val ;
        cin>> chk ;
        if(chk == 1){
            cin>> x >> val ;
            lvl = level[x] ;
            int lo=lvl+1,hi = mx ;
            lo = min(lo,mx) ;

        }
        else{
            cin>> x ;

        }
    }


    return 0;
}

