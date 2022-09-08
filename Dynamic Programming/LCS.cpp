#include<bits/stdc++.h>
using namespace std ;
#define lim 10000

int first[lim],second[lim] ;
int dp[lim][lim],dir[lim][lim];
string ans = "" ;

/// complexity O(n*m)
/// where n = first.size()
/// ans   m = second.size()

/// recursive lcs
int lcs_recursive(int i, int j){
    if(i== lim || j==lim) return 0 ;
    int &ans = dp[i][j] ;
    if(ans != -1) return ans ;
    ans = 0 ;

    if(first[i] == second[j])
        ans = 1 + lcs_recursive(i+1,j+1) ;
    else{
        int val1 = lcs_recursive(i+1,j) ;
        int val2 = lcs_recursive(i,j+1) ;
        ans = max(val1,val2) ;
    }

    return ans ;
}

/// solution print recursive
void solution_recursive(int i,int j){
    if(i==n || j==n){
        cout<< ans << endl ;
        return ;
    }
    if(first[i] == second[j]){
        ans += first[i] ;
        solution_recursive(i+1,j+1) ;
    }
    else{
        if(dp[i+1][j] > dp[i][j+1])
            solution_recursive(i+1,j) ;
        else solution_recursive(i,j+1) ;
    }
}

/// All possible solution print recursive
void solution_recursive_all(int i,int j){
    if(i==n || j==n){
        cout<< ans << endl ;
        return ;
    }
    else if(first[i] == second[j]){
        ans += first[i] ;
        solution_recursive_all(i+1,j+1) ;
        ans.pop_back() ;
    }
    else{
        if(dp[i+1][j] > dp[i][j+1])
            solution_recursive(i+1,j) ;
        else if(dp[i+1][j] < dp[i][j+1])
            solution_recursive(i,j+1) ;
        else{
            solution_recursive_all(i+1,j) ;
            solution_recursive_all(i,j+1) ;
        }
    }
}

/// Iterative LCS with solution print
void lcs_iterative_print(){
    int l1=lim,l2=lim ;             /// l1,l2 are size of first[],second[]
    memset(dir,0,sizeof dir) ;

    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(first[i-1] == second[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1 ;
                dir[i][j] = 1 ;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
                if(dp[i-1][j] > dp[i][j-1])
                    dir[i][j] = 2 ;
                else dir[i][j] = 3 ;
            }
        }
    }
    int i=l1,j=l2 ;
    while(true){
        if(dir[i][j] == 1){
            ans.push_back(first[i-1]) ;
            i-- ,j-- ;
        }
        else if(dir[i][j] == 2)
            i-- ;
        else if(dir[i][j] == 3)
            j-- ;
        else break ;
    }
    reverse(ans.begin(),ans.end()) ;
    cout<< "Size: " << ans.size() << endl ;
    cout<< "Solution: " << ans << endl ;
}

int main(){


    return 0 ;
}
