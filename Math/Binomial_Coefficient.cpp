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


// basic nCr bruteforce approach .
// complexity : O( n + r )
ll basic_nCr(ll n, ll r){
    double res = 1 ;

    for(ll i=1; i<=r; i++){
        double tmp = (double)(n-r+1)/(double)i ;
        res *= tmp ;
    }
    return (ll)(res+1e-9) ; // adding eps for precission error .
}


// we can use pascal triangle to calculate nCr using dp .
// complexity : O( n * r )
void preCal_nCr(ll n){
    ll dp[n+1][n+1] ;
    memset(dp, 0, sizeof dp) ;

    for(int i=0; i<=n; i++){
        dp[i][0] = 1 ;
        for(int j=1; j<=i; j++)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] ;
    }
}


// we can calculate nCr mod p , where p is a prime
// complexity : O(n) ;
const ll p = 1e9+7 ;
int fact[100005] , inv[100005] ;

void preCal(ll n){
    fact[0] = 1 ;
    for(ll i=1; i<=n; i++) fact[i] = (fact[i-1] * i) % p ;
    inv[n] = bigMod(fact[n], p-2) ;
    for(ll i=n-1; i>=0; i--) inv[i] = (inv[i+1] * (i+1)) % p ;
}
inline ll nCr(ll n, ll r){
    if(r>=n) return (n==r) ;
    return ( ((1LL*fact[n]*inv[n-r]) % p)*(1LL*inv[r]) ) % p ; // nCr = n!/( (n-r)!*r! )
}


/*
    when n and r are very large means <= 1e18 but the modulo is small 1e6 and prime 
    we can use Lucas theorem here . For C(n, r) % p , where n,r <= 1e18 and p <= 1e6 and prime .
    we need to convert n and r to p base number then 
    n = n1 n2 n3 n4 ... nx , here n1 , n2 .. nx are digit of n in p base 
    r = r1 r2 r3 r4 ... rx , here x1, r2  .. rx are digit of r in p base
    C(n, r) % p = C(n1, r1) * C(n2, r2) * C(n3, r3) .... * C(nx, rx) % p
*/

vector<ll> convert_base(ll n, ll b){
    vector<ll> res ;
    while(n!=0){
        res.pb(n%b) ;
        n /= b ;
    }
    return res ;
}

ll nCr_lucas_theorem(ll n,ll r){
    vector<ll> vn = convert_base(n, p) ;    // here vn size will be maximum logp(n) .
    vector<ll> vr = convert_base(r, p) ;
    while(vn.size() < vr.size()) vn.pb(0) ; // set extra zero to make length equal
    while(vr.size() < vn.size()) vr.pb(0) ;
    reverse(all(vn)) ;
    reverse(all(vr)) ;

    ll ans = 1 ;
    for(int i=0; i<vn.size(); i++)
        ans = (ans * nCr(vn[i], vr[i])) % p ;
    
    return ans ;
}

int main(){
    Boost ;

    

    
    return 0 ;
}