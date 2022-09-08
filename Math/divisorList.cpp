#include<bits/stdc++.h>
using namespace std ;

/// get divisor of 1 to n all number

vector<int> divisors[100002] ;

void genDivisor(int n){
    for(int i=1; i<=n ;i++)
        for(int j=i; j<=n ;j+=i)
            divisors[j].push_back(i) ;
}

int main(){


    return 0 ;
}

