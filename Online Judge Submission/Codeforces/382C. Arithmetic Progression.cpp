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


void solve(){
    int n ;
    cin>> n ;
    vector<ll> arr(n) ;
    foreach(arr) cin>> val ;

    sort(all(arr)) ;
    vector<ll> ans ;
    if(n==1){
        cout<< "-1" << endl ;
        return ;
    }
    if(n==2){
        ll d = arr[1] - arr[0] ;
        if(d==0) ans.pb(arr[0]) ;
        else{
            ans.pb(arr[0]-d) ;
            ans.pb(arr[1]+d) ;
            if(!(d&1)) ans.pb((arr[1]+arr[0])/2) ;
        }
    }
    else{
        map<int,int> freq ;
        for(int i=1; i<n; i++)
            freq[arr[i]-arr[i-1]]++ ;
        ll d = 0,mx=INT_MIN ;
        foreach(freq){
            if(val.ss > mx || (val.ss==mx && val.ff<d)){
                mx = val.ss ;
                d = val.ff ;
            }
        }

        bool flag = true ;
        for(int i=1; i<n; i++)
        if(arr[i]-arr[i-1] != d){
            if(flag && arr[i-1]+d == arr[i]-d){
                ans.pb(arr[i]-d) ;
                flag = false ;
                continue ;
            }
            cout<< "0" << endl ;
            return ;
        }
        if(flag){
            ans.pb(arr[0]-d) ;
            if(d!=0)
            ans.pb(arr[n-1]+d) ;
        }
    }

    sort(all(ans)) ;
    cout<< ans.size() << endl ;
    foreach(ans) cout<< val << " " ;
    cout<< endl ;

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


