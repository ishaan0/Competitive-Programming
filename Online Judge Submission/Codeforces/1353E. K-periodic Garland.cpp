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

    int t ;
    cin>> t ;
    while(t--){
        int n,k ;
        string str ;
        cin>> n >> k >> str ;
        str = "#" + str ;
        vector<int> pre(n+1) ;
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1] ;
            pre[i] += (int)(str[i]-'0') ;
        }

        int dp[n+5] ;
        memset(dp,0,sizeof dp) ;
        for(int i=n; i>=1; i--){
            int val = (str[i]=='0') ? 1 : 0 ;
            if(i+k-1 <= n)
                val += pre[i+k-1] - pre[i] ;
            else val += pre[n] - pre[i] ;
            if(i+k <= n)
                val += dp[i+k] ;
            int x = pre[n] - pre[i] + (int)(str[i]-'0') ;
            dp[i] = min(val,x) ;
        }

        int cnt = INT_MAX ;
        for(int i=1; i<=n; i++){
            int val = dp[i] + pre[i-1] ;
            cnt = min(cnt,val) ;
        }
        cout<< cnt << endl ;
    }

    return 0;
}


