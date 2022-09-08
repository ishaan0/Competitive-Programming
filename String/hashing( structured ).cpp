#include<bits/stdc++.h>
using namespace std ;

// 0 based indexing
// my string is 0 based but hash are saved in 1 based
struct simpleHash{
    int len ;
    long long base, mod ;
    vector<int> P, H, R ;
    simpleHash(){}
    simpleHash(const char* str,long long b=1949313259,long long m=2091573227){
        base = b, mod = m, len = strlen(str) ;
        P.resize(len+3, 1), H.resize(len+3, 0), R.resize(len+3, 0) ;
        for (int i = 1; i <= len; i++) P[i] = (P[i - 1] * base) % mod;
        for (int i = 1; i <= len; i++) H[i] = (H[i - 1] * base + str[i - 1] + 1007) % mod;
        for (int i = len; i >= 1; i--) R[i] = (R[i + 1] * base + str[i - 1] + 1007) % mod;
    }

    inline int range_hash(int l, int r){
        int hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }

    inline int reverse_hash(int l, int r){;
        int hashval = R[l + 1] - ((long long)P[r - l + 1] * R[r + 2] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }
} ;

struct doubleHash{
    simpleHash sh1, sh2 ;
    doubleHash(){}
    doubleHash(const char* str){
        sh1 = simpleHash(str, 1949313259, 2091573227);
        sh2 = simpleHash(str, 1997293877, 2117566807);
    }

    inline long long range_hash(int l, int r){
        return ((long long)sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
    }

    inline long long reverse_hash(int l, int r){
        return ((long long)sh1.reverse_hash(l, r) << 32) ^ sh2.reverse_hash(l, r);
    }
} ;


int main(){
    string a = "ishaan", b = "ishaan", c = "naahsi" ;

    doubleHash sh1(a.c_str()), sh2(b.c_str()), sh3(c.c_str()) ;

    if(sh1.range_hash(0, 5) == sh2.range_hash(0, 5))
        cout<< "They are same\n" ;
    else cout<< "Not matched\n" ;


    if(sh1.range_hash(0, 5) == sh3.reverse_hash(0, 5))
        cout<< "They are reverse of each other\n" ;
    else cout<< "They aren't reverse of each other\n" ;
    
    return 0 ;
}