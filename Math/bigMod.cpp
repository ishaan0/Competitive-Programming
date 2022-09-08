#include<bits/stdc++.h>
using namespace std ;

/// a^p % m
/// big mod recursive ...
int bigMod(int a ,int p ,int m){
    if(p == 0) return 1 ;
    if(p & 1)
        return ((a%m)*bigMod(a,p-1,m))%m ;
    else{
        int temp = bigMod(a,p/2,m) ;
        return (temp*temp)%m ;
    }
}

/// bigMod without recursive in Exponential method ...
ll binpow(ll a,ll b,ll m){
    a %= m ;
    ll res= 1 ;

    while(b>0){
        if(b&1) res = (res * a) % m ;
        a = (a * a) % m ;
        b >>= 1 ;
    }

    return res ;
}

int main(){


    return 0 ;
}

