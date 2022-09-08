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
#define     Case                printf("Case %d: ",++cs)
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

ll x,y,l,r ;

inline bool checkBit(ll n,ll pos) {return (bool)(n&(1LL<<pos));}
inline ll setBit(ll n,ll pos) {return n=n|(1LL<<pos);}
inline ll resetBit(ll n,ll pos) {return n=n&(~(1LL<<pos));}

vector<ll> func(){
    vector<ll> ans ;
    ans.pb(l) ;
    ans.pb(r) ;
    ll k = 40 ;
    while(k>=0 && checkBit(l,k)==checkBit(r,k))
        k-- ;
    for(ll i=k-1; i>=0; i--){
        ll z = l ;
        if(checkBit(z,i)) continue ;
        z = setBit(z,i) ;
        for(ll j=i-1; j>=0; j--){
            if(!checkBit(x,j) && !checkBit(y,j))
                z = resetBit(z,j) ;
            else z = setBit(z,j) ;
        }
        ans.pb(z) ;
    }
    for(ll i=k-1; i>=0; i--){
        ll z = r ;
        if(!checkBit(z,i)) continue ;
        z = resetBit(z,i) ;
        for(ll j=i-1; j>=0; j--){
            if(!checkBit(x,j) && !checkBit(y,j))
                z = resetBit(z,j) ;
            else z = setBit(z,j) ;
        }
        ans.pb(z) ;
    }
    sort(all(ans)) ;
    return ans ;
}

ll cal(ll z){
    return (x&z) * (y&z) ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>> t ;

    while(t--){

        cin>> x >> y >> l >> r ;
        vector<ll> arr = func() ;
        ll mx = -1, ans = r ;
        foreach(arr){
            ll temp = cal(val) ;
            if(temp > mx){
                mx = temp ;
                ans = val ;
            }
        }

        cout<< ans << endl ;
    }

    return 0;
}


