#include<bits/stdc++.h>
using namespace std ;

/**
    I am on a stair case , I need to
    tell in how many ways I can reach
    hear when I do have two move .
    1 : current + 1
    2 : current + 2
*/


int main(){

    int n ;
    cin>> n ;

    int dp[n+5] ;
    memset(dp,0,sizeof dp) ;
    dp[0] = dp[1] = 1 ;

    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2] ;

    cout<< dp[n] << endl ;

    return 0 ;
}
