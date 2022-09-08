#include<bits/stdc++.h>
using namespace std ;


const int lim = 1e6+5 ;

bitset<lim> mark ;
vector<int> primes ;

void sieve(){
    mark[0] = mark[1] = 1, primes.push_back(2) ;
    for(int i = 4; i < lim; i += 2) mark[i] = 1 ;
    for(int i = 3; i < lim; i += 2){
        if(mark[i]) continue ;
        primes.push_back(i) ;
        if(i*1LL*i >= lim) continue ;
        for(int j = i * i; j < lim; j += 2*i)
            mark[j] = 1 ;
    }
}

long long segmentedSieve(long long a,long long b){
    assert(b >= a) ;
    a = max(a, 2LL) ;
    vector<bool> mark_2(b-a+5) ;

    for(long long i=0; i<primes.size()&&primes[i]*1LL*primes[i]<=b; i++){
        long long p = primes[i] ;
        long long j = ( (a+p-1)/p )*p ;   /// to reach the p's first multiple on the range .
        if(j == p) j += p ;
        for(; j<=b; j+=p) mark_2[j-a] = 1 ;
    }
    long long cnt = 0 ;
    for(long long i=a; i<=b; i++)
        if(!mark_2[i-a])
            cnt++ ;
    return cnt ;
}


int main(){

    sieve() ;

    cout<< segmentedSieve(2, 10) ;

    return 0 ;
}
