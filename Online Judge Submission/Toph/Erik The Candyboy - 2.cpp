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

ll const lim = 1e5+5 ;
/// not solved ...
pair<ll,ll> tree[4*lim] ;
ll cnt[4*lim] ;


ll findSum(ll lo,ll hi,ll val,ll d){
    double n = (hi-lo+1) ;
    ll sum = (n/2)*(2.0*val+(n-1)*d*1.0) ;
    return sum ;
}

void update(int node,int lo,int hi,int qi,int qj,ll& val){
    if(qj<lo || qi>hi) return ;
    if(qi<=lo || hi<=qj){
        tree[node].ff += findSum(lo,hi,val,1) ;
        tree[node].ss += val ;
        cnt[node]++ ;
        val += hi-lo+1 ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    update(2*node,lo,mid,qi,qj,val) ;
    update(2*node+1,mid+1,hi,qi,qj,val) ;
    tree[node].ff = tree[2*node].ff+tree[2*node+1].ff+ findSum(lo,hi,tree[node].ss,cnt[node]) ;
}


ll query(int node,int lo,int hi,int qi,int qj,ll& carry,ll c=0){
    if(qj<lo || qi>hi) return 0 ;
    if(qi<=lo && hi<=qj){
        ll sum = tree[node].ff+findSum(lo,hi,carry,c) ;
        carry += hi-lo+1 ;
    }
    int mid = lo+(hi-lo)/2 ;
    carry += tree[node].ss ;
    ll lft = query(2*node,lo,mid,qi,qj,carry,c+cnt[node]) ;
    ll rgt = query(2*node+1,mid+1,hi,qi,qj,carry,c+cnt[node]) ;
    return lft+rgt ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif


    ll n,q;
    cin>> n>> q ;

    while(q--){
        ll task,lo,hi;
        cin>> task>> lo >> hi ;
        if(task==1){
            ll val = 1 ;
            update(1,1,n,lo,hi,val) ;
        }
        else{
            ll val = 0 ;
            ll ans = query(1,1,n,lo,hi,val) ;
            cout<< ans << endl ;
        }
    }

    return 0;
}

