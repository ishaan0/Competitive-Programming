#include<bits/stdc++.h>
using namespace std ;


namespace BC{
    inline int val(char ch){
        if(ch >= '0' && ch <= '9') return (int)ch-'0' ;
        return 10 + (int)(ch - 'A') ;
    }

    string toDec(string str,long long base){
        long long res = 0 ;
        for(int i = 0; i < str.size(); i++){
            long long digit = val(str[i]) ;
            assert(digit < base) ;
            res = (res * base) + digit ;
        }
        return to_string(res) ;
    }

    string fromDec(string str,long long base){
        string res = "" ;
        long long num = stoll(str) ;
        while(num > 0){
            res += to_string(num%base) ;
            num /= base ;
        }
        reverse(res.begin(), res.end()) ;
        return res ;
    }

    string convert(string str,long long a,long long b){
        string dec = toDec(str, a) ;
        return fromDec(dec, b) ;
    }

}

int main(){
    
    cout<< BC::convert("1001", 2, 10) << "\n" ;

    return 0 ;
}