#include<bits/stdc++.h>
using namespace std ;
int dp1[10000],dp2[10000][10000];

/*** problem 1: You can reach a step in stair from */

/// one step back or two step
int func1(int n){
    dp1[0] = dp1[1] =1  ;
    for(int i=2; i<=n; i++)
        dp1[i] = dp1[i-1]+dp1[i-2] ;
    return dp1[n] ;
}

/// variant 1
/// reach from k number of back step
int var1(int n){
    dp1[0] = dp1[1] = 1 ;
    for(int i=2; i<=n; i++)
        for(int j=1; j<=k && i-j>=0; j++)
            dp1[i] += dp1[i-j] ;
    return dp1[n] ;
}

/// variant 2
/// same as variant 1 but can't use
/// same step successively
/// so we need two states one is index
/// and the other is last step
int var2(int n){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=k; j++)
            for(int x=1; x<=k; x++)
            if(i-x >=0 && x!=j) dp2[i][j] += dp2[i-x][x] ;
    int ans = 0 ;
    for(int i=1; i<=k; i++)
        ans += dp2[n][i] ;
    return ans ;
}

/*** problem 2: A grid given .we need to reach */
///  (n,m) from (0,0) by moving only right and down
int n, m ;
bool ok(int i,int j) ;
int func2(){
    int dp[n][m] ;
    memset(dp,0,sizeof dp) ;
    dp[0][0] = 1 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ok(i-1,j))
                dp[i][j] += dp[i-1][j] ;    /// ways from up
            if(ok(i,j-1))
                dp[i][j] += dp[i][j-1] ;    /// ways from left
        }
    }
    return dp[n-1][m-1] ;
}
bool ok(int i,int j){
    if(i>=0 && j>=0)
        return true ;
    return false ;
}

/// can't use same move successively
int p2_var1(){
    int dp[2][n][m] ;
    memset(dp,0,sizeof dp) ;
    dp[0][0][0] = dp[1][0][0] = 1 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ok(i-1,j)){
                dp[0][i][j] += dp[1][i-1][j] ;
                dp[1][i][j] += dp[0][i-1][j] ;
            }
            if(ok(i,j-1)){
                dp[0][i][j] += dp[1][i][j-1] ;
                dp[1][i][j] += dp[0][i][j-1] ;
            }
        }
    }
    return max(dp[0][n-1][m-1],dp[1][n-1][m-1]) ;
}


int main(){


    return 0 ;
}
