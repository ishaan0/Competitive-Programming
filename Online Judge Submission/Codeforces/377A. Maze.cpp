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
#define     Case                printf("Case %d: ",++cs)
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

int n,m,k;
vector<string> str ;
bool vis[505][505] ;
int dr[4] = {0,0,1,-1} ;
int dc[4] = {1,-1,0,0} ;


int dfs(int ur,int uc){
    vis[ur][uc] = true ;
    int dec = 0 ;
    for(int i=0; i<4; i++){
        int vr = ur + dr[i] ;
        int vc = uc + dc[i] ;
        if(vr<0 || vr>=n || vc<0 || vc>=m) continue ;
        if(str[vr][vc] == '#' || vis[vr][vc]) continue ;
        dec += dfs(vr,vc) ;
    }
    if(dec == 0 && k>0){
        str[ur][uc] = 'X';
        k-- ;
    }
    else dec++ ;
    return dec ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif


    cin>> n >> m >> k;
    for(int i=0; i<n; i++){
        string temp ;
        cin>> temp ;
        str.pb(temp) ;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(str[i][j] == '.' && !vis[i][j])
                dfs(i,j) ;
        }
    }

    for(int i=0; i<n; i++)
        cout<< str[i] << endl ;


    return 0;
}


