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

int arr1[110],arr2[110] ;
int dp[110][110] ;
int n1,n2 ;

int lcs(){
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(arr1[i-1] == arr2[j-1])
                dp[i][j] = 1+dp[i-1][j-1] ;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
        }
    }
    return dp[n1][n2] ;
}



//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int cs=0 ;
    while(cin>> n1>> n2){
        if(n1==0 && n2==0)
            break ;
        memset(arr1,0,sizeof arr1) ;
        memset(arr2,0,sizeof arr2) ;
        memset(dp,0,sizeof dp) ;

        for(int i=0; i<n1; i++)
            cin>> arr1[i] ;
        for(int i=0; i<n2; i++)
            cin>> arr2[i] ;
        int ans = lcs() ;
        cout<< "Twin Towers #" << ++cs << endl ;
        cout<< "Number of Tiles : " << ans << endl ;
        cout<< endl ;
    }

    return 0;
}


