#include<bits/stdc++.h>
using namespace std ;
#define     ll      long long

/*
    We have two string a and b . we need to find tho index of occurences of
    b string in a string .
    we will use rabin karp algorithm which is work with hash value of
    those string .
    Here I used double hashing for extra security .
*/
const ll h_lim = 2 ;
const ll mod[2] = {1423165193, 1423172537} ;
const ll base[2] = {61, 73} ;

vector<int> occurences ;

void rabin_karp(string a,string b){
    int n = a.size() , m = b.size() ;
    if(n < m){
        cout<< "Not found !!!\n" ;
        exit(0) ;
    }
    ll hash_t[2] = {0, 0}, hash_p[2] = {0, 0} ;
    ll base_pow[2] = {1, 1} ;

    for(int i=0; i<m; i++){
        if(i<m-1){                          /// This is for a string hash till b size - 1 and base power also
            for(int j=0; j<h_lim; j++){
                hash_t[j] = hash_t[j] * base[j] + (a[i] - 'a') ;
                hash_t[j] %= mod[j] ;
                base_pow[j] = (base_pow[j] * base[j]) % mod[j] ; /// get power for base to substract from hash
            }
        }
        for(int j=0; j<h_lim; j++){
            hash_p[j] = hash_p[j] * base[j] + (b[i] - 'a') ;
            hash_p[j] %= mod[j] ;
        }
    }

    for(int i=m-1; i<n; i++){
        for(int j=0; j<h_lim; j++){
            hash_t[j] = hash_t[j] * base[j] + (a[i] - 'a') ;    /// this will add new char to the hash
            hash_t[j] %= mod[j] ;
        }

        if(hash_t[0] == hash_p[0] && hash_t[1] == hash_p[1])
            occurences.push_back(i - m + 1) ;       /// it will save occurences

        for(int j=0; j<h_lim; j++){                 /// This section remove this substring 1st char from hash
            hash_t[j] = hash_t[j] - ((a[i-m+1] - 'a') * base_pow[j]) % mod[j] ;
            hash_t[j] = (hash_t[j] + mod[j]) % mod[j] ;
        }
    }
}


int main(){
    
    string a = "ishaan" , b = "aan" ;

    rabin_karp(a, b) ;

    if(occurences.size() > 0) cout<< "YES substring found.\n" ;
    else cout<< "NOT found !!!\n" ;
    
    return 0 ;
}