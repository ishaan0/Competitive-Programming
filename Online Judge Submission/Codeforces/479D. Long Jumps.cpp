#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;


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
#define     pf                  printf
#define     sf                  scanf
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

const double eps = 1e-9 ;
/*
int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
int const drH[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
int const dcH[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;
*/



void solve(){
    ll n,l,x,y ;
    bool boy=true,g=true ;
    cin>> n >> l >> x >> y ;
    vector<ll> arr(n) ;
    foreach(arr) cin>> val ;

    for(int i=0; i<n; i++){
        if(g){
            int pos = lower_bound(all(arr),arr[i]-x)-arr.begin() ;
            if(pos<n && arr[pos]==arr[i]-x) g = false ;
        }
        if(boy){
            int pos = lower_bound(all(arr),arr[i]-y)-arr.begin() ;
            if(pos<n && arr[pos]==arr[i]-y) boy = false ;
        }
    }

    vector<ll> ans ;
    if(boy&&g){
        for(int i=0; i<n; i++){
            int r = arr[i] ;

            int a = lower_bound(all(arr),r+x+y)-arr.begin() ;
            int b = lower_bound(all(arr),r+x-y)-arr.begin() ;
            int c = lower_bound(all(arr),r-x+y)-arr.begin() ;
            int d = lower_bound(all(arr),r-x-y)-arr.begin() ;

            if(a<n&&arr[a]==(r+x+y)){
                if(r+x>=0 && r+x<=l)
                    boy=g=false,ans.pb(r+x) ;
                else if(r+y>=0 && r+y<=1)
                    boy=g=false,ans.pb(r+y) ;
            }
            else if(b<n&&arr[b]==(r+x-y)){
                if(r+x>=0 && r+x<=l)
                    boy=g=false,ans.pb(r+x) ;
                else if(r-y>=0 && r-y<=l)
                    boy=g=false,ans.pb(r-y) ;
            }
            else if(c<n&&arr[c]==(r-x+y)){
                if(r-x>=0 && r-x<=l)
                    boy=g=false,ans.pb(r-x) ;
                else if(r+y>=0 && r+y<=l)
                    boy=g=false,ans.pb(r+y) ;
            }
            else if(d<n&&arr[d]==(r-x-y)){
                if(r-x>=0 && r-x<=l)
                    boy=g=false,ans.pb(r-x) ;
                else if(r-y>=0 && r-y<=l)
                    boy=g=false,ans.pb(r-y) ;
            }

            if(boy==false && g==false) break ;
        }
    }

    if(g) ans.pb(x) ;
    if(boy) ans.pb(y) ;
    sort(all(ans)) ;
    cout<< ans.size() << endl ;
    foreach(ans) cout<< val << " " ;
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


