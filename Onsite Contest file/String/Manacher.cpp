#include<bits/stdc++.h>
using namespace std ;

#define         all(cont)       cont.begin(),cont.end()
#define         ll              long long
#define         pb              push_back
#define         ff              first
#define         ss              second
#define         nl              "\n"

/*
    problem link: https://cses.fi/problemset/task/1111/
*/

/*
    d1[i] = number of odd length palindrome when i is center
    d2[i] = number of even length palindrome when i and i-1 is center
*/
vector<int> d1, d2 ; 
void manacher(string& str){
    int l = 0, r = -1, n = str.size() ;
    d1.assign(n, 0), d2.assign(n, 0) ;
    for(int i = 0; i < n; i++){
        int k = (i > r ? 1 : min(d1[l+r-i], r-i)) ;
        while(i-k >= 0 && i+k < n && str[i-k] == str[i+k]) ++k ;
        d1[i] = k-- ;
        if(i+k > r) l = i-k, r = i+k ;
    }
    l = 0, r = -1 ;
    for(int i = 0; i < n; i++) {
        int k = (i > r ? 0 : min(d2[l+r-i+1], r-i+1))+1 ;
        while(i-k >= 0 && i+k-1 < n && str[i-k] == str[i+k-1]) ++k ;
        d2[i] = --k ;
        if(i+k-1 > r) l = i-k, r = i+k-1 ;
    }
}



int main(){
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) ;

    string str ;
    cin>> str ;

    manacher(str) ;

    int len = 0, st = -1 ;
    for(int i = 0; i < str.size(); i++){
        if(d1[i]*2-1 > len){
            len = d1[i]*2-1 ;
            st = i-d1[i]+1 ;
        }
        if(d2[i]*2 > len){
            len = d2[i]*2 ;
            st = i-d2[i] ;
        }
    }

    cout<< str.substr(st, len) << nl ;
    
    return 0 ;
}