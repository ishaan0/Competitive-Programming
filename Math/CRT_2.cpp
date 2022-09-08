#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define ff first
#define ss second
#define pll pair<ll,ll> 

/*
    This is generalized form of crt
    Here mod's doesn't need to be co-prime
    but this can be used for co-prime moduli also .
    the only problem is overflow .
*/
vector<pll > equation ;

pll CRT(){
    if(equation.size() == 0) return {-1,-1} ;

    ll a1 = equation[0].ff ;
    ll m1 = equation[0].ss ;
    a1 %= m1 ;

    for(int i=1; i<equation.size(); i++){
        ll a2 = equation[i].ff ;
        ll m2 = equation[i].ss ;

        ll g,p,q ;
        ll g = __gcd(m1,m2) ;
        if(a1%g != a2%g) return {-1,-1} ;

        egcd(m1/g, m2/g, p, q) ;
        ll mod = m1 / g  * m2 ;

        /// This might get overflow .
        ll x =( (a1 * (m2/g)%mod * q%mod) + (a2 * (m1/g)%mod * p%mod) ) % mod ;
        if(x < 0) x += mod ;
        a1 = x ;
        m1 = mod ;
    }

    return {a1,m1} ;
}


int main(){
    
    

    return 0 ;
}