#include<bits/stdc++.h>
using namespace std ;
#define ll long long


ll dp[2][10][85][85], lim, k ;
vector<int> digit ;

ll func(int isSmall,int pos,int rem,int digRem){
    if(pos == lim) return !(rem+digRem) ;
    ll &ans = dp[isSmall][pos][rem][digRem] ;
    if(ans != -1) return ans ;

    int last = (isSmall) ? 9 : digit[pos] ;
    ans = 0 ;

    for(int i=0; i<=last; i++)
        ans += func((isSmall | (i<digit[pos])), pos+1, (rem*10+i)%k, (digRem+i)%k) ;

    return ans ;
}

ll getCnt(ll n){
    digit.clear() ;

    while(n){
        digit.push_back(n%10) ;
        n /= 10 ;
    }
    memset(dp,-1,sizeof dp) ;
    reverse(digit.begin(),digit.end()) ;
    lim = digit.size() ;

    return func(0,0,0,0) ;
}

int main(){
    int t,cs=0;
    cin>> t ;

    while(t--){
        ll l,r ;
        cin>> l >> r >> k ;
        if(l>r) swap(l,r) ;

        cout<< "Case "<<++cs<< ": " ;
        if(k == 1) cout<< (r-l+1) << endl ;
        else if(k>81) cout<< 0 << endl ;
        else{
            ll ans = getCnt(r) - getCnt(l-1) ;
            cout<< ans << endl ;
        }

    }

    return 0 ;
}



