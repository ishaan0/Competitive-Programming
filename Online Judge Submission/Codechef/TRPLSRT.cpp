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
        ll n, k ;
        cin>> n >> k ;
        vector<int> arr(n+1) ;
        vector<bool> vis(n+1) ;
        vector<tuple<int,int,int> > ans ;
        vector<pii > dbl ;
        for(int i=1; i<=n; i++) cin>> arr[i] ;

        for(int i=1; i<=n; i++){
            vector<int> cycle ;
            int j = i ;
            while(!vis[j]){
                cycle.pb(j) ;
                vis[j] = true ;
                j = arr[j] ;
            }

            while(cycle.size() > 2){
                int z = cycle.back() ;
                cycle.pop_back() ;
                int y = cycle.back() ;
                cycle.pop_back() ;
                int x = cycle.back() ;
                if(cycle.size() == 1)
                    cycle.pop_back() ;
                ans.pb(tie(x,y,z)) ;
                k-- ;
            }
            if(cycle.size() == 2)
                dbl.pb(mp(cycle[0],cycle[1])) ;
        }

        while(dbl.size() > 1){
            pii a = dbl.back() ;
            dbl.pop_back() ;
            pii b = dbl.back() ;
            dbl.pop_back() ;
            ans.pb(tie(a.ss,b.ff,b.ss)) ;
            ans.pb(tie(a.ff,a.ss,b.ff)) ;
            k -= 2 ;
        }

        if(!dbl.empty() || k<0)
            cout<< "-1"  << endl ;
        else{
            cout<< ans.size() << endl ;
            for(int i=0; i<ans.size(); i++){
                cout<< get<0>(ans[i]) << " "
                    << get<1>(ans[i]) << " "
                    << get<2>(ans[i]) << endl ;
            }
        }

    }

    return 0;
}

