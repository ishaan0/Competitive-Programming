#include<bits/stdc++.h>
using namespace std ;

#define         all(cont)       cont.begin(),cont.end()
#define         ll              long long
#define         pb              push_back
#define         ff              first
#define         ss              second
#define         nl              "\n"

const int lim = 1e5 + 5 ;

pair<long long,long long> segtree[4 * lim] ;

#define     left    (2 * iter)
#define     right   (2 * iter + 1)
#define     mid     (lo + (hi - lo)/2)
// 1 based indexing
struct SegmentTree{
    int n ;
    
    SegmentTree(int nn,int arr[]){
        n = nn ;
        build(1, 1, n, arr) ;
    }

    inline void mrg(int iter){
        segtree[iter].first = segtree[left].first + segtree[right].first ;    
    }

    void build(int iter,int lo,int hi,int arr[]){
        if(lo == hi){
            segtree[iter] = {arr[lo], 0} ; 
            return ;
        }
        build(left, lo, mid, arr) ;
        build(right, mid+1, hi, arr) ;
        mrg(iter) ;
        segtree[iter].second = 0 ;
    }

    inline void lazy_update(int iter,int lo,int hi,int x){
        segtree[iter].first += (hi-lo+1LL) * (long long)x ;
        segtree[iter].second += x ;
    }
    inline void push_down(int iter,int lo,int hi){
        lazy_update(left,lo,mid,segtree[iter].second) ;
        lazy_update(right,mid+1,hi,segtree[iter].second) ;
        segtree[iter].second = 0 ;
    }

    void update(int iter,int lo,int hi,int qi,int qj,int x){
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
    void update(int qi,int qj,int val){
        update(1, 1, n, qi, qj, val) ;
    }

    long long query(int iter,int lo,int hi,int qi,int qj){
        if(lo > qj || hi < qi) return 0 ;
        if(qi <= lo && hi <= qj) return segtree[iter].first ;
        push_down(iter,lo,hi) ;
        long long L = query(left,lo,mid,qi,qj) ;
        long long R = query(right,mid+1,hi,qi,qj) ;
        mrg(iter) ;
        return L + R ;
    }
    long long query(int qi,int qj){
        return query(1, 1, n, qi, qj) ;
    }
} ;


int main(){
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) ;
    
    int n, m ;
    cin>> n >> m ;

    int arr[n+5] ;
    for(int i = 1; i <= n; i++)
        cin>> arr[i] ;

    SegmentTree sg(n, arr) ;

    while(m--){
        int tp ;
        cin>> tp ;

        if(tp == 1){
            int l, r, v ;
            cin>> l >> r >> v ;
            l++, r++ ;
            sg.update(l, r-1, v) ;
        }
        else{
            int i ;
            cin>> i ;
            i++ ;
            cout<< sg.query(i, i) << "\n" ;
        }
    }

    
    return 0 ;
}