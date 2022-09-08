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

ll arr[5005] ;
pii table[15][5005] ;

void preCal(int n){
    for(int i=0; i<n; i++)
        table[0][i] = mp(arr[i],i) ;
    for(int k=1; (1<<k)<=n; k++){
        for(int i=0; (i+(1<<k)-1)<n; i++){
            pii x = table[k-1][i] ;
            pii y = table[k-1][i+(1<<(k-1))] ;
            if(x.ff < y.ff)
                table[k][i] = x ;
            else table[k][i] = y ;
        }
    }
}

pii query(int i,int j){
    int k = log2(j-i+1) ;
    pii x = table[k][i] ;
    pii y = table[k][j-(1<<k)+1] ;
    if(x.ff < y.ff)
        return x ;
    return y ;
}


ll func(ll lo,ll hi,ll prev){
    if(lo > hi) return 0 ;
    if(lo == hi) return min(1LL,arr[lo]-prev) ;
    pii mn = query(lo,hi) ;
    ll ans = mn.ff-prev ;
    ans += func(lo,mn.ss-1,mn.ff) ;
    ans += func(mn.ss+1,hi,mn.ff) ;
    ans = min(ans,hi-lo+1) ;
    return ans ;
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll n ;
    cin>> n ;
    for(int i=0; i<n; i++) cin>> arr[i] ;
    preCal(n) ;
    ll ans = func(0,n-1,0) ;
    ans = min(ans,n) ;
    cout<< ans << endl ;

    return 0;
}

