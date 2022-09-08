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

vector<ll> arr,pre ;

ll func(ll l,ll r,ll x,ll k){
    ll lo=l,hi=r ;
    ll ans = 0 ;
    while(lo <= hi){
        ll mid = lo+(hi-lo)/2LL ;
        ll val = ((r-mid+1)*x) - (pre[r]-pre[mid-1]) ;
        if(val <= k){
            hi = mid-1LL ;
            ans = mid ;
        }
        else lo = mid+1LL ;
    }

    if(ans==0) return ans ;
    return (r-ans+1LL) ;
}

void reset(){
    arr.clear() ;
    pre.clear() ;
    arr.resize(n+5) ;
    pre.resize(n+5) ;
}

void solve(){
    ll n,q ;
    cin>> n ;
    reset() ;
    for(int i=1; i<=n; i++)
        cin>> arr[i] ;
    sort(arr.begin()+1,arr.begin()+n+1) ;

    for(int i=1; i<=n;i++)
        pre[i] = pre[i-1] + arr[i] ;

    cin>> q ;
    while(q--){
        ll x,k ;
        cin>> x >> k ;
        ll pos = upper_bound(arr.begin()+1,arr.begin()+n+1,x) - arr.begin() ;
        ll ans = (n-pos+1) ;
        pos-- ;

        if(pos<1){
            cout<< n << endl ;
            continue ;
        }

        ans += func(1,pos,x,k) ;
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


