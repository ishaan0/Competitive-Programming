#include<bits/stdc++.h>
using namespace std ;
 
#define         all(cont)       cont.begin(),cont.end()
#define         ll              long long
#define         pb              push_back
#define         ff              first
#define         ss              second
#define         nl              "\n"
 
const int lim = 3e3 + 5 ;
const ll mod = 2091573227 ;
const ll base = 1949313259 ;
 
int n, P[lim], H[lim], R[lim] ;
string str ;
 
void preCal(){
    P[0] = 1, R[0] = H[n+1] = 0 ; ;
    for(int i = 1; i <= n; i++){
        P[i] = (P[i-1] * base) % mod ;
        R[i] = ( R[i-1] * base + str[i-1] ) % mod ;
    }
    for(int i = n; i >= 1; i--){
        H[i] = ( H[i+1] * base + str[i-1] ) % mod ;
    }
}
 
int range_hash(int l,int r){
    int hash_val = (H[l+1] - ((long long)P[r-l+1] * H[r+2])%mod ) % mod ;
    hash_val = (hash_val + mod) % mod ;
    return hash_val ;
}
 
int reverse_hash(int l,int r){
    int hash_val = (R[r+1] - ((long long)P[r-l+1] * R[l])%mod ) % mod ;
    hash_val = (hash_val + mod) % mod ;
    return hash_val ;
}
 
 
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) ;
 
    int t ;
    cin>> t ;
 
    while(t--){
        cin>> str ;
        n = str.size() ;
        preCal() ;
 
        int ans = 1, d1 = 1, d2 = 1 ;
        for(int i = 1; i < n; i++){
            int a = i - d1, b = i + d1 ;
            while(a>=0 && b<n && range_hash(a, b)==reverse_hash(a, b)){
                ans = max(ans, b - a + 1) ;
                d1++ ;
                a = i - d1 , b = i + d1 ;
            }
        }

        for(int i = 0; i < n; i++){
            int a = i - d2 + 1, b = i + d2 ;
            while(a>=0 && b<n && range_hash(a, b)==reverse_hash(a, b)){
                ans = max(ans, b - a + 1) ;
                d2++ ;
                a = i - d2 + 1 , b = i + d2 ;
            }
        }
            
        int cnt = 0 ;
        for(int i = 0; i + ans - 1 < n; i++){
            if(range_hash(i, i+ans-1)==reverse_hash(i, i+ans-1))
                cnt++ ;
        }
 
        cout<< ans << " " << cnt << nl ;
 
    }
    
    return 0 ;
} 