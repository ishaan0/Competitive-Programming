#include<bits/stdc++.h>
using namespace std ;
#define pb push_back

/// Give 4 array consist of integer value .
/// need to pick one integer from each
/// such that their sum is equal to zero .
/// a+b+c+d = 0 . Hint : (a+b) = -(c+d) .

/// complexity : n^2

int main(){
    vector<int> A = {1, 2, 3} ;
    vector<int> B = {-1, -4, -5} ;
    vector<int> C = {1, 5, 8} ;
    vector<int> D = {9, 8, 5} ;
    vector<int> AB, CD ;

    for(int i=0; i<A.size(); i++)
        for(int j=0; j<B.size(); j++)
            AB.pb(A[i]+B[j]) ;

    for(int i=0; i<C.size(); i++)
        for(int j=0; j<D.size(); j++)
            CD.pb(C[i]+D[j]) ;
    sort(CD.begin(),CD.end()) ;

    int ans = 0 ;
    for(int i=0; i<AB.size(); i++){
        int val = -AB[i] ;
        int pos = lower_bound(CD.begin(),CD.end(),val) - CD.begin() ;
        if(pos < CD.size() && CD[pos] == val) ans++ ;
    }

    cout<< ans << endl ;

    return 0 ;
}
