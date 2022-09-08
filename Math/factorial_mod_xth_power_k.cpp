#include<bits/stdc++.h>
using namespace std ;

#define     Boost       ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)   cont.begin(), cont.end()
#define     rall(cont)  cont.rbegin(), cont.rend()
#define     ll          long long
#define     pb          push_back
#define     mp          make_pair
#define     ff          first
#define     ss          second


//  We are given N,K and we need to find largest X where N! % pow(k, x) == 0
/*
    when K is prime we can easily get x by legendre equation .
    (n/k^1) + (n/k^2) + (n/k^3) ...  (n/k^m) = x  
*/

/// get x for prime
ll get_xp(ll n, ll k){
    ll res = 0 ;
    while(n){
        n /= k ;
        res += n ;
    }
    return res ;
}

/*
    when K is a composite number . then we need prime factorization of K .
    k = k1^p1 * k2^p2 * k3^p3 .... km^pm .
    so we need to get result for all k means k1 to km , let those are 
    a1 , a2, a3 ... am . so required X will be
    min of all (ai / pi) for all i from 1 to m .
*/
bool isPrime[10000] ;
vector<pair<int,int> > factor ;

ll get_x(ll n, ll k){
    if(isPrime[k]) return get_xp(n,k) ;
    ll mn = 1e18 ;
    for(int i=0; i<factor.size(); i++){
        ll a = get_xp(n, factor[i].ff) ;
        mn = min(mn, a/factor[i].ss) 
    }
    return mn ;
}


int main(){
    Boost ;

    int t ;
    cin>> t ;

    while(t--){
        ll n, k ;
        cin>> n >> k ;
        cout<< get_x(n, k) << "\n" ;
    }

    
    return 0 ;
}