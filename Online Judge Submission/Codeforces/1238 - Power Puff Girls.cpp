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

vector<string> str(22) ;
int n,m,vis[22][22] ;

void bfs(int sr,int sc){
    queue<pii > q ;
    vis[sr][sc] = 0 ;
    q.push({sr,sc}) ;
    
    while(!q.empty()){
        pii temp = q.front() ;
        q.pop() ;
        int ur = temp.ff, uc = temp.ss ;
        for(int i=0; i<4; i++){
            int vr = ur + dr[i], vc = uc + dc[i] ;
            if(vr<0||vr>=n||vc<0||vc>=m) continue ;
            if(vis[vr][vc]!=0 || str[vr][vc]=='m' || str[vr][vc]=='#')
                continue ;
            vis[vr][vc] = vis[ur][uc] + 1 ;
            q.push({vr,vc}) ;
        }
    }
}

int solve(){
    memz(vis) ;
    cin>> n >> m ;
    for(int i=0; i<n; i++) cin>> str[i] ;
    vector<pii > arr ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(str[i][j]=='a'||str[i][j]=='b'||str[i][j]=='c')
                arr.pb({i,j}) ;
            else if(str[i][j]=='h') bfs(i,j) ;
        }
    } 
    
    int ans = 0 ;
    foreach(arr) ans = max(ans, vis[val.ff][val.ss]) ;

    cout<< ans << "\n" ;

    return 0 ;
}


int main()
{
    //Boost ;
    int t = 1,cs = 0 ;
    //sf("%d",&t) ;
    cin>> t ;
    while(t--){
        cout<< "Case " << ++cs << ": " ;
        //Case ;
        solve() ;
    }

    return 0;
}