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

ll const lim = 1e7+5 ;
ll const lim2 = 1e5+5 ;

bool mark[lim] ;
vector<int> primes ;
ll phi[lim2] ;
ll mark2[lim2] ;

void sieve(){
    primes.pb(2) ;
    for(ll i=4; i<lim; i+=2) mark[i] = true ;
    for(ll i=3; i*i<lim; i+=2){
        if(!mark[i]){
            for(ll j=i*i; j<lim; j+=i)
                mark[j] = true ;
        }
    }
    for(ll i=3; i<lim; i+=2)
        if(!mark[i]) primes.pb(i) ;
}

void segSieve(ll a,ll b){
    if(a==1) mark2[0] = 1 ;
    for(ll i=a; i<=b; i++) phi[i-a] = i,mark2[i-a] = i;
    for(ll i=0; i<primes.size()&&primes[i]<=b; i++){
        ll p = primes[i] ;
        ll j = (a/p)*p ;
        if(j<a) j+= p ;
        for(; j<=b; j+= p){
            while(mark2[j-a]%p==0)
                mark2[j-a] /= p ;
            phi[j-a] = (phi[j-a]/p)*(p-1) ;
        }
    }
    for(ll i=a; i<=b; i++)
        if(mark2[i-a] > 1)
            phi[i-a] = (phi[i-a]/mark2[i-a])*(mark2[i-a]-1) ;

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
    ll a,b ;
    scanf("%lld%lld",&a,&b) ;
    segSieve(a,b) ;

    for(ll i=a; i<=b; i++)
        printf("%lld\n",phi[i-a]) ;

    return 0;
}

