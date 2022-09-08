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
    int n ;
    string a,b ;
    cin>> n >> a >> b ;

    vector<int> ans ;
    bool flag = 0 ; /// back move -> 0 , front move -> 1
    int lo = 0, hi = n-1 ;
    char one = '1', zero = '0' ;
    for(int i=n-1; i>=0; i--){
        char temp1 = a[lo] ;
        char temp2 = a[hi] ;
        if(one == '0'){
            temp1 = (a[lo] == '1') ? '0' : '1' ;
            temp2 = (a[hi] == '1') ? '0' : '1' ;
        }
        if(temp2 == b[i]) ;
        else if(temp1 != b[i]){
            swap(one,zero) ;
            swap(lo,hi) ;
            flag = (flag) ? 0 : 1 ;
            ans.pb(i+1) ;
        }
        else{
            a[lo] = (a[lo] == '0')  ? '1' : '0' ;
            swap(one,zero) ;
            swap(lo,hi) ;
            flag = (flag) ? 0 : 1 ;
            ans.pb(1) ;
            ans.pb(i+1) ;
        }

        if(flag) hi++ ;
        else hi-- ;

    }
    
    cout<< ans.size() << " " ;
    foreach(ans) cout<< val << " " ;
    cout<< "\n" ;

    return 0 ;
}


int main()
{
    Boost ;
    int t = 1,cs = 0 ;
    //sf("%d",&t) ;
    cin>> t ;
    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}

