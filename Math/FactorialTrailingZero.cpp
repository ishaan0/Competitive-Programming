#include<bits/stdc++.h>
using namespace std ;

/// need to calculate trailing zero of n!
/// we will get it by ans = (n/5) + (n/25) + (n/125) + ... formula

int trailingZero(int n){
    int res = 0 ;
    while(n){
        n /= 5 ;
        res += n ;
    }
    return res ;
}

int main(){

    int t ;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;
        int ans = trailingZero(n) ;
        cout<< n << " has " << ans << " tailing zero." << endl ;

    }

    return 0 ;
}
