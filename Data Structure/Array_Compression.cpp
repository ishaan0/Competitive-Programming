#include<bits/stdc++.h>
using namespace std ;

/**
    From a given a array we have to tell
    every values first occurrence index
    on unique value of the array .

    we used array compression to get
    those unique value index .
*/

int main(){
    int n ;
    cin>> n ;
    vector<int> arr(n),compressed(n) ;
    for(int i=0; i<n; i++)
        cin>> arr[i] ;

    map<int,int> m ;
    int new_val = 0 ;
    for(int i=0; i<n; i++){
        if(!m.count(arr[i]))
            m[ arr[i] ] = ++new_val ;
        compressed[i] = m[ arr[i] ] ;
    }

    for(int i=0; i<n; i++)
        cout<< compressed[i] << " " ;
    cout<< endl ;

    return 0 ;
}
