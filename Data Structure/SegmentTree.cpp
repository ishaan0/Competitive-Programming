#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ; 

int arr[lim] ;
#define     left    (2 * iter)
#define     right   (2 * iter + 1)
#define     mid     (lo + (hi - lo)/2)

// 1 based indexing
template<typename T>
struct SegmentTree{
    int n ;
    vector<long long> arr ;
    vector<T> segtree ;
    SegmentTree(int m,long long* tmp){
        n = m ;
        arr.assign(tmp, tmp+n) ;
        segtree.assign(4*n+1, 0) ;
        build(1, 1, n) ;
    }
    SegmentTree(int m,vector<long long>& tmp){
        n = m ;
        arr.assign(tmp.begin(), tmp.begin()+n) ;
        segtree.assign(4*n+1, 0) ;
        build(1, 1, n) ;
    }
    inline void mrg(int iter){
        segtree[iter] = segtree[left] + segtree[right] ;   
    }
    void build(int iter,int lo,int hi){
        if(lo == hi){
            segtree[iter] = arr[lo] ; 
            return ;
        }
        build(left, lo, mid) ;
        build(right, mid+1, hi) ;
        mrg(iter) ;
    }
    // sum query on range
    T query(int iter,int lo,int hi,int qi,int qj){
        if(qj < lo || qi > hi) return 0 ;                  
        if(qi <= lo && hi <= qj) return segtree[iter] ;
        T L = query(left, lo, mid, qi, qj) ;
        T R = query(right, mid+1, hi, qi, qj) ;
        return L + R ;                                    
    }
    // simplified 
    T query(int qi,int qj){
        if(qj < qi) return 0 ;
        return query(1, 1, n, qi, qj) ;
    }
    // point update
    void update(int iter,int lo,int hi,int qi,T val){
        if(qi < lo || qi > hi) return ;
        if(qi <= lo && hi <= qi){
            segtree[iter] = val ;                         
            return ;
        }
        update(left, lo, mid, qi, val) ;
        update(right, mid+1, hi, qi, val) ;
        mrg(iter) ;
    }
    // simplified
    void update(int qi,int val){
        if(qi < 1 || qi > n) return ;
        update(1, 1, n, qi, val) ;
    }
} ;


int main(){
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) ;

    int n, m ;
    cin>> n >> m ;
    for(int i = 1; i <= n; i++) cin>> arr[i] ;

    SegmentTree<long long> sg(n+1, arr) ;

    while(m--){
        int tp ;
        cin>> tp ;
        if(tp == 1){
            int i, v ;
            cin>> i >> v ;  // i is 0 based
            i++ ;
            sg.update(i, v) ;
        }
        else{
            int l, r ;
            cin>> l >> r ;  // l to r-1 , where both are 0 based
            l++, r++ ;
            cout<< sg.query(l, r-1) << "\n" ;
        }
    }
    
    return 0 ;
}