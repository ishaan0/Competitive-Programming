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
ll n,arr[25][5],dp[25][5] ;

ll func(ll i,ll last){
    if(i>n) return 0 ;
    ll &ans = dp[i][last] ;
    if(ans != -1) return ans ;
    ans = INT_MAX ;
    for(int k=1; k<=3; k++)
        if(k != last)
        ans = min(ans,func(i+1,k)+arr[i][k]) ;
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

    int t,cs=0 ;
    cin>> t ;

    while(t--){
        memset(arr,0,sizeof arr) ;
        memset(dp,-1,sizeof dp) ;
        cin>> n ;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=3; j++)
                cin>> arr[i][j] ;
        ll ans = func(1,0) ;
        Case ;
        cout<< ans << endl ;
    }

    return 0;
}



