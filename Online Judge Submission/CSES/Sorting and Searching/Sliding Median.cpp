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

const int lim = 2e5+5 ;

int n,k,med ;
int arr[lim] ;
multiset<int> lower, upper ;

void add(int val){
    auto it = --(lower.end()) ;
    int sz1 = lower.size(),sz2 = upper.size() ;
    if((sz1+sz2)&1){
        if(val< *it){
            int temp = *(--(lower.end())) ;
            lower.erase(--(lower.end())) ;
            lower.insert(val) ;
            upper.insert(temp) ;
        }
        else upper.insert(val) ;
        med = *(--(lower.end())) ;
    }
    else{
        if(val >= *it){
            upper.insert(val) ;
            int temp = *(upper.begin()) ;
            upper.erase(upper.begin()) ;
            lower.insert(temp) ;
        }
        else lower.insert(val) ;
        med = *(--(lower.end())) ;
    }
}

void rem(int val){
    auto it = --(lower.end()) ;
    int sz1 = lower.size(),sz2 = upper.size() ;
    if((sz1+sz2)&1){
        if(val > *it){
            upper.erase(upper.find(val)) ;
            int temp = *(--(lower.end())) ;
            lower.erase(--(lower.end())) ;
            upper.insert(temp) ;
        }
        else lower.erase(lower.find(val)) ;
        med = *(--(lower.end())) ;
    }
    else{
        if(val <= *it){
            lower.erase(lower.find(val)) ;
            int temp = *(upper.begin()) ;
            upper.erase(upper.begin()) ;
            lower.insert(temp) ;
        }
        else upper.erase(upper.find(val)) ;
        med = *(--(lower.end())) ;
    }
}

void solve(){
    cin>> n >> k ;
    if(k==1){
        for(int i=1; i<=n; i++){
            cin>> arr[i] ;
            cout<< arr[i] << " " ;
        }
        return ;
    }
    for(int i=1; i<=n; i++){
        cin>> arr[i] ;
        int val = arr[i] ;
        if(i==1){
            lower.insert(val) ;
            continue ;
        }
        if(i<k) add(val) ;
        else{
            add(val) ;
            cout<< med << " " ;
            rem(arr[i-k+1]) ;
        }
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

