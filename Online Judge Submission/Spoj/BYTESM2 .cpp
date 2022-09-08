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


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>> t ;

    while(t--){
        int h,w ;
        int arr[110][110],dp[110][110] ;
        cin>> h >> w ;
        for(int i=1; i<=h; i++)
            for(int j=1; j<=w; j++)
                cin>> arr[i][j] ;
        memset(dp,0,sizeof dp) ;
        for(int i=1; i<=h; i++)
            for(int j=1; j<=w; j++)
                dp[i][j] = arr[i][j]+ max((max(dp[i-1][j-1],dp[i-1][j])),dp[i-1][j+1]) ;

        int ans = -1 ;
        for(int i=0; i<=w; i++)
            ans = max(ans,dp[h][i]) ;
        cout<< ans << endl ;
    }


    return 0;
}

