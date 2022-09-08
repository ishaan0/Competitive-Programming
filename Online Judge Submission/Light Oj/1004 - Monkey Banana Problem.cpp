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
int arr[200][200] ;
int n,dp[200][200] ;

int func(int i,int j){
    if(i>=0 && i<2*n-1 && j>=0 && j<n){
        int &ans = dp[i][j] ;
        if(ans != -1) return ans ;
        ans = func(i+1,j) + arr[i][j] ;
        if(i<n-1)
            ans = max(ans,func(i+1,j+1) + arr[i][j]) ;
        else
            ans = max(ans,func(i+1,j-1) + arr[i][j]) ;
        return ans ;
    }
    return 0 ;
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
    cin>> t  ;

    while(t--){
        memset(arr,0,sizeof arr) ;
        memset(dp,-1,sizeof dp) ;
        cin>> n ;
        for(int i=0; i<2*n-1; i++){
            if(i<n)
                for(int j=0; j<=i; j++)
                    cin>> arr[i][j] ;
            else for(int j=0; j<2*n-i-1; j++)
                    cin>> arr[i][j] ;
        }

        int ans = func(0,0) ;
        Case ;
        cout<< ans << endl ;
    }

    return 0;
}



