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
    unordered_map<char,int> m ;
    foreach(str) m[val]++ ;
    int even = 0 , odd = 0 ;
    foreach(m){
        if(val.ss&1) odd++ ;
        else even++ ;
    }
    if((str.size()%2!=0 && odd!=1) || (str.size()%2==0 && odd>0))
        cout<< "NO SOLUTION" << endl ;
    else{
        char ch ;
        for(char i='A'; i<='Z'; i++){
            if(m[i]&1){
                ch = i ;
                continue ;
            }
            int lim = m[i]/2 ;
            for(int j=1; j<=lim; j++)
                cout<< i ;
        }

        if(str.size()%2!=0)
        while(m[ch]!=0){
            cout<< ch ;
            m[ch]-- ;
        }

        for(char i='Z'; i>='A'; i--){
            int lim = m[i]/2 ;
            for(int j=1; j<=lim; j++)
                cout<< i ;
        }
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


