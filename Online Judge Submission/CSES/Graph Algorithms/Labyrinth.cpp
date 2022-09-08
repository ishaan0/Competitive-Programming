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
#define     Case                cout<< "Case "<< ++cs <<": "
#define     PI                  3.1415926535897932384
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
const double eps = 1e-9 ;

int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;/*
int const drH[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
int const dcH[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;
*/
const int lim = 1e3+5 ;

int n,m ;
vector<string> arr(lim) ;
int vis[lim][lim] ;
pii path[lim][lim] ;
pii src,des ;

char getDir(int ur,int uc,int vr,int vc){
    if(ur<vr) return 'D' ;
    if(ur>vr) return 'U' ;
    if(uc<vc) return 'R' ;
    if(uc>vc) return 'L' ;
}

void bfs(int sr,int sc){
    vis[sr][sc] = 0 ;
    queue<pii > q ;
    q.push(mp(sr,sc)) ;
    while(!q.empty()){
        pii tp = q.front() ;
        q.pop() ;
        int ur = tp.ff , uc = tp.ss ;

        for(int i=0; i<4; i++){
            int vr = ur + dr[i] ;
            int vc = uc + dc[i] ;
            if(vr<0||vc<0||vr>=n||vc>=m) continue ;
            if(vis[vr][vc]!=-1 || arr[vr][vc]=='#') continue ;
            if(arr[vr][vc] == 'B'){
                vis[vr][vc] = vis[ur][uc] + 1 ;
                path[vr][vc] = mp(ur,uc) ;
                return ;
            }
            vis[vr][vc] = vis[ur][uc]+1 ;
            path[vr][vc] = mp(ur,uc) ;
            q.push(mp(vr,vc)) ;
        }
    }
}

void getPath(int vr,int vc){
    if(vr==src.ff && vc==src.ss) return ;
    pii tp = path[vr][vc] ;
    getPath(tp.ff,tp.ss) ;
    cout<< getDir(tp.ff,tp.ss,vr,vc) ;
}


void solve(){
    memset(vis,-1,sizeof vis) ;
    cin>> n >> m ;
    for(int i=0; i<n; i++)
        cin>> arr[i] ;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'A')
                src = mp(i,j) ;
            if(arr[i][j] == 'B')
                des = mp(i,j) ;
        }
    }

    bfs(src.ff,src.ss) ;
    if(vis[des.ff][des.ss]!=-1){
        cout<< "YES" << endl ;
        cout<< vis[des.ff][des.ss] <<endl ;
        getPath(des.ff,des.ss) ;
        cout<< endl ;
    }
    else cout<< "NO" << endl ;

}


int main()
{
    Boost;

    int t = 1,cs = 0 ;
    //cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}

