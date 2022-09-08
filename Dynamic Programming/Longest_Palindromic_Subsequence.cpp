#include<bits/stdc++.h>
using namespace std ;

#define     ll      long long
#define     pb      push_back
#define     ff      first
#define     ss      second

const int lim = 1e3 + 5 ; 

string str ;
int dp[lim][lim] ;
int n ;

int func(int i,int j){
    if(i == j) return 1 ;
    if(i > j) return 0 ;
    int &ans = dp[i][j] ;
    if(ans != -1) return ans ;

    ans = 0 ;
    if(str[i] == str[j]) ans = 2 + func(i+1, j-1) ;
    else ans = max(func(i+1, j), func(i, j-1)) ;
    return ans ;
}


int main(){
    cin>> str ;
    n = str.size() ;

    memset(dp, -1, sizeof dp) ;
    cout<< func(0, n-1) << "\n" ;

    /*
                    ----Iterative Way----
                    
        memset(dp, 0, sizeof dp) ;
        int ans = 0 ;
        for(int i = 1; i <= n; i++){
            for(int j = n; j >=i; j--){
                if(i == j) dp[i][j] = dp[i-1][j+1] + 1 ;
                else if(str[i-1] == str[j-1]) dp[i][j] = dp[i-1][j+1] + 2 ;
                else dp[i][j] = max(dp[i-1][j], dp[i][j+1]) ;
                ans = max(ans, dp[i][j]) ;
            }
        }

        cout<< ans << "\n" ;
    */

    
    return 0 ;
}