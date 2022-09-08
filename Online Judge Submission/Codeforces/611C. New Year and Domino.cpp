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




//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int h,w ;
    cin>> h >> w ;

    vector<string> arr(h+1) ;
    vector<int> row[h+1],col[w+1] ;
    for(int i=1; i<=h; i++)
        cin>> arr[i] ;

    for(int i=0; i<=w; i++){
        arr[0] = arr[0] + "0" ;
        col[i].pb(0) ;
    }
    for(int i=0; i<=h; i++){
        arr[i] = "0" + arr[i] ;
        row[i].pb(0) ;
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            row[i].pb(row[i][j-1]) ;
            if(arr[i][j]=='.'&&arr[i][j-1]=='.')
                row[i][j]++ ;
        }
    }
    for(int i=1; i<=w; i++){
        for(int j=1; j<=h; j++){
            col[i].pb(col[i][j-1]) ;
            if(arr[j][i]=='.'&&arr[j-1][i]=='.')
                col[i][j]++ ;
        }
    }

    int q ;
    cin>> q ;

    while(q--){
        int r1,r2,c1,c2 ;
        cin>> r1 >> c1 >> r2 >> c2 ;
        ll sum = 0 ;
        for(int i=r1; i<=r2; i++){
            sum += (ll)row[i][c2] - row[i][c1-1] ;
            if(arr[i][c1]=='.' && arr[i][c1-1]=='.') sum-- ;
        }
        for(int i=c1; i<=c2; i++){
            sum += (ll)col[i][r2] - col[i][r1-1] ;
            if(arr[r1][i]=='.'&&arr[r1-1][i]=='.') sum-- ;
        }
        cout<< sum << endl ;
    }


    return 0;
}

