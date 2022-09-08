#include<bits/stdc++.h>
using namespace std ;



int main(){
    int arr[] = { -1, 0, -2, 4, 3 } ;
    int n = 5, mxNeg = INT_MIN ;
    int cntZ=0, cntN=0, prod = 1;

    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            cntZ++ ;
            continue ;
        }
        if(arr[i] < 0){
            mxNeg = max(mxNeg,arr[i]) ;
            cntN++ ;
        }
        prod *= arr[i] ;
    }

    if(cntZ == n) prod = 0 ;
    else if(cntN & 1){
        if(cntN==1 && cntZ>0 && cntN+cntZ==n) prod = 0 ;
        else prod /= mxNeg ;
    }

    cout<< prod << endl ;

    return 0 ;
}

