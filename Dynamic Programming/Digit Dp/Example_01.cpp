#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/// Print the sum of digit appearing between A to B
/// Here A = 10^18 , B = 10^18 .

ll dp[2][20][205], lim ;
vector<int> digit ;

ll func(int isSmall,int pos,int sum){
    if(pos == lim) return sum ;
    ll &ans = dp[isSmall][pos][sum] ;
    if(ans != -1) return ans ;

    int last = (isSmall) ? 9 : digit[pos] ;
    ans = 0 ;

    for(int i=0; i<=last; i++)
        ans += func((isSmall | (i<digit[pos])), pos+1, sum+i) ;
    return ans ;
}

ll getSum(ll n){
    digit.clear() ;

    while(n){
        digit.push_back(n%10) ;
        n /= 10 ;
    }
    memset(dp,-1,sizeof dp) ;
    reverse(digit.begin(),digit.end()) ;
    lim = digit.size() ;

    return func(0,0,0) ;
}

int main(){
    int t ;
    cin>> t ;

    while(t--){
        ll l,r ;
        cin>> l >> r ;
        ll ans = getSum(r) - getSum(l-1) ;
        cout<< ans << endl ;
    }

    return 0 ;
}
