#include<bits/stdc++.h>
using namespace std ;

// Range query on static array
template<typename T>
struct RMQ{              // 0 based
    vector<vector<T> > table ;
    T kInf = numeric_limits<T>::max() ;

    RMQ(){}
    RMQ(const vector<T>& arr){
        build(arr) ;
    }

    void build(const vector<T>& arr){
        int n = arr.size() ;
        table.assign(1, arr) ;
        for(int i = 0; (1<<(i+1)) <= n; i++){
            table.push_back(vector<T>(n)) ;
            for(int j = 0; j+(1<<(i+1)) <= n; j++)
                table[i+1][j] = min(table[i][j], table[i][j+(1<<i)]) ;  // Change
        }
    }
    
    T query(int lo,int hi){
        if(hi < lo) return kInf ;
        int i = 31 - __builtin_clz(hi-lo+1) ;
        return min(table[i][lo], table[i][hi-(1<<i)+1]) ;   // change
    }
};


int main(){
    int n, q ;
    cin>> n >> q ;

    vector<int> arr(n) ;
    for(int i = 0; i < n; i++) cin>> arr[i] ;

    RMQ<int> sp(arr) ;

    while(q--){
        int l, r ;
        cin>> l >> r ;
        l--, r-- ;
        cout<< sp.query(l, r) << endl ;
    }
    
    return 0 ;
}