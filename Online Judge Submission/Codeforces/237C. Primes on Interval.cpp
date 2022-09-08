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

int const lim = 1e6+5 ;

ll mark[lim];

void sieve(){
    for(int i=0; i<lim; i++) mark[i] = 1 ;
    mark[0] = mark[1] = 0 ;
    for(ll i=4; i<lim; i+=2) mark[i] = 0 ;
    for(ll i=3; i<lim; i+=2){
        if(mark[i]){
            for(ll j= i*i; j<lim; j+= 2*i)
                mark[j] = 0 ;
        }
    }
    for(int i=1; i<lim; i++)
        mark[i] += mark[i-1] ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    sieve() ;
    int a,b,k,pos;
    cin>> a>> b >> k ;
    pos = k-1 ;
    if(mark[b]-mark[a-1] < k)
        return cout<< "-1" << endl, 0 ;

    bool flag = true ;
    for(int i=a; i+pos<=b; i++){
        ll temp = mark[i+pos]-mark[i-1] ;
        while(temp < k){
            pos++ ;
            if(i+pos > b) break ;
            temp = mark[i+pos]-mark[i-1] ;
        }
    }

    cout<< pos+1 << endl ;

    return 0;
}

