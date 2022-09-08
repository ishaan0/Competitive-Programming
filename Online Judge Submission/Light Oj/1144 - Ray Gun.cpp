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


ll const lim = 1e6+5 ;

int mark[lim] ;

void sieve(){
    for(ll i=2; i<lim; i++){
        if(mark[i] == 0){
            for(ll j=2*i; j<lim; j+=i)
                mark[j]++ ;
        }
    }
    for(ll i=2; i<lim; i++)
        if(mark[i] == 1)
        for(ll j=i; j<lim; j+=i) mark[j] = -1 ;
}
//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    sieve() ;
    int t,cs = 0 ;
    scanf("%d",&t) ;

    while(t--){
        ll n,m ;
        scanf("%lld%lld",&n,&m) ;
        if(n>m) swap(n,m) ;
        printf("Case %d: ",++cs) ;
        if(n==0 && m==0)
            printf("0\n") ;
        else if(n==0 || m==0)
            printf("1\n") ;
        else{
            ll ans = n*m ;
            for(ll i=2; i<=n; i++){
                if(mark[i] == -1) continue ;
                ll val = (m/i)*(n/i) ;
                if(mark[i]==0 || mark[i]&1)
                    ans -= val ;
                else ans += val ;
            }
            ans += 2 ;
            printf("%lld\n",ans) ;
        }
    }

    return 0;
}
