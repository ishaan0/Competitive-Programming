#include<bits/stdc++.h>
using namespace std ;

/**
    In an array there are total 2^n subset .
    We will use bit mask to get subset .
    also called inclusion exclusion .
*/


int main(){

    char arr[] = {'a','b','c','d'} ;
    int n = 4 ;

    for(int mask=0; mask<(1<<n); mask++){    /// 1<<n = 2^n
        for(int i=0; i<n; i++){
            int pos = 1<<i ;
            if((mask & pos))
                cout<< arr[i] ;
        }
        cout<< endl ;
    }

    return 0 ;
}

