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
#define mod 100000007

int a[55],c[55] ;
int n,k ;
int dp[55][1005] ;

int func(int i,int rem){
    if(i>=n){
        if(rem == 0) return 1 ;
        return 0 ;
    }
    int &ans = dp[i][rem] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    for(int j=1; j<=c[i]; j++){
        if(rem-(j*a[i]) >= 0)
            ans += func(i+1,rem-(j*a[i]))%mod ;
        else break ;
    }
    ans += func(i+1,rem)%mod ;
    ans = ans%mod ;
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
        cin>> n >> k ;
        for(int i=0; i<n; i++)
            cin>> a[i] ;
        for(int i=0; i<n; i++)
            cin>> c[i] ;
        memset(dp,-1,sizeof dp) ;
        int ans = func(0,k) ;
        Case ;
        cout<< ans << endl ;
    }

    return 0;
}


