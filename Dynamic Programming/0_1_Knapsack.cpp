#include<bits/stdc++.h>
using namespace std ;
#define lim 10000

/*
    Taking element in such a way that
    we get maximum price and weight 
    will be in our capacity .
*/

int n,cap;
int price[lim],weight[lim] ;
int dp[lim][lim] ;

/// Time  : n*cap
/// Space : n*cap
int knapsack(int i,int w){
    if(i == n) return 0 ;
    int &ans = dp[i][w] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    if(w+weight[i] <= cap)
        ans = price[i]+knapsack(i+1,w+weight[i]) ;   /// Taking that element
    ans = max(ans,knapsack(i+1,w)) ;        /// Without taking that element
    return ans ;
}

/// Space optimized Knapsack but time complexity remain same .
/// Time  : n*cap
/// Space : cap
int knapsack_iterative(){
    int dp2[lim] ;
    memset(dp2, 0, sizeof dp2) ;

    for(int i=0; i<n; i++){
        for(int j=cap; j>=weight[i]; j--){
            dp2[j] = max(dp2[j], price[i]+dp2[j - weight[i]]) ;
        }
    }
    return dp2[cap] ;
}

int main(){

    memset(dp,-1,sizeof dp) ;
    cin>> n >> cap ;
    for(int i=0; i<n; i++)
        cin>> price[i] >> weight[i] ;
    int ans = knapsack(0,0) ;
    cout<< ans << endl ;

    return 0 ;
}
