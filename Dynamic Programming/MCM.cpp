#include<bits/stdc++.h>
using namespace std ;

/// Formula
/**          |  0 ; i==j
    m[i,j] = |
             |  min(m[i,k]+m[k+1,j]+p(i-1)*p(k)*p(j)) ; where i<=k<j
*/

int p[100],dp[100][100] ;

int mcm(int i,int j){
    if(i==j) return 0 ;
    int &ans = dp[i][j] ;
    if(ans != -1) return ans ;
    ans = INT_MAX ;
    for(int k=i; k<j; k++){
        int temp = mcm(i,k)+mcm(k+1,j)+(p[i-1]*p[k]*p[j]) ;
        ans = min(ans,temp) ;
    }
    return ans ;
}

int main(){

    memset(dp,-1,sizeof dp) ;
    p[0] = 3 ;
    p[1] = 2 ;
    p[2] = 4 ;
    p[3] = 5 ;
    p[4] = 6 ;
    cout<< mcm(1,4) << endl ;

    return 0 ;
}
