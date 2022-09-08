#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/// By prime factorize a number it form as
/// p1^a1, p2^a2, p3^a3 ....where p1,p2,p3 are primes
/// NOD(n)-> (a1+1) * (a2+1) * (a3+1) ...(ak+1)
/// SOD(n)-> (p1^(a1+1)-1)/(p1-1) * (p2^(a2+1)-1)/(p2-1) * ...(pk^(ak+1)-1)/(pk-1)

ll const lim = 1e5+5 ;
bool mark[lim] ;
vector<int> primes ;

/// O(nloglogn)
void sieve(){
    primes.push_back(2) ;
    for(ll i=4; i<lim; i+=2) mark[i] = true ;
    for(ll i=3; i<lim; i+=2){
        if(mark[i]) continue ;
        primes.push_back(i) ;
        for(ll j=i*i; j<lim; j+=2*i)
            mark[j] = true ;
    }
}

/// O(logn)
int NOD(int n){
    int ans=1 ;
    for(ll i=0; i<primes.size()&&primes[i]*primes[i]<=n; i++){
        if(n%primes[i]) continue ;
        ll p = primes[i], cnt = 0 ;
        while(n%p == 0){
            cnt++ ;
            n /= p ;
        }
        ans *= (cnt+1) ;
    }
    if(n>1) ans *= 2LL ;
    return ans ;
}
/// O(logn)
int SOD(int n){
    ll ans = 1 ;
    for(ll i=0; i<primes.size()&&primes[i]*primes[i]<=n; i++){
        if(n%primes[i]) continue ;
        ll p = primes[i], cnt = 0 ;
        while(n%p == 0){
            cnt++ ;
            n /= p ;
        }
        ans *= (pow(i,cnt+1) - 1)/(i-1) ;
    }
    if(n>1) ans *= ((n*n) - 1)/(n-1) ;
    return ans ;
}


int main(){

    int t ;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;
        cout<< NOD(n) << endl ;
        cout<< SOD(n) << endl ;
    }

    return 0 ;
}
