#include<bits/stdc++.h>
using namespace std ;

#define ll long long

/// return sum of all pair XOR in O(n) time
ll getSumXor(int arr[], int sz){
    ll sum = 0 ;
    for(int i=0; i<32; i++){
        ll indSum = 0 ;
        ll zero = 0, one = 0 ;

        for(int j=0; j<sz; j++){
            if(arr[j]%2 == 0) zero++ ;
            else one++ ;
            arr[j] /= 2 ;
        }
        indSum = one*zero*(1<<i) ;
        sum += indSum ;
    }
    return sum ;
}


int main(){


    return 0 ;
}
