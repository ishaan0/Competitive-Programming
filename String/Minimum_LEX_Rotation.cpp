#include<bits/stdc++.h>
using namespace std ;


int minLex(const char* str){
    int len = strlen(str), a, b ;
    int n = len * 2, i = 0, j = 1, k = 0 ;

    while(i+k < n && j+k < n){
        a = (i+k >= len ? str[i+k-len] : str[i+k]) ;
        b = (j+k >= len ? str[j+k-len] : str[j+k]) ;

        if(a == b) k++ ;
        else if(a > b){
            i = i + k + 1 ;
            if(i <= j) i = j + 1 ;
            k = 0 ;
        }
        else{
            j = j + k + 1 ;
            if(j <= i) j = i + 1 ;
            k = 0 ;
        }
    }

    return min(i, j) ;
}



int main(){
    string str ;
    cin>> str ;

    cout<< minLex(str.c_str()) << endl ;
    
    return 0 ;
}