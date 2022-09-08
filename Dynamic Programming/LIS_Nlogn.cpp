#include<bits/stdc++.h>
using namespace std ;
#define lim 10000
int arr[lim], f[lim] ;

int lis(){
    vector<int> dp ;
    for(int i=0; i<lim; i++){
        auto it = lower_bound(dp.begin(),dp.end(),arr[i]) ; /// use upper_bound for
                                                            /// non decreasing order
        if(it == dp.end()) dp.push_back(arr[i]) ;
        else dp[it-dp.begin()] = arr[i] ;
    }
    return dp.size() ;
}

void lis_print(){
    vector<int> dp ;
    for(int i=0; i<lim; i++){
        f[i] = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin() ;
        if(f[i] == dp.size()) dp.push_back( arr[i] ) ;
        else dp[ f[i] ] = arr[i] ;
        f[i]++ ;    /// LIS from 0 - i for ith element include
    }
    int x = dp.size() ;
    vector<int> lis ;
    for(int i=lim-1; i>=0; i--){
        if(f[i] == x){
            lis.push_back( arr[i] ) ;
            x-- ;
        }
    }
    reverse(lis.begin(), lis.end()) ;
}


int main(){


    return 0 ;
}
