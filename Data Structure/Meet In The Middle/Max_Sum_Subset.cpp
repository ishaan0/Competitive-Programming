#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long

/// Given an array of integer .
/// Need to find the maximum sum
/// subset having less than or
/// equal sum to S .
/// Input  : set[] = {45, 34, 4, 12, 5, 2} and S = 42
/// Output : 41

/// complexity : 2^(n/2) * n
vector<ll> arr = {45, 34, 4, 12, 5, 2} ;
vector<ll> x,y ;
ll s = 42 ;

void func(int n,int c){
    for(int i=0; i<(1<<n); i++){
        ll sum = 0 ;
        for(int j=0; j<n; j++)
            if(i & (1<<j)) sum += arr[j+c] ;
        x.pb(sum) ;
    }
}

int main(){
    int n = arr.size() ;

    func(n/2,0) ;
    func(n-(n/2),n/2) ;

    sort(y.begin(),y.end()) ;
    ll mx = 0 ;

    for(int i=0; i<x.size(); i++){
        if(x[i] <= s){
            int p = lower_bound(y.begin(),y.end(),s-x[i])-y.begin() ;
            if(p==y.size() || y[p]!=s-x[i]) p-- ;
            mx = max(mx,x[i]+y[p]) ;
        }
    }

    cout<< mx << endl ;

    return 0 ;
}

