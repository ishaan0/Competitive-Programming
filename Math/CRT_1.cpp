#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pll pair<ll,ll> 

/*
    Here we are given so mod equation , we need to find x .
    x = a1 (mod m1)
    x = a2 (mod m2)
    --------------
    --------------
    x = ak (mod mk)
    where m1,m2,...,mk are co-prime to each other .
*/

vector<ll> r , m ;

void egcd(ll a, ll b, ll &x, ll &y){
    if(b==0){
        x = 1 ;
        y = 0 ;
        return ;
    }

    ll x1 , y1 ;
    egcd(b, a%b, x1, y1) ;

    x = y1 ;
    y = x1 - y1*(a/b) ;
}

ll inv(ll a,ll b){
    ll x, y ;
    egcd(a,b,x,y) ;
    return (x%b + b) % b ;
}

ll CRT(){
    ll n = r.size() ;
    ll prod = 1 ;
    for(int i=0; i<n; i++) prod *= m[i] ;

    ll ans = 0 ;
    for(int i=0; i<n; i++){
        ll pp  = prod/m[i] ;
        ll temp = (pp * r[i]) % prod ;
        temp  = ( temp * inv(pp, m[i]) ) % prod ;
        ans = (ans + temp) % prod ;
    }
    return ans ;
}


int main(){
    int n ;
    cin>> n ;

    for(int i=0; i<n; i++){
        ll a , b ;
        cin>> a >> b ;
        r.pb(a) ;
        m.pb(b) ;
    }

    cout<< CRT() << endl ;
    

    return 0 ;
}