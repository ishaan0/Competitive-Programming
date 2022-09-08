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
const int lim = 3e5+5 ;

int n, arr[lim], sparseG[20][lim], sparseM[20][lim] ;
vector<int> res ;

void preCal(){
    for(int i=0; i<lim; i++){
        sparseG[0][i] = arr[i] ;
        sparseM[0][i] = arr[i] ;
    }
    for(int k=1; (1<<k)<=n; k++){
        for(int i=0; (i+(1<<k)-1)<n; i++){
            int x = sparseG[k-1][i] ;
            int y = sparseG[k-1][i+(1<<(k-1))] ;
            sparseG[k][i] = __gcd(x,y) ;
            x = sparseM[k-1][i] ;
            y = sparseM[k-1][i+(1<<(k-1))] ;
            sparseM[k][i] = min(x,y) ;
        }
    }
}

pii query(int l,int r){
    int k = log2(r-l+1) ;
    int x = sparseG[k][l] ;
    int y = sparseG[k][r-(1<<k)+1] ;
    int gcd = __gcd(x,y) ;
    x = sparseM[k][l] ;
    y = sparseM[k][r-(1<<k)+1] ;
    int mn = min(x,y) ;
    return mp(gcd,mn) ;
}

bool func(int mid){
    bool flag = false  ;
    vector<int> temp ;
    for(int i=0; i+mid-1<n; i++){
        pii val = query(i,i+mid-1) ;
        if(val.ff == val.ss){
            flag = true ;
            temp.pb(i+1) ;
        }
    }
    if(flag){
        res = temp ;
        return true ;
    }
    return false ;
}

void solve(){
    cin>> n ;
    for(int i=0; i<n; i++) cin>> arr[i] ;
    preCal() ;
    
    int lo = 1 , hi = n, ans= 0;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2 ;
        if(func(mid)){
            lo = mid+1 ;
            ans = mid ;
        }
        else hi = mid-1 ;
    }
    
    cout<< res.size() << " " << ans-1 << "\n" ;
    foreach(res) cout<< val <<" " ;
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

