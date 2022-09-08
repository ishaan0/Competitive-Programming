#include<bits/stdc++.h>
using namespace std ;
#define ll long long
/**
    some random primes
    479001599
    1979339339
    1000163491
    1000173893
    1423165193
    1423172537
    2513475829
*/

ll const m1 = 1423172537 ;
ll const b = 71 ;

/*
    hash(str) = ( str[0]*b^0 + str[1]*b^1 + str[2]*b^2 + ... + str[n-1]*b^(n-2) ) % m1 ;
*/

ll getHash(string str){
    ll h = 0 ;
    for(int i=0; i<str.size(); i++){
        h = h*b + str[i] ;
        h %= m1 ;
    }
    return h ;
}

int main(){

    return 0 ;
}
