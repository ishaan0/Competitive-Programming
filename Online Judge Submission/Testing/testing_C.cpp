#include<bits/stdc++.h>
using namespace std ;

#define     ran(a, b)           ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))


int main(){
	freopen("generated_input.txt", "w", stdout) ;
    freopen("input.txt", "r", stdin) ;

    int t = 10 ;
    cout<< t << "\n" ;

    while(t--){
        int n = ran(1, 1000) ;
        int m = ran(1, 100000) ;

        cout<< n << " " << m << "\n" ;
    }
    
    return 0 ;
}