#include<bits/stdc++.h>
using namespace std ;
int arr[10000],dp[10000],dir[10000] ;

/// Longest Increasing Subsequence
/// with solution print

/// Recursive in O(n^2)
int lis_recursive(int i){
    if(dp[i] != -1) return dp[i] ;
    int mx = 0 ;
    for(int j=i+1; j<n; j++){               /// index -> j > i
        if(arr[j] > arr[i]){                /// value -> arr[j] > arr[i]
            int len = lis_recursive(j) ;
            if(len > mx){                   /// max increasing sequence
                mx = len ;
                dir[i] = j ;
            }
        }
    }
    dp[i] = 1+mx ;
    return dp[i] ;
}
void solution1(int i){
    cout<< "LIS : " ;
    while(dir[i] != -1){
        cout<< arr[i] << " " ;
        i = dir[i] ;
    }
    cout<< endl ;
}


/// LIS Iterative O(n^2)
int lis_iterative(){
    memset(dp,1,sizeof dp) ;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] > arr[i] && dp[i]+1 > dp[j])
                dp[j] = dp[i] + 1 ;
        }
    }

    int mx = 0 ;
    for(int i=0; i<n; i++)
        mx = max(mx,dp[i]) ;
    return mx ;
}
void findSequence(int mx){
    int i=0 ;
    for(int j=1; j<n; j++)              /// find pos which has max length
        if(dp[j] > dp[i]) i = j ;

    int top = dp[i]-1 ;                 /// mx and top+1 are equal
    int seq[mx] ;
    seq[top] = arr[i] ;
    top-- ;

    for(int j=i-1; j>=0; j--){
        if(arr[j]<arr[i] && dp[j]==dp[i]-1){
            i = j ;
            seq[top] = arr[j] ;
            top-- ;
        }
    }

    cout<< "LIS : " ;
    for(int i=0; i<mx; i++)
        cout<< seq[i] << " " ;
    cout<< endl ;
}


int main(){

    return 0 ;
}
