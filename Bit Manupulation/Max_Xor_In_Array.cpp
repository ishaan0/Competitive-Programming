#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/**
    We are given a array and need to find max
    value which is xor of a pair in this array .
*/

/// Time: O(nlogn)

int main(){
    ll arr[] = {25, 10, 2, 8, 5, 3} ;
    ll n = 6 ;

    ll mx = 0, mask = 0 ;
    for(int i=30; i>=0; i--){
        set<ll> s ;
        mask |= (1LL<<i) ;
        for(int j=0; j<n; j++)
            s.insert(mask ^ arr[j]) ;

        ll newMax = mx | (1<<i) ;
        for(auto val: s){
            if(s.count(val ^ newMax)){
                mx = newMax ;
                break ;
            }
        }
    }

    return 0 ;
}

