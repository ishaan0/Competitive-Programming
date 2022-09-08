#include<bits/stdc++.h>
using namespace std ;


const int lim = 1e6 + 5 ;

vector<int> primes ;
int spf[lim] ;  // spf[i] = smallest prime factor of i

void sieve(){
    primes.push_back(2) ;
    for(int i = 1; i < lim; i++) spf[i] = i ;
    for(int i = 4; i < lim; i += 2) spf[i] = 2 ;
    for(int i = 3; i < lim; i += 2){
        if(spf[i] != i) continue ;
        primes.push_back(i) ;
        if(i*1LL*i >= lim) continue ;
        for(int j = i*i; j < lim; j += 2*i){
            if(spf[j] == j) spf[j] = i ;
        }
    }
}

// factorize in logn time if n <= 10^7
vector<pair<int,int> > factorize(int n){
    int cnt = 0 ;
    vector<pair<int,int> > factors ;
    while(spf[n] > 1){
        cnt++ ;
        int prev = spf[n] ;
        n /= spf[n] ;
        if(spf[n] != prev){
            factors.push_back({prev, cnt}) ;
            cnt = 0 ;
        }
    }
    return factors ;
}

int main(){

    sieve() ;

    
    return 0 ;
}