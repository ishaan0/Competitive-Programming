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
#define     Case                cout<< "Case "<< ++cs <<": "
#define     PI                  3.1415926535897932384
#define     eps                 1e-9
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

ll dp[1005][1005][3] ;
vector<pair<ll,ll> > arr ;
int n, m, x, y ;

int func(int i,int cnt,int flag){
    if(cnt>y) return INT_MAX ;
    if(i==m){
        if(cnt>=x) return 0 ;
        return INT_MAX ;
    }
    ll &ans = dp[i][cnt][flag] ;
    if(ans != -1) return ans ;
    ans = INT_MAX ;

    int tmp ;
    if(flag==0) tmp = cnt+1 ;
    else tmp = 1 ;
    if(flag==0 || cnt>=x)
    ans = min(ans,arr[i].ss+func(i+1,tmp,0)) ;
    if(flag==1) tmp = cnt+1 ;
    else tmp = 1 ;
    if(flag==1 || cnt>=x)
    ans = min(ans,arr[i].ff+func(i+1,tmp,1)) ;

    return ans ;
}


void solve(){
    cin>> n >> m >> x >> y ;
    vector<string> str(n) ;
    foreach(str) cin>> val ;

    for(int i=0; i<m; i++){
        ll w=0,b=0 ;
        for(int j=0; j<n; j++)
            if(str[j][i] == '.') w++ ;
            else b++ ;
        arr.pb(mp(w,b)) ;
    }

    memset(dp,-1,sizeof dp) ;
    int ans = func(0,x,2) ;
    cout<< ans << endl ;

}


int main()
{
    Boost;

    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t = 1,cs = 0 ;
    //cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}


