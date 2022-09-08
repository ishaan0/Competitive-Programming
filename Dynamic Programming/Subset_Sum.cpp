#include<bits/stdc++.h>
using namespace std ;

bool dp1[1005][1005] ;
bool dp2[1005], vis[1005] ;
int pre[1005] ;
int arr[1005] ;  /// 1 based 


bool recursive(int i,int rem,int n){
    if(i==n) return (rem == 0) ;
    if(vis[i][rem]) return dp1[i][rem] ;
    vis[i][rem] = 1 ;

    if(rem - arr[i] >= 0)
        dp1[i][rem] |= recursive(i+1,rem-arr[i]) ; /// include element
    dp1[i][rem] |= recursive(i+1,rem) ; /// not include

    return d1[i][rem] ;
}

/// Time: O(n*m) Space: O(n*m)
bool func1(int n,int m){
    memset(dp1,0,sizeof dp1) ;
    dp1[0][0] = true ;

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(j < arr[i])
                dp1[i][j] = dp1[i-1][j] ;
            else{
                int need = j - arr[i] ;
                dp1[i][j] = dp1[i-1][j] | dp1[i-1][need] ;
            }
        }
    }
    return dp1[n][m] ;
}

/// Space optimized version
/// Time: O(n*m) Space: O(n)
bool func2(int n,int m){
    memset(dp2,0,sizeof dp2) ;
    dp2[0] = true ;

    for(int i=1; i<=n; i++){
        for(int j=m; j>=1; j--){
            if(j-arr[i] >= 0)
                dp2[j] = ( dp2[j] | dp2[ j-arr[i] ] ) ;
        }
    }
    return dp2[m] ;
}

/// same as func2 but solution path added
void printSolution(int n,int m){
    memset(pre,0,sizeof pre) ;
    pre[0] = 1 ;

    for(int i=0; i<n; i++){
        int cur = arr[i] ;
        for(int j=m; j>=cur; j--){
            if(pre[j] || pre[j-cur] == 0)
                continue ;
            pre[j] = cur ;
        }
    }

    if(pre[m] == 0)
        cout<< "-1"  << endl ;
    else{
        int cur = m ;
        while(cur > 0){
            cout<< pre[cur] << " " ;
            cur -= pre[cur] ;
        }
        cout<< endl ;
    }
}


int main(){



    return 0 ;
}

