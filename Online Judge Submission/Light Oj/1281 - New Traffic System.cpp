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

int const lim =  1e4+5 ;
int n,m,k,d ;

struct edge{
    int v,w,p ;
    edge(int vv,int ww,int pp){v=vv,w=ww,p=pp; }
};

struct node{
    int x,cost,used ;
    node(int xx,int cc,int uu){x=xx, cost=cc,used=uu ; }
    node(){ }
    bool operator < (node const &ob)const{
        return this->cost > ob.cost ;
    }
};

vector<edge> adj[lim] ;
int dis[lim][11] ;

int dijstra(){
    priority_queue<node> pq ;
    pq.push(node(0,0,0)) ;
    dis[0][0] = 0 ;
    while(!pq.empty()){
        node u = pq.top() ;
        pq.pop() ;
        if(u.cost != dis[u.x][u.used]) continue ;
        if(u.x == n-1) return u.cost ;
        for(int i=0; i<adj[u.x].size(); i++){
           node v ;
           v.x = adj[u.x][i].v ;
           v.cost = adj[u.x][i].w + u.cost ;
           v.used = adj[u.x][i].p + u.used ;

           if(v.used <= d && v.cost < dis[v.x][v.used]){
                dis[v.x][v.used] = v.cost ;
                pq.push(v) ;
           }
        }
    }
    return -1 ;
}

void reset(){
    for(int i=0; i<lim; i++){
        adj[i].clear() ;
        for(int j=0; j<11; j++) dis[i][j] = INT_MAX ;
    }
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
    scanf("%d",&t) ;

    while(t--){
        reset() ;
        scanf("%d%d%d%d",&n,&m,&k,&d) ;
        for(int i=0; i<m; i++){
            int u,v,w ;
            scanf("%d%d%d",&u,&v,&w) ;
            adj[u].pb(edge(v,w,0)) ;
        }
        for(int i=0; i<k; i++){
            int u,v,w ;
            scanf("%d%d%d",&u,&v,&w) ;
            adj[u].pb(edge(v,w,1)) ;
        }

        int ans = dijstra() ;
        if(ans != -1) printf("Case %d: %d\n",++cs,ans) ;
        else printf("Case %d: Impossible\n",++cs) ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}


