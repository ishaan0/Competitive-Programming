#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e6 + 5 ; 

int phi[lim] ;

void sievePhi(){
    for(int i = 1; i < lim; i++) phi[i] = i ;
    for(int i = 2; i < lim; i++){
        if(phi[i] != i) continue ;  // not prime
        phi[i] = i - 1 ;
        for(int j = (i<<1); j < lim; j+=i)
            phi[j] = (phi[j]/i) * (i - 1) ;
    }
}

int main(){
    sievePhi() ;

    for(int i = 1; i <= 20; i++)
        printf("Phi(%d) = %d\n", i, phi[i]) ;

    
    return 0 ;
}