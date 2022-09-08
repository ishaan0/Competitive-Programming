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



//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,k ;
    cin>> n >> k ;

    vector<int> level[n+1],deg(n) ;
    ll mx = -1 ;
    for(int i=0; i<n; i++){
        ll val  ;
        cin>> val ;
        mx = max(mx,val) ;
        level[val].pb(i) ;
    }

    if(level[0].size() != 1){
        cout<< "-1" << endl ;
        return 0 ;
    }

    vector<pii > edge ;
    for(int i=0; i<mx; i++){
        if(level[i].size() == 0){
            cout<< "-1" << endl ;
            return 0 ;
        }
        for(int j=0,idx=0; j<level[i+1].size(); j++){
            edge.pb(mp(level[i][idx],level[i+1][j])) ;
            idx = (idx+1)%level[i].size() ;
            deg[level[i][idx]]++ ;
            deg[level[i+1][j]]++ ;
        }
    }

    for(int i=0; i<n; i++){
        if(deg[i] > k){
            cout<< "-1" << endl ;
            return 0 ;
        }
    }

    cout<< edge.size() << endl ;
    foreach(edge)
        cout<< val.ff+1 << " " << val.ss+1 << endl ;

    return 0;
}

