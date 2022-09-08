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
#define     Case                cout<< "Case "<< ++cs << ": "
#define     inf                 LONG_LONG_MIN
#define     INF                 LONG_LONG_MAX
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

struct group{
    int cnt,pay,idx ;
    group(){cnt=0,pay=0,idx=0;}
};

struct table{
    int idx,cap ;
    table(){idx=0,cap=0;}
};

bool cmp1(group a,group b){
    return a.pay > b.pay ;
}

bool cmp2(table a,table b){
    return a.cap < b.cap ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,r ;
    cin>> n ;
    vector<group> arr(n) ;
    for(int i=0; i<n; i++){
        cin>> arr[i].cnt >> arr[i].pay ;
        arr[i].idx = i+1 ;
    }
    cin>> r ;
    vector<table> tb(r) ;
    for(int i=0; i<r; i++){
        cin>> tb[i].cap ;
        tb[i].idx = i+1 ;
    }

    sort(all(arr),cmp1) ;
    sort(all(tb),cmp2) ;

    vector<pii> ans ;
    vector<bool> used(r) ;
    int sum = 0 ;
    for(int i=0; i<n; i++){
        int val = arr[i].cnt ;
        int j = 0 ;
        while(j<r && (tb[j].cap < val || used[j]))
            j++ ;

        if(j<r){
            sum += arr[i].pay ;
            ans.pb(mp(arr[i].idx,tb[j].idx)) ;
            used[j] = true ;
        }
    }

    cout<< ans.size() << " " << sum << endl ;
    foreach(ans) cout<< val.ff << " " << val.ss << endl ;


    return 0;
}


