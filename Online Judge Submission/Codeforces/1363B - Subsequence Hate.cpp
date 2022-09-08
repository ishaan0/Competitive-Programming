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
    string str ;
    cin>> str ;
    int n = str.size(),one=0,zero=0 ;
    str = "#" + str ;
    for(int i=1; i<=n; i++){
        if(str[i] == '1') one++ ;
        else zero++ ;
    }

    if(one==n || zero==n){
        cout<< "0" << endl ;
        return ;
    }

    vector<int> preZ(n+5),sufZ(n+5) ;
    vector<int> preO(n+5),sufO(n+5) ;
    for(int i=1; i<=n; i++){
        preO[i] = preO[i-1] ;
        preZ[i] = preZ[i-1] ;
        if(str[i] == '0')
            preZ[i]++ ;
        else preO[i]++ ;
    }
    for(int i=n; i>=1; i--){
        sufO[i] = sufO[i+1] ;
        sufZ[i] = sufZ[i+1] ;
        if(str[i] == '0')
            sufZ[i]++ ;
        else sufO[i]++ ;
    }

    int ans = INT_MAX ;

    for(int i=1; i<=n; i++){
        int val1 = preO[i] + sufZ[i+1] ;
        int val2 = preZ[i] + sufO[i+1] ;
        ans = min({ans,val1,val2}) ;
    }
    ans = min({ans,one,zero}) ;
    cout<< ans << endl ;

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
    cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}

