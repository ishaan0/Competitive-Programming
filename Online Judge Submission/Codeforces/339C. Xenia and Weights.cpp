#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &value: cont)
#define     show(val)           cout<< #val << " -> " << val << endl
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs << ": "
#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second
#define     ed                  "\n"

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;

vector<int> wgt ;
int dp[1005][11][20] ;
int path[1005][11][20] ;

bool func(int m,int last,int diff){
    if(m==0) return 1 ;
    int &ans = dp[m][last][diff] ;
    if(ans != -1) return ans ;
    for(int x: wgt){
        if(x-diff>0 && x!=last && func(m-1,x,x-diff)){
            path[m][last][diff] = x ;
            return ans = 1 ;
        }
    }
    return ans = 0 ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    memset(dp,-1,sizeof dp) ;
    string str ;
    cin>> str ;
    for(int i=0; i<str.size(); i++)
        if(str[i] == '1') wgt.pb(i+1) ;

    int m ;
    cin>> m ;

    if(func(m,0,0)){
        cout<< "YES" << endl ;
        int last=0,diff=0 ;
        for(int i=m; i>0; i--){
            cout<< path[i][last][diff] << " " ;
            last = path[i][last][diff] ;
            diff = last - diff ;
        }
        cout<< endl ;
    }
    else cout<< "NO" << endl ;

    return 0;
}


