#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e6 + 5 ;
bitset<lim> mark ;
vector<int> primes ;
int spf[lim] ; // spf[i] = smallest prime factor of i

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


// work in sqrt(primes number count)
vector<pair<int,int> > factorize(int n){
    vector<pair<int,int> > factors ;
    for(int p: primes){
        if((long long)p * p > n) break ;
        int cnt = 0 ;
        while(n % p == 0){
            n /= p ;
            cnt++ ;
        }
        if(cnt > 0)
            factors.push_back( {p, cnt} ) ;
    }
    if(n > 1) factors.push_back( {n, 1} ) ;
    return factors ;
}

// work in sqrt(n) , we can use it without sieve
vector<pair<int,int> > factorize(int n){
    vector<pair<int,int> > factors ;
    int cnt = 0 ;
    while(n % 2 == 0){
        n /= 2 ;
        cnt++ ;
    }
    if(cnt > 0) factors.push_back( {2, cnt} ) ;

    for(int i = 3; (long long)i*i <= n; i += 2){
        cnt = 0 ;
        while(n % i == 0){
            n /= i ;
            cnt++ ;
        }
        if(cnt > 0)
            factors.push_back( {i, cnt} ) ;
    }
    if(n > 1) factors.push_back( {n, 1} ) ;
    return factors ;
}


// we need to call sieve first to call those factorization function
int main(){
    


    
    return 0 ;
}