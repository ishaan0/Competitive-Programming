#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;


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
#define     Case                printf("Case %d: ",++cs)
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
typedef     pair <ll , ll >             pll ;

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

int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;/*
int const drH[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
int const dcH[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;
*/

const int lim = 1e3+5 ;

vector<string> grid(lim) ;
vector<pii > mons ;
int dis1[lim][lim], dis2[lim][lim], n, m ;
pii par[lim][lim] ;
bool vis[lim][lim] ;

void bfs1(){
    memz(vis) ;
    queue<pii > q ;
    foreach(mons){
        q.push({val.ff,val.ss})  ;
        vis[val.ff][val.ss] = 1 ;
        dis1[val.ff][val.ss] = 0 ;
    }

    while(!q.empty()){
        pii tt = q.front() ;
        q.pop() ;
        int ur = tt.ff, uc = tt.ss ;

        for(int i=0; i<4; i++){
            int vr = dr[i] + ur ;
            int vc = dc[i] + uc ;
            if(vr<0||vr>=n||vc<0||vc>=m) continue ;
            
            if(vis[vr][vc] || grid[vr][vc]=='#'||dis1[vr][vc] <= (dis1[ur][uc]+1))
                continue ;
            
            vis[vr][vc] = 1 ;
            dis1[vr][vc] = min(dis1[vr][vc], dis1[ur][uc] + 1) ;
            q.push({vr,vc}) ;
        }
    }
}

char getDir(int ur,int uc,int vr,int vc){
    if(ur != vr){
        if(ur > vr) return 'U' ;
        else return 'D' ;
    }
    else{
        if(uc > vc) return 'L' ;
        else return 'R' ;
    }
}

void bfs2(int sr,int sc){
    memz(vis) ;
    queue<pii > q ;
    q.push({sr,sc}) ;
    vis[sr][sc] = 1 ;
    dis2[sr][sc] = 0 ;
    if(sr==0||sr==n-1||sc==0||sc==m-1){
        cout<< "YES\n0\n" ;
        exit(0) ;
    }

    while(!q.empty()){
        pii tt = q.front() ;
        q.pop() ;
        int ur = tt.ff, uc = tt.ss ;

        for(int i=0; i<4; i++){
            int vr = dr[i] + ur ;
            int vc = dc[i] + uc ;

            if(vr<0||vr>=n||vc<0||vc>=m) continue ;
            if(vis[vr][vc] || grid[vr][vc]=='#'||dis1[vr][vc]<=dis2[ur][uc]+1)
                continue ;

            par[vr][vc] = mp(ur,uc) ;
            if(vr==0||vr==n-1||vc==0||vc==m-1){
                int xr = vr, xc = vc ;
                vector<char> temp ;
                while(xr != sr || xc != sc){
                    pii val = par[xr][xc] ;
                    temp.pb(getDir(val.ff,val.ss,xr,xc)) ;
                    xr = val.ff , xc = val.ss ;
                }
                reverse(all(temp)) ;
                cout<< "YES\n" << temp.size() << "\n" ; 
                foreach(temp) cout<< val ;
                cout<< "\n" ;
                exit(0) ;
            }

            vis[vr][vc] = 1 ;
            dis2[vr][vc] = dis2[ur][uc] + 1 ;
            q.push({vr,vc}) ;
        }
    }

}



int solve(){
    int r,c ;
    cin>> n >> m  ;

    for(int i=0; i<n; i++) cin>> grid[i] ;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] != 'M')
                dis1[i][j] = 1e9 ;
            if(grid[i][j] == 'A'){ r = i, c = j ; }
            if(grid[i][j] == 'M') mons.pb({i,j}) ;
        }
    }
    
    bfs1() ;
    bfs2(r,c) ;
    
    cout<< "NO\n" ;

    return 0 ;
}


int main()
{
    Boost ;
    int t = 1,cs = 0 ;
    //sf("%d",&t) ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}