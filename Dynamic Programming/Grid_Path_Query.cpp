#include<bits/stdc++.h>
using namespace std ;
#define lim 1005
#define inf 1000000000

int dp[lim][lim] ;
int dp2[lim][lim] ;
int grid[lim][lim] ;

/// We need to go from (0,0) cell to (n-1,m-1) cell
/// we do have 2 move, right and down .
/// finding total number of ways .

/// Time: O(n*m) Space: O(n*m)
int variant1(int n,int m){
    memset(dp,0,sizeof dp) ;

    dp[0][0] = grid[0][0] ;                 /// set (0,0) cell value
    for(int i=1; i<n; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0] ; /// set first column all cell
    for(int i=1; i<m; i++)
        dp[0][i] = dp[0][i-1] + grid[0][i] ; /// set first row all cell

    for(int i=1; i<n; i++)
        for(int j=1; j<m; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + grid[i][j] ;

    return dp[n-1][m-1] ;
}

/// we need to go from 1st row to nth row in min cost
/// we can start from any cell and end on any cell
/// we have three moves : right,down,left-down,right-down .

int variant2(int n,int m){
    memset(dp2,0,sizeof dp2) ;

    dp2[0][0] = grid[0][0] ;
    for(int i=1; i<m; i++)
        dp2[0][i] = dp2[0][i-1] + arr[0][i] ;
    for(int i=1; i<n; i++){
        dp2[i][0] = min({dp2[i-1][0] , dp2[i-1][1]}) + grid[i][0] ;
        dp2[i][m-1] = min({dp2[i-1][m-1] , dp2[i-1][m-2] }) + grid[i][m-1] ;
        for(int j=1; j<m-1; j++)
            dp2[i][j] = min({dp2[i][j-1], dp2[i-1][j-1], dp[i-1][j], dp[i-1][j+1]})+grid[i][j] ;
    }

    int mn = INT_MAX ;
    for(int i=0; i<m; i++)
        mn = min(mn,dp2[n-1][i]) ;
    return mn ;
}

int main(){



    return 0 ;
}


