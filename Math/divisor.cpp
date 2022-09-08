#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/// get divisor of one number

vector<int> divisors ;

void getDiv(ll n){
    for(ll i=1; i*i<=n; i++){
        if(n%i != 0) continue ;
        if(n%i == i) divisors.push_back(i) ;
        else{
            divisors.push_back(i) ;
            divisors.push_back(n/i) ;
        }
    }
}

int main(){


    return 0 ;
}

