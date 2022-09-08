#include<bits/stdc++.h>
using namespace std ;

/*
    z[i] -> longest string start from i which is also
            prefix of that string
    Time : O(n), where n is the size of string
*/


vector<int> z_function(string str){
    int lo = 0, hi = 0, n = str.size() ;
    vector<int> z(n) ;

    for(int i=1; i<n; i++){
        if(i <= hi) z[i] = min(z[i - lo], hi - i + 1) ;
        while(i+z[i] < n && str[ z[i] ] == str[ i + z[i] ])
            z[i]++ ;
        if(i+z[i]-1 > hi) lo = i , hi = i+z[i]-1 ;
    }

    return z ;
}


int main(){
    string str = "abcxyabcxabcxya" ;

    vector<int> z = z_function(str) ;

    for(int el: z) cout<< el << " " ;
    cout<< "\n" ;
    
    return 0 ;
}