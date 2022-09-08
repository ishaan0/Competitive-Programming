#include<bits/stdc++.h>
using namespace std;
#define ll long long
/* 
    Find number of divisor for N! .
    if N! = p1 * p2 * p3 * ... * Pk ... where p is prime .
    NOD(N!) = (p1+1) * (p2+1) * (p3+1) * ... * (pk+1)
    We will find all prime factor by dividing using 
    some power of prime less than N .
    which is known as legendre formula
*/
const int lim = 1e5+5 ;
bool mark[lim] ;
vector<int> prime ;

void sieve(){
    prime.push_back(2) ;
    for(ll i=4; i<lim; i+=2) mark[i] = 1 ;
    for(ll i=3; i<lim; i+=2){
        if(mark[i]) continue ;
        prime.push_back(i) ;
        for(ll j=i*i; j<lim; j+=2*i)
            mark[j] = 1 ;
    }
}

/// legendre formula
inline ll getCnt(ll n, ll p){
    ll res = 0 ;
    while(n > 0){
        n /= p ;
        res += n ;
    }
    return res ;
}

ll NOD(ll n){
    ll ans = 1 ;
    for(ll i = 0 ; i<prime.size() && prime[i]<=n; i++){
        ll cnt = getCnt(n,prime[i]) ;
        ans *= (cnt+1) ;
    }
    return ans ;
}



int main(){
    int t ;
    cin>> t ;

    sieve() ;
    while(t--){
        int n ;
        cin>> n ;
        cout<< NOD(n) << "\n" ;
    }

    return 0;
}

