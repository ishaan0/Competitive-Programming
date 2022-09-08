#include<bits/stdc++.h>
using namespace std ;
const double eps = 1e-9 ;

int numberOfDigit(double n){
    int cnt = log10(n) + 1.0 + eps ;
    return cnt ;
}

int factorialDigit(int n){
    double cnt = 0 ;
    for(double i=1; i<=n; i++)
        cnt += log10(i) ;
    int res = cnt + 1.0 + eps ;
    return res ;
}

/// we can use above factorial digit count
/// method for any base . But c++ only
/// support log2 and log10 . So we need
/// to apply formula logb(x) = (log10(x))/(log10(b))

int factorialDigitBase(int n,int base){
    double cnt =0 ;
    for(int i=1; i<=n; i++)
        cnt += log10(i)/log10(base) ;
    int res = cnt + 1.0 + eps ;
    return res ;
}

int main(){


    return 0 ;
}
