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

string str ;
ll nb,ns,nc ;
ll pb,ps,pc ;
ll cb,cs,cc ;
ll amt ;

inline ll func(ll cnt){
    ll tb = cnt*cb ;
    ll ts = cnt*cs ;
    ll tc = cnt*cc ;
    ll price = (pb*tb) + (ps*ts) + (pc*tc) ;
    price -= ( (min(tb,nb)*pb) + (min(ts,ns)*ps) + (min(tc,nc)*pc) ) ;
    return price ;
}

inline ll f(ll a, ll b){
    if(b == 0)
        return INT_MAX ;
    return (a/b) ;
}

void solve(){
    cb = cs = cc = 0 ;
    cin>> str ;
    cin>> nb >> ns >> nc ;
    cin>> pb >> ps >> pc ;
    cin>> amt ;

    for(int i=0; i<str.size(); i++){
        if(str[i] == 'B') cb++ ;
        else if(str[i] == 'S') cs++ ;
        else cc++ ;
    }

    ll ans = min({f(nb,cb),f(ns,cs),f(nc,cc)}) ;
    nb = (cb) ? nb - (ans*cb) : 0 ;
    ns = (cs) ? ns - (ans*cs) : 0 ;
    nc = (cc) ? nc - (ans*cc) : 0 ;

    ll lo = 1, hi = 1e13, temp = 0 ;
    while(lo <= hi){
        ll mid = lo + (hi-lo)/2LL ;
        if(func(mid) <= amt){
            temp = mid ;
            lo = mid + 1 ;
        }
        else hi = mid - 1 ;
    }
    ans += temp ;

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


