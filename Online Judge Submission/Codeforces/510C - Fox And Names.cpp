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


vector<int> adj[26] ;
stack<int> stk ;
int vis[105] ;

void func(string prev,string cur){
    for(int i=0; i<prev.size(); i++){
        if(i==cur.size()){
            cout<< "Impossible" << endl ;
            exit(0) ;
        }
        if(cur[i] != prev[i]){
            int u = prev[i]-'a' ;
            int v = cur[i]-'a' ;
            adj[u].pb(v) ;
            return ;
        }
    }
}

void dfs(int u){
    vis[u] = 1 ;
    for(int v: adj[u]){
        if(vis[v] == 1){
            cout<< "Impossible" << endl ;
            exit(0) ;
        }
        else if(vis[v] == 2) continue ;
        dfs(v) ;
    }
    vis[u] = 2 ;
    stk.push(u) ;
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n ;
    cin>> n ;

    string prev ,cur ;
    cin>> prev ;
    for(int i=1; i<n; i++){
        cin>> cur ;
        func(prev,cur) ;
        prev = cur ;
    }

    memset(vis,0,sizeof vis) ;
    for(int i=0; i<26; i++)
        if(vis[i]==0) dfs(i) ;

    while(!stk.empty()){
        char ch = (char)stk.top() + 'a' ;
        cout<< ch ;
        stk.pop() ;
    }
    cout<< endl ;

    return 0;
}


