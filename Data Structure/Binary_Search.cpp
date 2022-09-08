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

/*
    Some types of way to code Binary Search .
*/


ll n, x ;
vector<ll> arr ;

ll B_srch1(){
    ll lo = 0 , hi = n-1, ans = -1 ;
    while(hi <= lo){
        ll mid = lo + (hi-lo)/2LL ;
        if(arr[mid] <= x) ans = mid , lo = mid + 1 ;
        else hi = mid - 1 ;
    }
    return ans ;
}

ll B_srch2(){
    ll lo = 0 , hi = n-1 ;
    while(hi < lo){
        ll mid = lo + (hi-lo+1)/2LL ;
        if(arr[mid] <= x) lo = mid ;
        else hi = mid - 1 ;
    }
    return lo ;
}

ll B_srch3(){
    ll lo = 0 , hi = n-1 ;
    while(hi < lo){
        ll mid = lo + (hi-lo)/2LL ;
        if(arr[mid] >= x) hi = mid ;
        else lo = mid + 1 ;
    }
    return hi ;
}

double B_srch4(){
    double lo = 1 , hi = 1e9 ;
    for(int i=0; i<100; i++){
        double mid = lo + (hi-lo)/2.0 ;
        if((mid*mid)-x <= 1e-9) lo = mid
        else hi = mid ;
    }
    return lo ;
}


int main(){
    Boost ;


    
    return 0 ;
}