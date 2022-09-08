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

struct block{
    int x,y,h ;
    block(){x=y=h=0;}
    block(int xx,int yy,int hh){
        x = xx, y = yy, h = hh ;
    }
    bool operator > (block const &ob) const{
        return ((this->x>ob.x && this->y>ob.y) ||
               (this->x>ob.y && this->y>ob.x) ) ;
    }
};

vector<block> arr ;
int dp[100],n ;

int func(int u){
    if(dp[u] != -1) return dp[u] ;

    int ans = 0 ;
    for(int v=0; v<n; v++){
        if(arr[u] > arr[v]){
            int temp = func(v) ;
            if(temp > ans)
                ans = temp ;
        }
    }
    ans += arr[u].h ;

    return dp[u] = ans ;
}

void solve(int cs){
    cin>> n ;
    if(n==0) exit(0) ;
    arr.clear() ;
    for(int i=0; i<n; i++){
        int a,b,c ;
        cin>>a >>b >>c ;
        arr.pb(block(a,b,c)) ;
        arr.pb(block(a,c,b)) ;
        arr.pb(block(b,c,a)) ;
    }
    n = 3*n ;
    memset(dp,-1,sizeof dp) ;

    int ans = 0 ;
    for(int i=0; i<n; i++)
        ans = max(ans,func(i)) ;

    cout<< "Case "<< cs <<": maximum height = " << ans << endl ;

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

    while(true){
        //Case ;
        solve(++cs) ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}


