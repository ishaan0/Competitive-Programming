#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ;

int mob[lim] ;

/*
    mob[i] = 0 , if i has squared prime factor
    mob[i] = 1 , if it is square free and it has odd number of prime factor
    mob[i] = -1, if it is square free and it has even number of prime factor
*/

void mobius(){
    mob[1] = 1 ;
    for(int i = 1; i < lim; i++){
        for(int j = i+i; j < lim; j += i)
            mob[j] -= mob[i] ;
    }
}


int main(){



    
    return 0 ;
}