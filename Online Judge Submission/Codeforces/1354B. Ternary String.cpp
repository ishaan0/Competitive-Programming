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




int main()
{
    Boost;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>> t ;

    while(t--){
        string str ;
        cin>> str ;
        int n = str.size() ;
        str = "#" + str ;

        bool a=false,b=false,c=false ;
        for(int i=1; i<=n; i++){
            if(str[i] == '1') a = true ;
            if(str[i] == '2') b = true ;
            if(str[i] == '3') c = true ;
        }

        if(a==false || b==false || c==false) {
            cout<< "0" << endl ;
            continue ;
        }

        int pre[n+5][4],suf[n+5][4] ;
        memset(pre,0,sizeof pre) ;
        memset(suf,0,sizeof suf) ;
        for(int i=1; i<=3; i++){
            pre[1][i] = -1000000 ;
            suf[n][i] = 1000000 ;
        }

        for(int i=2; i<=n; i++){
            pre[i][1] = pre[i-1][1] ;
            pre[i][2] = pre[i-1][2] ;
            pre[i][3] = pre[i-1][3] ;
            if(str[i-1] == '1') pre[i][1] = i-1 ;
            else if(str[i-1] == '2') pre[i][2] = i-1 ;
            else if(str[i-1] == '3') pre[i][3] = i-1 ;
        }

        for(int i=n-1; i>=1; i--){
            suf[i][1] = suf[i+1][1] ;
            suf[i][2] = suf[i+1][2] ;
            suf[i][3] = suf[i+1][3] ;
            if(str[i+1] == '1') suf[i][1] = i+1 ;
            else if(str[i+1] == '2') suf[i][2] = i+1 ;
            else if(str[i+1] == '3') suf[i][3] = i+1 ;
        }

        int ans= INT_MAX ;
        for(int i=1; i<=n; i++){
            if(str[i] == '1'){
                int val1 = suf[i][3]-pre[i][2]+1 ;
                int val2 = suf[i][2]-pre[i][3]+1 ;
                ans = min({ans,val1,val2}) ;
            }
        }
        for(int i=1; i<=n; i++){
            if(str[i] == '2'){
                int val1 = suf[i][3]-pre[i][1]+1 ;
                int val2 = suf[i][1]-pre[i][3]+1 ;
                ans = min({ans,val1,val2}) ;
            }
        }
        for(int i=1; i<=n; i++){
            if(str[i] == '3'){
                int val1 = suf[i][1]-pre[i][2]+1 ;
                int val2 = suf[i][2]-pre[i][1]+1 ;
                ans = min({ans,val1,val2}) ;
            }
        }
        cout<< ans << endl ;
    }

    return 0;
}

