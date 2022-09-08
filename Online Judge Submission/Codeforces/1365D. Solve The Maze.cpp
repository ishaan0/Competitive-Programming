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

vector<string> grid(55) ;
int dr[] = {-1,0,0,1} ;
int dc[] = {0,-1,1,0} ;
int n,m ;
bool vis[55][55] ;

int dfs(int ur,int uc){
    int g = 0 ;
    vis[ur][uc] = true ;
    if(grid[ur][uc] == '#') return 0 ;

    for(int i=0; i<4; i++){
        int vr = dr[i] + ur ;
        int vc = dc[i] + uc ;
        if(vr<0||vc<0||vr>=n||vc>=m) continue ;
        if(vis[vr][vc]) continue ;
        g += dfs(vr,vc) ;
    }

    if(grid[ur][uc] == 'G') g++ ;
    return g ;
}

void reset(){
    grid.clear() ;
    grid.resize(55) ;
    memset(vis,0,sizeof vis) ;
}

void solve(){
    reset() ;
    int g = 0 ;
    cin>> n >> m ;
    for(int i=0; i<n; i++)
        cin>> grid[i] ;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j] == 'G') g++ ;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'B'){
                for(int k=0; k<4; k++){
                    int vr = dr[k] + i ;
                    int vc = dc[k] + j ;
                    if(vr<0||vc<0||vr>=n||vc>=m) continue ;
                    if(grid[vr][vc] != 'B')
                        grid[vr][vc] = '#' ;
                }
            }
        }
    }

    int ans = dfs(n-1,m-1) ;

    if(ans == g)
        cout<< "Yes" << endl ;
    else cout<< "No" << endl ;
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

    while(t--){
        //Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}


