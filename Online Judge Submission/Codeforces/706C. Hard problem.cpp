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

    ll n ;
    cin>> n ;
    vector<string> str,rev ;
    vector<int> cost(n) ;
    for(int i=0; i<n; i++)
        cin>> cost[i] ;
    for(int i=0; i<n; i++){
        string temp ;
        cin>> temp ;
        str.pb(temp) ;
        reverse(all(temp)) ;
        rev.pb(temp) ;
    }

    ll dp[n][2],mx = 1e15 ;
    for(int i=0; i<n; i++)
        dp[i][0] = dp[i][1] = mx ;

    dp[0][0] = 0 ;
    dp[0][1] = cost[0] ;

    for(int i=1; i<n; i++){
        if(str[i] >= str[i-1])
            dp[i][0] = min(dp[i][0],dp[i-1][0]) ;
        if(rev[i] >= str[i-1])
            dp[i][1] = min(dp[i][1],cost[i]+dp[i-1][0]) ;
        if(str[i] >= rev[i-1])
            dp[i][0] = min(dp[i][0],dp[i-1][1]) ;
        if(rev[i] >= rev[i-1])
            dp[i][1] = min(dp[i][1],cost[i]+dp[i-1][1]) ;
    }

    ll ans = min(dp[n-1][0],dp[n-1][1]) ;
    if(ans >= mx) ans = -1 ;

    cout<< ans << endl ;


    return 0;
}

