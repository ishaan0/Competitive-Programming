#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long

ll const lim = 1e3+5 ;
int spf[lim] ; /// smallest prime factors
vector<int> primes ;

void linear_sieve(){
    for(int i = 2; i < lim; i++){
        if(spf[i] == 0){
            spf[i] = i ;
            primes.push_back( i ) ;
        }
        for(int j = 0; j < (int)primes.size() && primes[j] <= spf[i] && (long long)i*primes[j] < lim; j++)
            spf[ i * primes[j] ] = primes[j] ;
    }
}


int main(){

    linear_sieve() ;
    for(int i = 0; i < 20; i++) cout<< spf[i] << " " ;

    return 0 ;
}
