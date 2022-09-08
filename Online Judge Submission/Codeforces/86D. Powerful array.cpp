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

const int lim1 = 2e5+5 ;
const int lim2 = 1e6+5 ;

ll arr[lim1] ;
const int k = 555 ;

struct range{
    int l, r, idx ;
    bool operator < (range const &ob)const{
        return mp(l/k,r) < mp(ob.l/k,ob.r) ;
    }
};

vector<range> queries ;
ll freq[lim2] ;

inline ll Add(ll idx){
    ll val = arr[idx] ;
    ll prev = freq[val] * freq[val] * val ;
    freq[val]++ ;
    ll cur = freq[val] * freq[val] * val ;
    return cur-prev ;
}

inline ll Remove(ll idx){
    ll val = arr[idx] ;
    if(freq[val] != 0){
        ll prev = freq[val] * freq[val] * val ;
        freq[val]-- ;
        ll cur = freq[val] * freq[val] * val ;
        return cur-prev ;
    }
    return 0 ;
}

void func(int n){
    vector<ll> ans(queries.size()) ;
    sort(all(queries)) ;
    int curL=0, curR=-1 ;
    ll sum = 0 ;

    foreach(queries){
        while(curL > val.l){
            curL-- ;
            sum += Add(curL) ;
        }
        while(curR < val.r){
            curR++ ;
            sum += Add(curR) ;
        }
        while(curL < val.l){
            sum += Remove(curL) ;
            curL++ ;
        }
        while(curR > val.r){
            sum += Remove(curR) ;
            curR-- ;
        }

        ans[val.idx] = sum ;
    }
    foreach(ans)
        printf("%I64d\n",val) ;
}


void solve(){
    int n,q,idx=0 ;
    scanf("%d%d",&n,&q) ;
    for(int i=0; i<n; i++)
        scanf("%I64d",&arr[i]) ;

    while(q--){
        range temp ;
        scanf("%d%d",&temp.l,&temp.r) ;
        temp.l--, temp.r-- ;
        temp.idx = idx++ ;
        queries.pb(temp) ;
    }

    func(n) ;
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


