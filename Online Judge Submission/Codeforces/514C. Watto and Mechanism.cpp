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

const ll m1 = 107241585433 ;
const ll m2 = 1000173893 ;
const ll p1 = 151 ;
const ll p2 = 197 ;
ll n,m ;

pll getHash(string str){
    ll h1 = 0, h2 = 0 ;
    for(int i=0; i<str.size(); i++){
        h1 = (h1*p1 + str[i]) % m1 ;
        h2 = (h2*p2 + str[i]) % m2 ;
    }
    return mp(h1,h2) ;
}

int solve(){
    cin>> n >> m ;
    vector<ll> arr, brr ;

    for(int i=0; i<n; i++){
        string str ;
        cin>> str ;
        pll val = getHash(str) ;
        arr.pb(val.ff) ;
        brr.pb(val.ss) ;
    }

    sort(all(arr)) ;
    sort(all(brr)) ;
    

    while(m--){
        bool flag = false ;
        string str ;
        cin>> str ;

        pll val = getHash(str) ;
        ll basepo1 = 1 , basepo2 = 1;

        for(int i=str.size()-1; i>=0 && !flag; i--){
            for(int j=0; j<3 && !flag; j++){
                if(j == (str[i]-'a')) continue ;
                ll nVal1 = val.ff - (str[i] * basepo1) ;
                ll nVal2 = val.ss - (str[i] * basepo2) ;

                nVal1 = (nVal1 % m1 + m1) % m1 ;
                nVal2 = (nVal2 % m2 + m2) % m2 ;

                nVal1 = (nVal1 + (j+'a') * basepo1) % m1 ;
                nVal2 = (nVal2 + (j+'a') * basepo2) % m2 ;
                
                ll pos1 = lower_bound(all(arr), nVal1) - arr.begin() ;
                ll pos2 = lower_bound(all(brr), nVal2) - brr.begin() ;
                
                if(pos1==n||pos2==n||arr[pos1]!=nVal1||brr[pos2]!=nVal2) continue ;
                flag = true ;
            }
            basepo1 = (basepo1 * p1) % m1 ;
            basepo2 = (basepo2 * p2) % m2 ;
        }

        
        if(flag) cout<< "YES\n" ;
        else cout<< "NO\n" ;
         
    }


    return 0 ;
}


int main()
{
    //Boost ;
    int t = 1,cs = 0 ;
    //sf("%d",&t) ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}

