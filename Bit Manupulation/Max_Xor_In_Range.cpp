#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/**
    We are given a range and need to find max
    value which is xor of a pair in this range .
    L = 8 -> (01000)
    R = 20-> (10100)
    L^R   -> (11100)
    Now if we assume L^R -> (1xxxx) form then
    our answer will be (11111) .
    So find the msb ans set all bit after that
    we will get our result .
*/

/// Time : O(logr)
int main(){
    ll l,r ;
    cin>> l >> r ;

    ll msb = log2(l^r) + 1 ;
    ll p = 1 , ans = 0 ;
    while(msb--){
        ans += p ;
        p <<= 1 ;
    }
    cout<< ans << endl ;

    return 0 ;
}
