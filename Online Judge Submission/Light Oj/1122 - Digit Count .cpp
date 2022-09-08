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

ll dp[12][12],arr[12];
ll n,m ;

ll func(ll cnt,ll last){
    if(cnt == n) return 1;
    ll &ans = dp[cnt][last] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    for(ll i=0; i<m; i++)
        if(last == 0 || abs(arr[i]-last)<=2)
            ans += func(cnt+1,arr[i]) ;
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

    ll t,cs=0;
    cin>> t ;

    while(t--){
        memset(dp,-1,sizeof dp) ;
        cin>> m >> n ;
        for(int i=0; i<m; i++)
            cin>> arr[i] ;
        ll ans = func(0,0) ;
        Case ;
        cout<< ans << endl ;
    }


    return 0;
}





