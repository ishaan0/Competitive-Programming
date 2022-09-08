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

int const lim = 1e6+5 ;

vector<int> tree[4*lim] ;
int pre[lim] ;

void build(int node,int lo,int hi){
    if(lo==hi){
        tree[node].pb(pre[lo]) ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    merge(all(tree[2*node]),all(tree[2*node+1]),back_inserter(tree[node])) ;
}

ll query(int node,int lo,int hi,int qi,int qj,int val){
    if(qj<lo || qi>hi) return 0 ;
    if(qi<=lo && hi<=qj){
        int up = upper_bound(all(tree[node]),val) - tree[node].begin() ;
        int dwn = lower_bound(all(tree[node]),val) - tree[node].begin() ;
        return up-dwn ;
    }
    int mid = lo+(hi-lo)/2 ;
    ll a = query(2*node,lo,mid,qi,qj,val) ;
    ll b = query(2*node+1,mid+1,hi,qi,qj,val) ;
    return (a+b) ;
}

void solve(){
    string str ;
    cin>> str ;
    int n = str.size() ;
    str = "#" + str ;
    for(int i=1; i<=n; i++){
        int val = str[i]-'0' ;
        val %= 3 ;
        pre[i] = (pre[i-1] + val)%3 ;
    }
    build(1,1,n) ;

    ll ans = 0 ;
    for(int i=1; i<=n; i++){
        if(i!=1)
            ans += query(1,1,n,1,i-1,pre[i]) ;
        if(pre[i]%3==0) ans++ ;
    }

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


