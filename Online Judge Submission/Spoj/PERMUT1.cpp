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

int dp[15][100] ;

int func(int n,int k){
    if(n == 0) return 0 ;
    if(k == 0) return 1 ;
    int &ans = dp[n][k] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    for(int i=0; i<n&&k-i>=0; i++)
        ans += func(n-1,k-i) ;
    return ans ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t;
    cin>> t ;

    while(t--){
        memset(dp, -1, sizeof dp) ;
        int n,k ;
        cin>> n >> k ;
        int ans = func(n,k) ;
        cout<< ans << endl ;
    }

    return 0;
}

