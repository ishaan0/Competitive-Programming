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

ll const lim = 2e5+5 ;

ll pre[lim], arr[lim] ;
pair<ll,pair<ll,ll> > dp[lim][2] ;
ll n, k ;


pair<ll,pair<ll,ll> > func(int i,int taken){
    if(i+k>n) return mp(0,mp(0,0)) ;
    pair<ll,pair<ll,ll> > &ans = dp[i][taken] ;
    if(ans.ff != -1) return ans ;
    pair<ll,pair<ll,ll> > val1,val2 ;
    if(!taken) val1 = func(i+k+1,1) ;
    val1.ff += pre[i+k]-pre[i-1] ; ;

    val2 = func(i+1,taken) ;
    if(val1.ff>=val2.ff){
        ans = val1 ;
        if(taken) ans.ss.ss = i ;
        else ans.ss.ff = i ;
    }
    else ans = val2 ;
    return ans ;
}

void solve(){
    cin>> n >> k ;
    k-- ;
    for(int i=1; i<=n; i++){
        cin>> arr[i] ;
        pre[i] = pre[i-1] + arr[i] ;
    }

    for(int i=0; i<lim; i++)
        dp[i][0].ff = dp[i][1].ff = -1;
    pair<ll,pair<ll,ll> > ans = func(1,0) ;
    cout<< ans.ss.ff << " " << ans.ss.ss << endl ;
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


