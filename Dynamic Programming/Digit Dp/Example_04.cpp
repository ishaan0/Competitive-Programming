#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back

/// Find how many number between range a to b
/// which first and last digit are same

ll dp[2][10][10][10] , lim ;
vector<int> digit ;

ll func(int isSmall,int pos,int firstId,int lastId){
    if(pos == lim) return (firstId == lastId) ;
    ll &ans = dp[isSmall][pos][firstId][lastId] ;
    if(ans != -1) return ans ;

    int last = (isSmall) ? 9 : digit[pos] ;
    ans = 0 ;

    for(int i=0; i<=last; i++){
        int curFirst = firstId ;
        if(pos==0 || firstId==0)
            curFirst = i ;
        ans += func(isSmall | (i<digit[pos]), pos+1,curFirst,i) ;
    }
    return ans ;
}

ll getAns(ll n){
    digit.clear() ;
    while(n){
        digit.pb(n%10) ;
        n /= 10 ;
    }
    reverse(digit.begin(), digit.end()) ;
    lim = digit.size() ;
    memset(dp,-1,sizeof dp) ;
    return func(0,0,0,0) ;
}

int main(){
    int t ;
    cin>> t ;

    while(t--){
        ll l,r ;
        cin>> l >> r ;
        ll ans = getAns(r) - getAns(l-1) ;
        cout<< ans << endl ;
    }

    return 0 ;
}


