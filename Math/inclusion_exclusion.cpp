#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/*
    Inclusion Exclusion Principle
    (A u B u C) = A + B + C - (A ^ B) - (B ^ C) - (C ^ A) + (A ^ B ^ C)
    If we pick odd number of element then add it otherwise deduct it
*/

/*
    problem : How many numbers from 1 to n which are divisible
              by alteast one element of an array .
*/

int main(){
    ll n , m ;
    cin>> n >> m ;

    vector<ll> arr(m) ;
    for(int i=0; i<m; i++) cin>> arr[i] ;

    ll ans = 0 ;
    for(int i=1; i<(1<<m); i++){
        ll val = 1 ;
        for(int j=0; j<m; j++){
            if((1<<j) & i)
                val *= arr[j] ;
        }

        if(__builtin_popcount(i) & 1) ans += (n/val) ;
        else ans -= (n/val) ; 
    }

    cout<< ans << endl ;

    return 0 ;
}