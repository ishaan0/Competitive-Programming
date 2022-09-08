#include<bits/stdc++.h>
using namespace std ;

#define     ll      long long
#define     pb      push_back
#define     ff      first
#define     ss      second

const int lim = 1e2 + 5 ; 

string str ;
int dp[lim][lim] ;
int n ;

int func(int i,int j){
    if(i >= j) return 1 ;
    int &ans = dp[i][j] ;
    if(ans != -1) return ans ;

    ans = 0 ;
    if(str[i] == str[j]) ans = func(i+1, j-1) ;
    return ans ;
}


int main(){
    cin>> str ;
    n = str.size() ;

    memset(dp, -1, sizeof dp) ;
    int ans = 0 ;
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(func(i, j)) ans = max(ans, j - i + 1) ;
        }
    }

    cout<< ans << "\n" ;

    return 0 ;
}