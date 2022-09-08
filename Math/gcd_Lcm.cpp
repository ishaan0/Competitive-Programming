#include<bits/stdc++.h>
using namespace std ;

/// gcd(a,b) = gcd(-a,b) = gcd(a,-b) = gcd(-a,-b)

/// Time : O( loga + logb )
int basicGcd(int a,int b){
    while(b!=0){
        int temp = b ;
        b = a%b ;
        a = temp ;
    }
    return a ;
}

/// Here __gcd(x,y) is library function
int lcm(int a,int b){
    return a * ( b / __gcd(a,b) ) ;     /// modified to handle overflow
}

/// Extended GCD
/// ax + bY = gcd
int egcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1 ;
        y = 0 ;
        return a ;
    }

    int x1,y1 ;
    int gcd = egcd(b,a%b,x1,y1) ;

    x = y1 ;
    y = x1 - y1 * (a/b) ;

    return gcd ;
}

template< typename T >
T egcd(T a,T b,T& x,T& y){
    x = 1, y = 0 ;
    T x1 = 0, y1 = 1, a1 = a, b1 = b ;
    while(b1){
        T q = a1/b1 ;
        tie(x, x1) = make_tuple( x1, x - q * x1 ) ;
        tie(y, y1) = make_tuple( y1, y - q * y1 ) ;
        tie(a1, b1) = make_tuple( b1, a1 - q * b1 ) ;
    }
    return a1 ;
}

int main(){


    return 0 ;
}
