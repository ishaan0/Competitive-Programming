#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/*
    From Fermat Little Theorem we know 
    a^(p-1) = 1 (mod p) , where p is a prime and 2<= a <= p-2 ;
    We can use it to find a number is prime or not .
    It is a probabilistic algorithm so it will say 
    the number is probably prime .
    some time it will detect a composite as a prime which
    is called Fermat liar .
    a is called Fermat witness . 
*/

ll bigMod(ll a, ll b,ll mod){
    a %= mod ;
    ll res = 1 ;
    while(b > 0){
        if(b & 1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        b >>= 1 ;
    }
    return res ;
}

bool probably_prime(ll n){
    if(n < 4) return (n==2 || n==3) ;

    for(int i=1; i<=10; i++){
        ll a = 2 + rand() % (n-3) ;
        if(bigMod(a, n-1, n) != 1)
            return false ;
    }
    return true ;
}


int main(){
    ll t ;
    cin>> t ;

    while(t--){
        ll n ;
        cin>> n ;
        if(probably_prime(n)) cout<< "prime" << endl ;
        else cout<< "not prime" << endl ;
    }

    return 0 ;
}