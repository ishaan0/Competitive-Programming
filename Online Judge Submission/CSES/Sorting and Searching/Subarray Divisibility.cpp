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

inline ll mod(ll a,ll b){
    ll ans = ((a%b)+b)%b ;
    return ans ;
}

void solve(){
    ll n,ans=0,sum=0 ;
    cin>> n ;
    vector<ll> arr(n+5) ;
    for(int i=1; i<=n; i++){
        cin>> arr[i] ;
        sum += arr[i] ;
        arr[i] += arr[i-1] ;
        if(mod(sum,n)==0) ans++ ;
    }

    map<ll,ll> m ;

    for(int i=1; i<=n; i++){
        if(m.count(mod(arr[i],n))) ans += m[mod(arr[i],n)] ;
        m[mod(arr[i],n)]++ ;
    }

    cout<< ans  ;

}


int main()
{
    Boost;

    int t = 1,cs = 0 ;
    //cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}

