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
    ll sum = 0 ;
    int n,k,p ;
    cin>> n >> k >> p ;
    vector<int> even,odd ;
    for(int i=0; i<n; i++){
        int val ;
        cin>> val ;
        if(val & 1) odd.pb(val) ;
        else even.pb(val) ;
        sum += (ll)val ;
    }
    
    ll temp = (even.size()+(odd.size()-k+p)/2) ;
    if((sum&1) != ((k-p)&1) || (odd.size()<(k-p)) || temp<p){
        cout<< "NO" << endl ;
        return ;
    }

    int j = 0 ;
    vector<int> ans[k] ;
    for(int i=even.size()-1; i>=0&&j<p; i--,j++){
        ans[j].pb(even[i]) ;
        even.pop_back() ;
    }

    for(int i=odd.size()-1; i-1>=0&&j<p;i-=2,j++){
        ans[j].pb(odd[i]) ;
        ans[j].pb(odd[i-1]) ;
        odd.pop_back() ;
        odd.pop_back() ;
    }

    for(int i=odd.size()-1; i>=0&&j<k;i--,j++){
        ans[j].pb(odd[i]) ;
        odd.pop_back() ;
    }
    for(int i=0; i<even.size(); i++)
        ans[k-1].pb(even[i]) ;
    for(int i=0; i<odd.size(); i++)
        ans[k-1].pb(odd[i]) ;

    cout<< "YES" << endl ;
    for(int i=0; i<k; i++){
        cout<< ans[i].size() <<" " ;
        foreach(ans[i]) cout<< val << " " ;
        cout<< endl ;
    }




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
