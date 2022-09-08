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

int const lim = 2e5+5 ;

struct triple{
    ll cost,zero,one ;
    triple(){cost=zero=one=0;}
};

int n ;
vector<int> adj[lim] ;
triple node[lim] ;
ll minL[lim] ;

triple dfs(ll u,ll par,ll prev){
    minL[u] = min(node[u].cost,prev) ;
    triple cur ;
    for(int v: adj[u]){
        if(v == par) continue ;
        triple temp = dfs(v,u,minL[u]) ;
        cur.cost += temp.cost ;
        cur.zero += temp.zero ;
        cur.one += temp.one ;
    }
    cur.one += node[u].one ;
    cur.zero += node[u].zero ;
    ll mn = min(cur.one,cur.zero) ;
    cur.one -= mn ;
    cur.zero -= mn ;
    cur.cost += (minL[u]*2LL*mn) ;
    return cur ;
}


void solve(){
    int zero=0,one=0 ;
    cin>> n ;
    for(int i=1; i<=n; i++){
        ll a,b,c ;
        cin>> a >> b >> c ;
        node[i].cost = a ;
        if(b==c) continue ;
        if(b==0) node[i].zero = 1,zero++ ;
        else node[i].one = 1,one++ ;
    }

    for(int i=0; i<n-1; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }

    if(zero != one){
        cout<< "-1" << endl ;
        return ;
    }

    triple ans = dfs(1,-1,INT_MAX) ;
    cout<< ans.cost << endl ;
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


