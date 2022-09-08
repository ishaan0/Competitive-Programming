#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
    Catalan number : Cn = ( 1/(n+1) ) * (2n)C(n)
                        = (2n)C(n) - (2n)C(n+1)
                        = Sum (Ci * C(n-i)) for n >= 0 ; where i = 0,1,...,N

*/

/// Using iterative Dp
/// Time : n^2
ll catalan_iterative(ll n){
    ll cat[n+1] ;
    memset(cat, 0, sizeof cat) ;

    cat[0] = cat[1] = 1 ;
    for(ll i=2; i<=n; i++){
        for(ll j=0; j<i; j++){
            cat[i] += cat[j] * cat[i-j-1] ;
        }
    }

    return cat[n] ;
}

/// Using Binomial Coeficient
/// Time : N
ll nCr(ll n, ll r) ;
ll catalan_binomial(ll n){
    ll ans = nCr(2*n, n) ;
    ans /= (n+1) ;
    return ans ;
}

ll nCr(ll n, ll r){
    if(r > n-r)
        r = n-r ;
    ll ans = 1 ;

    for(ll i=0; i<r; i++){
        ans *= (n - i) ;
        ans /= (i + 1) ;
    }

    return ans ;
}


int main(){
    int t ;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;

        cout<< catalan_iterative(n) << endl ;
        cout<< catalan_binomial(n) << endl ;
    }

    return 0;
}

