#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/// We will calculate prime factorize for N!

/// need to store all prime till N by sieve method
vector<int> primes ;


/// Here we can freq of a prime in logn time
/// this will run until all prime less than n
void factFactorize(ll n){
    for(int i=0; i<primes.size() && primes[i]<=n; i++){
        int x = n ;
        int freq = 0 ;

        while(x){               /// legendre formula 
            x /= primes[i] ;
            freq += x ;
        }
        cout<< primes[i] << " to the power " << freq << endl ;
    }
}

int main(){

    int t;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;
        cout<< "prime factorize of " << n << "! : " ;
        factFactorize(n) ;
    }

    return 0 ;
}

