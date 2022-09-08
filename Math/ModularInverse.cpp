#include<bits/stdc++.h>
using namespace std ;

/// ax = 1 (mod m) ->  x = a^-1 (mod m)
/// linear algorithm .. O(m)
int modInverse(int a,int m){
    a = a%m ;
    for(int x=1;x<m;x++)
        if((a*x)%m == 1)
            return x ;
    cout<< "NOT Possible" ;
    exit(1) ;
}


int extendedGcd(int a,int b,int &x,int &y) ;
/// using extended gcd in O( logn )
int modInverseEfficient(int a,int m){
    int x,y ;
    int gcd = extendedGcd(a,m,x,y) ;
    if(gcd != 1)
        return cout<< "Not possible"<< endl , 0 ;
    return (x%m + m)%m ;

}

int extendedGcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1 ;
        y = 0 ;
        return a ;
    }

    int x1,y1 ;
    int gcd = extendedGcd(b,a%b,x1,y1) ;

    x = y1 ;
    y = x1 - y1 * (a/b) ;

    return gcd ;
}


/// using totient function a to the power (phi(m)-1)  (mod m)
/// Time : O(logn) , if totient calculated using sieve
/// Below code complexity : O( sqrt(n) ) .
double totient(int n) ;
int binPower(int a,int p) ;

int modInverseTotient(int a,int m){
    if(__gcd(a,m) != 1){
        cout<< "Not possible " << endl;
        return 0 ;
    }

    int p = (int) totient(m) - 1 ;
    return binPower(a,p)%m ;

}

double totient(int n){
    double res = n ;
    for(int i=2;i*i <= n;i++){
        if(!n%i){
            while(!n%i)
                n /= i;
            res -= (res/i) ;
        }
    }
    // if n also a prime
    if(n>1) res -= (res/n) ;
    return res ;
}

int binPower(int a,int p){
    int res = 1 ;
    while(p>0){
        if(p&1) res = res*a ;
        a = a*a ;
        p >>= 1 ;
    }
    return res ;
}



/// Using fermet little theorem when m is prime
int modInversePrime(int a,int m){
    return binPower(a,m-2)%m ;
}


int main(){

    cout<< modInverse(7,11) << endl;
    cout<< modInverseEfficient(7,11) << endl;
    cout<< modInverseTotient(7,11) << endl;

    return 0 ;
}
