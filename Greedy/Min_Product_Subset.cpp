#include<bits/stdc++.h>
using namespace std ;

/**
    If I need a subset of min product
    then I choose only non zero number
    if have no negative number and at least
    have one zero then the ans is zero or
    I have no negative number and no zero then
    ans will be minimum pos number . Or I have
    negative number but I can't pick even number
    of them so divide the product by max neg number
    I will get my result .
*/

int main(){
    int arr[] = { -1, 0, -2, 4, 3 } ;
    int n = 5, mxNeg = INT_MIN, mnPos = INT_MAX ;
    int cntZ = 0,cntN = 0, cntP = 0 ;
    int prod = 1 ;

    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            cntZ++ ;
            continue ;
        }
        if(arr[i] < 0)
            mxNeg = max(mxNeg,arr[i]), cntN++ ;
        if(arr[i] > 0)
            mnPos = min(mnPos,arr[i]), cntP++ ;
        prod *= arr[i] ;
    }

    if(cntN == 0 && cntZ > 0)
        prod = 0 ;
    else if(cntN == 0)
        prod = mnPos ;
    else if(cntN !=0 && cntN%2==0)
        prod /= mxNeg ;

    cout<< prod << endl ;

    return 0 ;
}
