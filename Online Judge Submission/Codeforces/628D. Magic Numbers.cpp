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

ll const mod  = 1e9+7 ;
ll m,d,lim ;
vector<int> digit ;
ll dp[2][2005][2005] ;

ll func(int isSmall,int pos,int rem){
    if(pos == lim) return (rem==0) ;
    ll &ans = dp[isSmall][pos][rem] ;
    if(ans != -1) return ans ;

    int last = (isSmall) ? 9 : digit[pos] ;
    ans = 0 ;

    if(pos&1){
        if(d>last) return ans ;
        ans = func(isSmall | (d<digit[pos]), pos+1,(rem*10+d)%m)%mod ;
    }
    else{
        for(int i=0; i<=last; i++){
            if(i!=d)
            ans = (ans + func(isSmall | (i<digit[pos]),pos+1,(rem*10+i)%m))%mod ;

        }
    }
    return ans ;
}

ll getAns(string str){

    digit.clear() ;
    foreach(str)
        digit.pb(val-'0') ;
    lim = digit.size() ;
    memset(dp,-1,sizeof dp) ;
    return func(0,0,0) ;
}

void solve(){
    string l,r ;
    cin>> m >> d >> l >> r ;

    ll ans = getAns(r) - getAns(l) ;
    ans = (ans+mod)%mod ;

    ll rem = 0 ;
    bool flag = false ;
    for(int i=0; i<lim; i++){
        if(i==0) flag= true ;
        if(i&1 && digit[i]!=d){
            flag = false ;
            break ;
        }
        if(!(i&1) && digit[i]==d){
            flag = false ;
            break ;
        }
        rem = (rem*10+digit[i])%m ;
    }

    if(flag && rem == 0)
        ans = (ans+1LL)%mod ;
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


