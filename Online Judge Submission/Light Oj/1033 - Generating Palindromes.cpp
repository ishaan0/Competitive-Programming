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

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;

string str ;
ll dp[105][105] ;

ll func(ll i,ll j){
    if(i>j) return 0  ;
    ll &ans = dp[i][j] ;;
    if(ans != -1) return ans ;

    if(str[i] == str[j])
        ans = func(i+1,j-1) ;
    else ans =  1+min(func(i+1,j),func(i,j-1)) ;
    return ans ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0 ;
    cin>> t ;
    while(t--){
        cin>> str ;
        memset(dp,-1,sizeof dp) ;
        ll ans = func(0,str.size()-1) ;
        Case ;
        cout<< ans << endl ;
    }

    return 0;
}

