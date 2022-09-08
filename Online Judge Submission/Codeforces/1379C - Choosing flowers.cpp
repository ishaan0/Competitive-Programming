#include<bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;
*/

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
#define     Case                printf("Case %d: ",++cs)
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
typedef     pair <ll , ll >             pll ;

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



int solve(){
    ll n,m ;
    sf("%I64d %I64d", &n, &m) ;

    vector<pll> arr(m) ;
    vector<ll> suf(m+1), brr(m) ;
    for(int i=0; i<m; i++)
        sf("%I64d %I64d", &arr[i].ff, &arr[i].ss) ;

    sort(all(arr)) ;
    for(int i=0; i<m; i++)
        brr[i] = arr[i].ff ;

    for(int i=m-1; i>=0; i--)
        suf[i] = suf[i+1] + brr[i] ;

    ll mx = INT_MIN ;
    for(int i=0; i<m; i++){
        ll pos = lower_bound(all(brr), arr[i].ss) - brr.begin() ;
        ll sum = 0, rem = n ;
        if(pos <= i){
            if(m-pos > n) pos = m - n ;
        }
        else{
            if(m-pos > n-1) pos = m - n + 1 ;
            sum = arr[i].ff ;
            rem = n-1 ;
        }
        if(pos < m){
            sum += suf[pos] ;
            rem -= (m-pos) ; 
        }

        sum += (rem*arr[i].ss) ;
        mx = max(mx, sum) ;
    }

    pf("%I64d\n", mx) ;

    return 0 ;
}


int main()
{
    int t = 1,cs = 0 ;
    sf("%d",&t) ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}

