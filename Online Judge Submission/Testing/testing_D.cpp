#include<bits/stdc++.h>
using namespace std ;


int main(){
    freopen("generated_input.txt", "r", stdin) ;
    freopen("bruteforce_output.txt", "w", stdout) ;
    
    int n, q ;
    scanf("%d %d", &n, &q) ;

    map<int, int> m ;
    for(int i = 0; i < n; i++){
        int val ;
        scanf("%d", &val) ;
        m[ val ]++ ;
    }

    while(q--){
        int b, c, rem ;
        scanf("%d %d", &b, &c) ;
        rem = b ;
        vector<int> temp ;
        for(auto it = m.begin(); it != m.end(); it++){
            int x = min(rem, it->second) ;
            it->second -= x ;
            rem -= x ;
            if(it->second == 0) temp.push_back( it->first ) ;
            if(rem == 0) break ;
        }
        for(int i = 0; i < temp.size(); i++)
            m.erase( temp[i] ) ;
        m[ c ] += b ;
    }

    long long ans = 0 ;
    for(auto it = m.begin(); it != m.end(); it++)
        ans += (long long)it->first * (long long)it->second ;

    printf("%lld\n", ans) ;
    
    return 0 ;
}