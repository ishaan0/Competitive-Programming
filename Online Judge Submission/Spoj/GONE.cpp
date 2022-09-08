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

bool mark[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0,
               1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0,
               0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0,
               0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
               0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
               0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
               0, 1 } ;


ll dp[2][10][80],lim ;
vector<int> digit ;

ll func(int isSmall,int pos,int sum){
    if(pos == lim) return mark[sum] ;

    ll &ans = dp[isSmall][pos][sum] ;
    if(ans != -1) return ans ;

    int last = (isSmall) ? 9 : digit[pos] ;
    ans = 0 ;
    for(int i=0; i<=last; i++)
        ans += func(isSmall | (i<last), pos+1, sum+i) ;

    return ans ;
}

ll makeDigit(ll n){
    if(n<0) return 0 ;
    digit.clear() ;
    while(n){
        digit.pb(n%10) ;
        n /= 10 ;
    }
    reverse(all(digit)) ;
    lim = digit.size() ;
    return func(0,0,0) ;
}

void solve(){
    ll l,r ;
    cin>> l >> r ;
    if(l>r) swap(l,r) ;
    memset(dp,-1,sizeof dp) ;
    ll a = makeDigit(r) ;
    memset(dp,-1,sizeof dp) ;
    ll b = makeDigit(l-1) ;
    ll ans = a-b ;
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
    cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}


