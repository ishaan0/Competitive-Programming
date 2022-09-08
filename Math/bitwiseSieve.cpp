#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long

const ll lim = 1e8+5 ;
vector<int> primes ;
ll mark[lim/64 + 5] ;


inline ll Set(ll n, ll pos){ return n = (n | (1<<pos)) ; }

inline bool check(ll n, ll pos){ return (bool)(n & (1<<pos)) ;}

/*
    Here value / 64 -> block of that number
    ans value % 64 -> index of that block .
*/

void sieve(){
    primes.pb(2) ;
    for(ll i=4; i<lim; i+=2)
        mark[i/64] = Set(mark[i/64], i%64) ;
    for(ll i=3; i<lim; i+=2){
        if( check(mark[i/64], i%64) ) continue ;
        primes.pb(i) ;
        for(ll j=i*i; j<lim; j+=2*i)
            mark[j/64] = Set( mark[j/64],  j%64) ;
    }
}


int main(){
    sieve() ;
    

    return 0 ;
}
