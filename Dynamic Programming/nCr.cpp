#include<bits/stdc++.h>
using namespace std ;
#define lim 10000

int dp[lim][lim] ;

/// Recursive
int nCr(int n,int r){
    if(r > n) return 0 ;
    else if(r == 0 || n == r) return 1 ;
    int &ans = dp[n][r] ;
    if(ans != -1) return ans ;
    ans = nCr(n-1,r) + nCr(n-1,r-1) ;
    return ans ;
}


/**
1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5   10  10  5   1

*/
/// Iterative
int nCr_it(int n,int r){
    for(int row=0; row<=n; row++){
        dp[row][0] = dp[row][row] = 1 ; /// pascal triangle edge 1's
        for(int col=1; col<row; col++)
            dp[row][col] = dp[row-1][col]+dp[row-1][col-1] ;
    }
    return dp[n][r] ;
}



int main(){

    int n,r ;
    cin>> n >> r;
    memset(dp,-1,sizeof dp) ;
    cout<< nCr(n,r) << endl ;

    return 0 ;
}

