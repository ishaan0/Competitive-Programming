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

int const lim = 1e5+5 ;
bool mark[lim] ;
int vis[lim] ;
vector<int> primes ;
vector<int> adj[lim] ;

void sieve(){
    for(ll i=4; i<lim; i+=2) mark[i] = true ;
    for(ll i=3; i<lim; i+=2){
        if(!mark[i]){
            for(ll j=i*i; j<lim; j+=2*i)
                mark[j] = true ;
        }
    }
    for(ll i=1000; i<=9999; i++)
        if(!mark[i]) primes.pb(i) ;
}

bool isValid(int a, int b){
    int cnt = 0 ;
    while(a!=0){
        if((a%10) != (b%10)) cnt++ ;
        a /= 10 ;
        b /= 10 ;
    }
    return cnt == 1 ;
}

void build(){
    for(int i=0; i<primes.size(); i++){
        for(int j=0; j<primes.size(); j++){
            if(isValid(primes[i],primes[j])){
                adj[primes[i]].pb(primes[j]) ;
                adj[primes[j]].pb(primes[i]) ;
            }
        }
    }
}

int bfs(int src,int dest){
    queue<int> q ;
    q.push(src) ;
    vis[src] = 0 ;

    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;
        for(int v: adj[u]){
            if(vis[v] == -1){
                vis[v] = vis[u] + 1 ;
                q.push(v) ;
            }
            if(v == dest) return vis[v] ;
        }
    }
    return -1 ;
}

void solve(){
    memset(vis,-1,sizeof vis) ;
    int n,m ;
    cin>> n >> m ;
    int ans = bfs(n,m) ;
    if(ans == -1) cout<< "Impossible" << endl ;
    else cout<< ans << endl ;
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
    cin>> t ;
    sieve() ;
    build() ;
    while(t--){
        //Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}

