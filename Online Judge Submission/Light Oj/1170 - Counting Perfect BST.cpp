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

ll const mod = 100000007 ;
ll const lim = 1e6+5 ;
ll numbers[lim], fact[lim] ;
ll cnt = 0 ;

void genNumbers(){
    for(ll i=2; i<=100000LL; i++){
        for(ll j=i*i; j<=10000000000LL; j*=i)
            numbers[cnt++] = j ;
    }
    sort(numbers,numbers+cnt) ;
    cnt = unique(numbers,numbers+cnt) - numbers ;
    numbers[cnt] = 10000000100LL ;
}

void genFact(){
    fact[0] = 1 ;
    for(ll i=1; i<=100005; i++)
        fact[i] = (fact[i-1]*i)%mod ;
}

ll bigMod(ll a,ll b){
    a %= mod ;
    ll res = 1 ;
    while(b!=0){
        if(b&1) res = (res*a)%mod ;
        a = (a*a)%mod ;
        b >>= 1 ;
    }
    return res ;
}

void solve(){
    ll a,b ;
    cin>> a >> b ;
    b = upper_bound(numbers,numbers+cnt,b) - numbers ;
    a = lower_bound(numbers,numbers+cnt,a) - numbers ;
    ll n = b - a ;
    if(n==0) cout<< n << endl ;
    else{
        ll ans = (fact[n+1]*fact[n])%mod ;
        ans = bigMod(ans,mod-2) ;
        ans = (ans*fact[2LL*n])%mod ;
        cout<< ans << endl ;
    }
}


int main()
{
    Boost;

    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    genNumbers() ;
    genFact() ;
    int t = 1,cs = 0 ;
    cin>> t ;

    while(t--){
        Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}


