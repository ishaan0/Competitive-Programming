#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/// Find number of zeroes in given range
/// Source: http://shakilcompetitiveprogramming.blogspot.com/2015/09/digit-dp.html
/// Problem: LightOJ - 1140 (How Many Zeroes)

ll dp[2][2][20][20], lim ;
vector<int> digit ;

ll func(int isSmall,int isStart,int pos,int zero){
    if(pos == lim) return zero ;
    ll &ans = dp[isSmall][isStart][pos][zero] ;
    if(ans != -1) return ans ;

    int last = (isSmall) ? 9 : digit[pos] ;
    ans = 0 ;

    if(!isStart){
        for(int i=0; i<=last; i++)
            ans += func((isSmall | (i<digit[pos])),0, pos+1, (i==0)+zero) ;
    }
    else{
        for(int i=1; i<=last; i++)
            ans += func((isSmall | (i<digit[pos])),0, pos+1, (i==0)+zero) ;
        ans += func(1,1,pos+1,0) ;
    }

    return ans ;
}

ll countZero(ll n){
    if(n<0) return 0 ;
    else if(n<=9) return 1 ;

    digit.clear() ;

    while(n){
        digit.push_back(n%10) ;
        n /= 10 ;
    }
    memset(dp,-1,sizeof dp) ;
    reverse(digit.begin(),digit.end()) ;
    lim = digit.size() ;

    return func(0,1,0,0)+1 ;
}

int main(){
    int t,cs=0;
    cin>> t ;

    while(t--){
        ll l,r ;
        cin>> l >> r ;
        ll ans = countZero(r) - countZero(l-1) ;
        cout<< "Case "<<++cs<< ": " << ans << endl ;
    }

    return 0 ;
}

