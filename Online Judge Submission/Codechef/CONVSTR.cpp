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

inline bool checkBit(int num,int pos){
    return (bool)(num&(1<<pos)) ;
}

void solve(){
    bool flag = false ;
    int n,gave=0 ;
    cin>> n ;
    string st,ed ;
    cin>> st >> ed ;

    for(int i=0; i<n; i++)
        gave |= (1<<(st[i]-'a')) ;
    for(int i=0; i<n; i++){
        if(st[i] == ed[i]) continue ;
        if(st[i]<ed[i] || !checkBit(gave,ed[i]-'a')){
            flag = true ;
            break ;
        }
    }

    if(flag){
        cout<< "-1" << endl ;
        return ;
    }

    vector<vector<int> > ans ;
    for(int i=25; i>=0; i--){
        vector<int> temp ;
        for(int j=0; j<n; j++){
            if((ed[j]-'a')==i && ed[j]!=st[j])
                temp.pb(j) ;
        }
        if(temp.size() != 0){
            for(int j=0; j<n; j++)
            if(st[j]-'a' == i){
                temp.pb(j) ;
                break ;
            }
            ans.pb(temp) ;
        }
    }

    cout<< ans.size() << endl ;
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i].size() ;
        sort(all(ans[i])) ;
        for(int j=0; j<ans[i].size(); j++){
            cout<< " " ;
            cout<< ans[i][j] ;
        }
        cout<< endl ;
    }

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

