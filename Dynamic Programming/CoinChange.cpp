#include<bits/stdc++.h>
using namespace std ;

int dp[1000][1000] ;
int coin[10000] ;
int n ;

/// Number of ways to make an amount by some coin...

/// variant 1
/// Can use a coin unlimited times
int ways(int i, int rem){
    if(i >= n) return (rem == 0) ;

    if(dp[i][rem] != -1) return dp[i][rem] ;
    int val1=0, val2 = 0 ;

    if(rem - coin[i] >= 0)
        val1 = ways(i,rem-coin[i]) ;    /// taking that coin
    val2 = ways(i+1,rem) ;              /// without taking coin

    dp[i][rem] = val1+val2 ;
    return dp[i][rem] ;
}

/// Variant 2
/// Can use a coin only once
int waysOne(int i, int rem){
    if(i>=n) return (rem == 0) ;
    
    if(dp[i][rem] != -1)
        return dp[i][rem] ;
    int val1 = 0, val2 = 0 ;

    if(rem - coin[i] >= 0)
        val1 = waysOne(i+1,rem-coin[i]) ;       /// taken coin
    val2 = waysOne(i+1,rem) ;                   /// not taking coin

    dp[i][rem] = val1 + val2 ;
    return dp[i][rem] ;
}

/// Variant 3
/// Total ways using K times of coin to make amount
int coinChange(int i, int rem){
    if(i>=n){
        if(rem == 0) return 1 ;
        return 0 ;
    }
    if(dp[i][rem] != -1)
        return dp[i][rem] ;
    int ans = 0 ;
    for(int j=1; j<=k; j++){
        if(rem-(coin[i]*j) >= 0)
            ans += coinChange(i+1,rem-(coin[i]*j));     /// taking k times a coin
        else break ;
    }
    ans += coinChange(i+1,rem) ;                        /// without taking

    dp[i][rem] = ans;
    return dp[i][rem] ;
}

int main(){



    return 0 ;
}
