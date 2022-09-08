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

int blkSize ;
struct query{
    int l,r,idx ;
    bool operator < (query const &ob) const{
        return mp(l/blkSize,r) < mp(ob.l/blkSize,ob.r) ;
    }
};

int arr[30005] ;
vector<query> queries ;
int freq[1000005] ;

inline int Add(int idx){
    freq[ arr[idx] ]++ ;
    if(freq[ arr[idx] ] == 1)
        return 1 ;
    return 0 ;
}
inline int Remove(int idx){
    if(freq[ arr[idx] ] != 0){
        freq[ arr[idx] ]-- ;
        if(freq[ arr[idx] ] == 0)
            return -1 ;
    }
    return 0 ;
}


void func(int n){
    blkSize = sqrt(n) ;
    vector<int> ans(queries.size()) ;
    sort(all(queries)) ;
    int curL=0, curR=-1, cnt=0 ;

    for(query q: queries){

        while(curL > q.l){
            curL-- ;
            cnt += Add(curL) ;
        }
        while(curR < q.r){
            curR++ ;
            cnt += Add(curR) ;
        }
        while(curL < q.l){
            cnt += Remove(curL) ;
            curL++ ;
        }
        while(curR > q.r){
            cnt += Remove(curR) ;
            curR-- ;
        }
        ans[q.idx] = cnt ;
    }

    foreach(ans)
        cout<< val << endl ;
}


void solve(){
    int n ;
    cin>> n ;
    for(int i=0; i<n; i++)
        cin>> arr[i] ;

    int q,idx = 0 ;
    cin>> q ;
    while(q--){
        query range ;
        cin>> range.l >> range.r ;
        range.l--, range.r-- ;
        range.idx = idx++ ;
        queries.pb(range) ;
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


