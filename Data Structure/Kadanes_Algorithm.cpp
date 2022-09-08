#include<bits/stdc++.h>
using namespace std ;

/*
    This is Kadane's algorithm .
    This will find largest sum sub array
    from an array .
    so we need just sum of contigous element
    but if we get less sum than previous
    then we will not pick that sub array .
    And after each iteration we will update
    max sum value .

*/


int main(){
    int n ;
    cin>> n ;

    vector<int> arr(n) ;
    for(int i=0; i<n; i++) cin>> arr[i] ;

    int sum = 0 , mx = -1e9 ;   // mx = negative INF to pick atleast one element
    for(int i=0; i<n; i++){
        sum = sum + arr[i] ;
        mx = max(mx, sum) ;
        sum = max(sum , 0) ;
    }

    cout<< mx << "\n" ;     
    
    return 0 ;
}