#include<bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;
*/

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     memz(cont)          memset(cont, 0, sizeof cont)
#define     memn(cont)          memset(cont, -1, sizeof cont)
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
    ll n,m,x,k,y ;
    cin>> n >> m ;
    cin>> x >> k >> y ;

    vector<ll> arr(n),brr(m),occ(n+5,-1),seg ;

    seg.pb(0) ;
    for(int i=0; i<n; i++){
        cin>> arr[i] ;
        occ[ arr[i] ] = i ;
    }
    for(int i=0; i<m; i++){
        cin>> brr[i] ;
        seg.pb(occ[ brr[i] ]) ;
    }
    seg.pb(n-1) ;

    int prev = -1 ;
    for(int i=0; i<m; i++){
        int cur = occ[ brr[i] ] ;
        if(cur <= prev){
            cout<< "-1\n" ;
            return ;
        }
        prev = cur ;
    }

    ll sum = 0 ;
    for(int i=0; i+1<seg.size(); i++){
        ll l = seg[i], r = seg[i+1] ;
        ll lft = arr[l], rgt= arr[r] ;
        ll p = INT_MIN, range = r-l-1 ;
        
        if(i==0){
            l-- ;
            lft = -1e18 ;
            range++ ;
        }
        if(i+2==seg.size()){
            r++ ;
            rgt = -1e18 ;
            range++ ;
        }
        
        for(int j=l+1; j<=r-1; j++)
            p = max(p,arr[j]) ;

        if(range<k && p>lft && p>rgt){
            cout<< "-1\n" ;
            return ;
        }
        
        sum += (range%k)*y ;
        ll rem = range/k ;
        
        if(rem*k >= k && rem*x <= rem*k*y){
            sum += rem*x ;
            continue ;
        }

        if(p<lft || p<rgt)
            sum += rem*k*y ;
        else sum += x + (rem-1)*k*y ;
    }
    
    cout<< sum << "\n" ;
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

