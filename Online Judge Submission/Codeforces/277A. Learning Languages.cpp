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

vector<int> p,r ;
void init(int n){
    p.resize(n+5) ;
    r.resize(n+5) ;
    for(int i=0; i<n+3; i++){
        p[i] = i ;
        r[i] = 1 ;
    }
}


int findP(int n){
    if(p[n] == n) return n ;
    return p[n] = findP(p[n]) ;
}

void setUnion(int u, int v){
    int x = findP(u) ;
    int y = findP(v) ;

    if(x==y) return ;
    if(r[x] > r[y])
        p[y] = p[x] ;
    else if(r[y] > r[x])
        p[x] = p[y] ;
    else{
        p[y] = p[x] ;
        r[x]++ ;
    }
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,m,z=0 ;
    cin>> n >> m ;
    init(n) ;
    vector<int> adj[m+5] ;
    for(int i=0; i<n; i++){
        int cnt ;
        cin>> cnt ;
        if(cnt==0) z++ ;
        for(int j=0; j<cnt; j++){
            int temp ;
            cin>> temp ;
            adj[temp].pb(i) ;
        }
    }

    if(z==n)
        return cout<< n << endl, 0 ;

    for(int i=1; i<=m; i++){
        int lim= adj[i].size() ;
        lim-- ;
        for(int j=0; j<lim; j++)
            setUnion(adj[i][j],adj[i][j+1]) ;
    }

    set<int> grp ;
    for(int i=0; i<n; i++)
        grp.insert(findP(i)) ;

    cout<< grp.size()-1 << endl ;


    return 0;
}


