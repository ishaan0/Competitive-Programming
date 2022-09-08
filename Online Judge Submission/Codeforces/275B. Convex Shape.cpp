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



//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,m ;
    cin>> n >> m ;
    vector<string> str(n) ;
    vector<pii> pos ;
    foreach(str) cin>> val ;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            if(str[i][j] == 'B')
                pos.pb(mp(i,j)) ;
    }

    for(int i=0; i<pos.size(); i++){
        for(int j=i+1; j<pos.size(); j++){
            int x1 = pos[i].ff, y1 = pos[i].ss ;
            int x2 = pos[j].ff, y2 = pos[j].ss ;
            bool p1 = true , p2 = true ;
            if(x2<x1){
                for(int k=x1; k>=x2; k--){
                    if(str[k][y1] == 'W') p1 = false ;
                    if(str[k][y2] == 'W') p2 = false ;
                }
            }
            else if(x2>x1){
                for(int k=x1; k<=x2; k++){
                    if(str[k][y1] == 'W') p1 = false ;
                    if(str[k][y2] == 'W') p2 = false ;
                }
            }

            for(int k=y1; k<=y2; k++){
                if(str[x2][k] == 'W') p1 = false ;
                if(str[x1][k] == 'W') p2 = false ;
            }

            if(p1==false && p2==false)
                return cout<< "NO" << endl, 0 ;
        }

    }

    cout<< "YES" << endl ;

    return 0;
}


