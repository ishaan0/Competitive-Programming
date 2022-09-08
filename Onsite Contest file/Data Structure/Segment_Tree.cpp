#include<bits/stdc++.h>
using namespace std ;


// Point update, Range query
#define     left    (iter<<1)
#define     right   (left | 1)
#define     mid     (lo + ((hi - lo)>>1))
template<typename T>
struct segmentTree{ // 1 based
    int n ;
    vector<T> segtree ;
    segmentTree(){}
    segmentTree(int n,vector<T>& arr){
        init(n, arr) ;
    }
    void init(int n,vector<T>& arr){
        this->n = n ;
        segtree.assign(4*n+5, 0) ;
        build(1, 1, n, arr) ;
    }

    inline void mrg(int iter){
        segtree[iter] = segtree[left] + segtree[right] ;// change   
    }
    void build(int iter,int lo,int hi,vector<T>& arr){
        if(lo == hi){
            segtree[iter] = arr[lo] ; 
            return ;
        }
        build(left, lo, mid, arr) ;
        build(right, mid+1, hi, arr) ;
        mrg(iter) ;
    }

    // sum query on range
    T query(int iter,int lo,int hi,int qi,int qj){
        if(qj < lo || qi > hi) return 0 ;          // change        
        if(qi <= lo && hi <= qj) return segtree[iter] ;
        T L = query(left, lo, mid, qi, qj) ;
        T R = query(right, mid+1, hi, qi, qj) ;
        return L + R ;                            // change                  
    }
    T query(int qi,int qj){
        if(qj < qi) return 0 ;                  // change
        return query(1, 1, n, qi, qj) ;
    }
    
    // point update
    void update(int iter,int lo,int hi,int qi,T val){
        if(qi < lo || qi > hi) return ;
        if(qi <= lo && hi <= qi){
            segtree[iter] = val ;               // change               
            return ;
        }
        update(left, lo, mid, qi, val) ;
        update(right, mid+1, hi, qi, val) ;
        mrg(iter) ;
    }
    void update(int qi,int val){
        if(qi < 1 || qi > n) return ;
        update(1, 1, n, qi, val) ;
    }
} ;

int main(){
    



    
    return 0 ;
}