#include<bits/stdc++.h>
using namespace std ;

int cuts[100],dp[100][100] ;  /// cuts[] = {0,a,b,c,d,...,sz}

int rodCutting(int lo,int hi){
    if(lo+1 == hi) return 0 ;
    int &ans = dp[lo][hi] ;
    if(ans != -1) return ans ;
    ans = INT_MAX ;
    for(int i=lo+1; i<hi; i++){
        int temp = rodCutting(lo,i)+rodCutting(i,hi)+(cuts[hi]-cuts[lo]) ;
        ans = min(ans,temp) ;
    }
    return ans ;
}

int main(){
    int sz = 5 ;
    cout<< rodCutting(0,sz) << endl ;

    return 0 ;
}
