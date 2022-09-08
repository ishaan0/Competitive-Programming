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


int cnt[10],temp[10],lim ;
vector<int> digit ;
ll dp[2][2][20][1024] ;

ll func(int isSmall,int isStart,int pos,int mask){
    if(pos == lim) return (mask == 0) ;

    ll &ans = dp[isSmall][isStart][pos][mask] ;
    if(ans != -1) return ans ;

    int last = (isSmall) ? 9 : digit[pos] ;
    ans = 0 ;

    if(!isStart){
        for(int i=0; i<=last; i++){
            temp[i]++ ;
            int curMask = mask ;
            if(temp[i] == cnt[i]) curMask |= (1<<i) ;
            else curMask &= (~(1<<i)) ;
            ans += func(isSmall | (i<digit[pos]),0,pos+1,curMask) ;
            temp[i]-- ;
        }
    }
    else{
        for(int i=1; i<=last; i++){
            temp[i]++ ;
            int curMask = 0 ;
            if(temp[i] == cnt[i]) curMask |= (1<<i) ;
            else curMask &= (~(1<<i)) ;
            ans += func(isSmall | (i<digit[pos]),0,pos+1,curMask) ;
            temp[i]-- ;
        }
        ans += func(1,1,pos+1,0) ;
    }
    return ans ;
}


ll getAns(ll n){
    digit.clear() ;
    while(n){
        digit.pb(n%10) ;
        n /= 10 ;
    }
    reverse(all(digit)) ;
    lim = digit.size() ;
    memset(dp,-1,sizeof dp) ;
    memset(temp,0,sizeof temp) ;
    return func(0,1,0,0)-1 ;
}


void solve(){
    ll l,r ;
    cin>> l >> r ;
    memset(cnt,0,sizeof cnt) ;
    for(int i=0; i<10; i++)
        cin>> cnt[i] ;
    dbg(getAns(r),getAns(l-1)) ;
    ll ans = getAns(r) - getAns(l-1) ;
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


