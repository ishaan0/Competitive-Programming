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

ll const lim  = 105 ;
ll const mx = 1e18 ;

ll arr[lim][lim],n,m ;
ll dp[lim][lim] ;

ll func(int i,int j,ll val){
    if(i>=n || j>=m) return mx ;
    ll &ans = dp[i][j] ;
    if(ans != -1) return ans ;

    if(i==(n-1) && j==(m-1)){
        if(arr[i][j] >= val) return ans = arr[i][j]-val ;
        return ans = mx ;
    }

    if(arr[i][j] >= val){
        ll add = arr[i][j]-val ;
        ans =  min(func(i+1,j,val+1), func(i,j+1,val+1)) ;
        ans += add ;
    }
    else ans = mx ;
    return ans ;
}


int main()
{
    Boost;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>> t ;

    while(t--){
        cin>> n >> m ;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>> arr[i][j] ;

        ll ans = 1e18 ;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                memset(dp,-1,sizeof dp) ;
                ll start = arr[i][j]-(i+j) ;
                ans = min(ans,func(0,0,start)) ;
            }
        }

        cout<< ans << endl ;
    }

    return 0;
}


