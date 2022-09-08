#include<bits/stdc++.h>
using namespace std ;

int coin[10000] ;
int ways[10000] ;
int n ; // The amount to make
int k ; // Coin array limit

/// Number of ways to make an amount by some coin...

/// variant 1
/// Can use a coin unlimited times
int coinInfinite(int n){
    memset(ways, 0, sizeof(ways)) ;
    ways[0] = 1 ;

    for(int i=0; i<k; i++){                 /// loop on coin
        for(int amt=1; amt<=n; amt++){      /// loop on amount
            if(amt-coin[i] >= 0)
                ways[amt] += ways[amt-coin[i]] ;
        }
    }
    return ways[n] ;
}

/// Variant 2
/// Can use a coin only once
int coinFinite(){
    memset(ways, 0, sizeof(ways)) ;
    ways[0] = 1 ;

    for(int i=0; i<k; i++){
        for(int amt=n; amt>=1; amt--){
            if(amt-coin[i] >= 0)
                ways[amt] += ways[amt-coin[i]] ;
        }
    }
    return ways[n] ;
}


int main(){



    return 0 ;
}
