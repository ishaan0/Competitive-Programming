#include<bits/stdc++.h>
using namespace std ;


const int lim = 1e7 + 5 ;

bitset<lim> mark ;
vector<int> primes ;

void sieve(){
    mark[0] = mark[1] = 1, primes.push_back(2) ;
    for(int i = 4; i < lim; i += 2) mark[i] = 1 ;
    for(int i = 3; i < lim; i += 2){
        if(mark[i]) continue ;
        primes.push_back(i) ;
        if(i*1LL*i >= lim) continue ;
        for(int j = i * i; j < lim; j += 2*i)
            mark[j] = 1 ;
    }
}

int main(){

    sieve() ;

    
    return 0 ;
}