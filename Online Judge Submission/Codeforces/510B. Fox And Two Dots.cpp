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

int n,m ;
int dr[4] = {0,0,1,-1} ;
int dc[4] = {1,-1,0,0} ;
int vis[55][55];
vector<string> str(55) ;
bool flag ;

void dfs(int ur,int uc,int pr,int pc){
    vis[ur][uc] = 1 ;
    for(int i=0; i<4; i++){
        int vr = ur+dr[i], vc = uc+dc[i] ;
        if(vr<0 || vc<0 || vr>n || vc>m) continue ;
        if(str[ur][uc] != str[vr][vc]) continue ;
        if(vr==pr && vc==pc) continue ;
        if(vis[vr][vc] == 2) continue ;
        if(vis[vr][vc] == 1) flag = true ;
        else dfs(vr,vc,ur,uc) ;
    }
    vis[ur][uc] = 2 ;
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    cin>> n >> m ;
    for(int i=0; i<n; i++)
        cin>> str[i] ;
    flag = false ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] == 0) dfs(i,j,i,j) ;
            if(flag) return cout<< "Yes" << endl ,0 ;
        }
    }

    cout<< "No" << endl ;

    return 0;
}


