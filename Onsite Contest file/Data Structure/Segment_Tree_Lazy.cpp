#include<bits/stdc++.h>
using namespace std ;

// Range update, Range query

#define     left    (iter<<1)
#define     right   (left | 1)
#define     mid     (lo + ((hi - lo)>>1))
template<typename T>
struct SegmentTree_lazy{ // 1 based
    int n ;
    vector< pair<T,T> > segtree ;
    SegmentTree_lazy(){}
    SegmentTree_lazy(int n,vector<T>& arr){
        init(n, arr) ;
    }
    void init(int n,vector<T>& arr){
        this->n = n ;
        segtree.assign(4*n+10, make_pair(0, 0)) ;
        build(1, 1, n, arr) ;
    }

    inline void mrg(int iter){          // Change
        segtree[iter].first = segtree[left].first + segtree[right].first ; 
        segtree[iter].second = 0 ;  
    }
    void build(int iter,int lo,int hi,vector<T>& arr){
        if(lo == hi){
            segtree[iter] = {arr[lo], 0} ; 
            return ;
        }
        build(left, lo, mid, arr) ;
        build(right, mid+1, hi, arr) ;
        mrg(iter) ;
    }

    inline void lazy_update(int iter,int lo,int hi,T x){
        segtree[iter].first += (hi-lo+1LL) * x ;     // Change
        segtree[iter].second += x ;
    }
    inline void push_down(int iter,int lo,int hi){
        lazy_update(left,lo,mid,segtree[iter].second) ;
        lazy_update(right,mid+1,hi,segtree[iter].second) ;
        segtree[iter].second = 0 ;                   // Change
    }

    void update(int iter,int lo,int hi,int qi,int qj,T x){
        if(lo > qj || hi < qi) return ;
        if(qi <= lo && hi <= qj){
            lazy_update(iter,lo,hi,x) ;
            return ;
        }
        push_down(iter,lo,hi) ;
        update(left,lo,mid,qi,qj,x) ;
        update(right,mid+1,hi,qi,qj,x) ;
        mrg(iter) ;
    }
    void update(int qi,int qj,T x){
        update(1, 1, n, qi, qj, x) ;
    }
    
    T query(int iter,int lo,int hi,int qi,int qj){
        if(lo > qj || hi < qi) return 0 ;           // Change
        if(qi <= lo && hi <= qj) return segtree[iter].first ;
        push_down(iter,lo,hi) ;
        T L = query(left,lo,mid,qi,qj) ;
        T R = query(right,mid+1,hi,qi,qj) ;
        mrg(iter) ;
        return L + R ;           // Change
    }
    T query(int qi,int qj){
        return query(1, 1, n, qi, qj) ;
    }
} ;

int main(){
    // ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) ;



    
    return 0 ;
}