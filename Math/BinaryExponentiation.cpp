#include<bits/stdc++.h>
using namespace std;
#define ll long long


/// calculate a^b in log(n) time
ll binPowRecursion(ll a, ll b){
    if(b == 0) return 1 ;
    ll res = binPowRecursion(a,b/2) ;
    if(b&1) return res*res*a ;
    else return res*res ;
}

/// without recursion log(n) time
ll binPow(ll a,ll b){
    ll res = 1 ;
    while(b > 0){
        if( b&1 ) res = res * a ;
        a = a*a ;
        b >>= 1 ;
    }
    return res ;
}

int main(){

    return 0 ;
}
