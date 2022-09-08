#include<bits/stdc++.h>
using namespace std ;

/*  phi(n) -> n * (1 - 1/p1) * (1 - 1/p2) * ..... * (1 - 1/pk)
           -> n * (p1-1)/p1  * (p2-1)/p2  * ..... * (pk-1)/pk
*/

int phi(int n){
    int res = n ;
    for(int i = 2; (long long)i*i <= n; i++){
        if(n % i) continue ;
        while(n%i == 0) n /= i ;
        res = (res/i) * (i - 1) ;
    }
    if(n > 1) res = (res/n) * (n-1) ;
    return res ;
}


int main(){
    
    for(int i = 1; i < 20; i++)
        printf("Phi(%d) = %d\n", i, phi(i)) ;
    
    
    return 0 ;
}