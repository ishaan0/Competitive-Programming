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

ll const mod = 1e9+7 ;
ll const lim = 1e4+5 ;
ll const lim2 = 1e6+5 ;
bool mark[lim2] ;
vector<int> primes ;
void sieve(){
    mark[0] = mark[1] = 1 ;
    primes.pb(2) ;
    for(ll i=4; i<lim2; i+=2) mark[i] = 1 ;
    for(ll i=3; i<lim2; i+=2){
        if(!mark[i]){
            primes.pb(i) ;
            for(ll j=i*i; j<lim2; j+=2*i)
                mark[j] = 1 ;
        }
    }
}

ll arr[lim] ;
vector<pii > tree[4*lim] ;

ll bigMod(ll a,ll p){
    if(p == 0) return 1 ;
    else if(p&1)
        return ((a%mod)*bigMod(a,p-1))%mod ;
    else{
        ll temp = bigMod(a,p/2) ;
        temp = (temp*temp)%mod ;
        return temp ;
    }
}

vector<pii > factor(ll n){
    vector<pii > ans ;
    for(int i=0; i<primes.size()&&primes[i]*primes[i]<=n; i++){
        if(n%primes[i]!=0) continue ;
        ll cnt = 0 ;
        ll p = primes[i] ;
        while(n%p==0)
            n/=p , cnt++ ;
        ans.pb(mp(p,cnt)) ;
    }
    if(n>1) ans.pb(mp(n,1)) ;
    return ans ;
}

vector<pii > Merge(vector<pii > a, vector<pii > b){
    ll i=0,j=0 ;
    vector<pii > ans ;
    while(i<a.size() && j<b.size()){
        if(a[i].ff == b[j].ff){
            ans.pb(mp(a[i].ff, max(a[i].ss,b[j].ss))) ;
            i++,j++ ;
        }
        else if(a[i].ff < b[j].ff) ans.pb(a[i++]) ;
        else ans.pb(b[j++]) ;
    }
    while(i<a.size()) ans.pb(a[i++]) ;
    while(j<b.size()) ans.pb(b[j++]) ;
    return ans ;
}

void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node] = factor(arr[lo]) ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    tree[node] = Merge(tree[2*node],tree[2*node+1]) ;
}

vector<pii > query(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return vector<pii >() ;
    else if(qi<=lo && hi<=qj) return tree[node] ;
    int mid = lo+(hi-lo)/2 ;
    vector<pii > lft = query(2*node,lo,mid,qi,qj) ;
    vector<pii > rgt = query(2*node+1,mid+1,hi,qi,qj) ;
    return Merge(lft,rgt) ;
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
    int n ;
    cin>> n ;
    for(int i=1; i<=n; i++) cin>> arr[i] ;
    build(1,1,n) ;

    int q ;
    cin>> q ;

    while(q--){
        int lo, hi ;
        cin>> lo >> hi ;
        vector<pii > qry = query(1,1,n,lo,hi) ;
        ll ans = 1 ;
        foreach(qry) ans = (ans*bigMod(val.ff,val.ss))%mod ;
        cout<< ans << endl ;
    }


    return 0;
}
