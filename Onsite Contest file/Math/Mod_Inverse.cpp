#include<bits/stdc++.h>
using namespace std ;


// Using Fermet's little theorem : a^(m-2) = 1/a mod m, where m is prime
long long invMod(long long a,long long mod){
    return bigMod(a, mod-2, mod) ;
}

// Using Euler Totient : a^(phi(mod)-1) = 1/a mod m, where a and m are co prime
long long invMod(long long a,long lond mod){
    assert(__gcd(a, mod) == 1) ;
    return bigMod(a, phi(mod)-1, mod) ;
}

// Using egcd : ax + by = gcd(a, b), here b = mod and x is the inverse modulo
long long invMod(long long a,long long mod){
    long long x, y, g ;
    g = egcd(a, mod, x, y) ;
    assert(g == 1) ;
    return (x%mod + mod) % mod ;
}



int main(){



    
    return 0 ;
}