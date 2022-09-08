#include<bits/stdc++.h>
using namespace std ;

const int maxN = 1e5 + 5 ; 

// single update and range query
template<class T>
struct fenwick{ // 1 based index
    int n ;
    vector<T> bit_tree ;

    fenwick(int m) : n(m){
        bit_tree.assign(n+1, 0) ;
    }
    // point update
    void update(int idx,T val){
        while( idx > 0 && idx <= n ){
            bit_tree[idx] += val ;
            idx += (idx & (-idx)) ;
        }
    }
    // point query
    T query(int idx){
        T sum = 0 ;
        while( idx > 0 && idx <= n ){
            sum += bit_tree[idx] ;
            idx ^= (idx & (-idx)) ;
        }
        return sum ;
    }
    // range query
    T query(int l,int r){
        if(l > r) return 0 ;
        return (query(r) - query(l-1)) ;
    }
};


// range update, single query
namespace BIT{
    int n, bit_tree[maxN] ;

    void init(int m){
        n = m ;
        for(int i = 1; i <= n; i++) bit_tree[i] = 0 ;
    }
    // add value on [idx, n]
    void update(int idx,int val){
        while( idx <= n ){
            bit_tree[idx] += val ;
            idx += (idx & (-idx)) ;
        }
    }
    // add value on [l, r]
    void update(int l,int r,int val){
        if(l > r) return ;
        update(l, val) ;
        update(r+1, -val) ;
    }
    // sum of point idx
    int query(int idx){
        int sum = 0 ;
        while( idx ){
            sum += bit_tree[idx] ;
            idx ^= (idx & (-idx)) ;
        }
        return sum ;
    }
}

// it can support range update and range query
template<class T>
struct fenwick_range{
    int n ;
    vector<T> B1, B2 ;
    fenwick(int m) : n(m){
        B1.assign(n+1, 0) ;
        B2.assign(n+1, 0) ;
    }
    // point update
    void update(vector<T>& bit_tree,int idx,T val){
        while( idx > 0 && idx <= n ){
            bit_tree[idx] += val ;
            idx += (idx & (-idx)) ;
        }
    }
    // range update
    void update(int l,int r,T val){
        if(l > r) return ;
        update(B1, l, val) ;
        update(B1, r+1, -val) ;
        update(B2, l, val*(l-1)) ;
        update(B2, r+1, -val*r) ;
    }
    // prefix sum
    T query(vector<T>& bit_tree,int idx){
        T sum = 0 ;
        while( idx > 0 && idx <= n ){
            sum += bit_tree[idx] ;
            idx ^= (idx & (-idx)) ;
        }
        return sum ;
    }
    T query(int idx){
        return (query(B1, idx)*idx - query(B2, idx)) ;
    }
    // range query
    T query(int l,int r){
        if(l > r) return 0 ;
        return (query(r) - query(l-1)) ;
    }
};


// Range Update, Range Query on 2D grid
const int lim = 1e3 + 10 ;
long long M[lim][lim][2], A[lim][lim][2] ;

struct fenwick_2d{
    int n, m ;
    
    fenwick_2d(int _n,int _m){
        n = _n, m = _m ;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                M[i][j][0] = M[i][j][1] = 0 ;
                A[i][j][0] = A[i][j][1] = 0 ;
            }
        }
    }

    void update(long long t[lim][lim][2],int x,int y,long long mul,long long add){
        for(int i=x; i<=n; i+=(i & -i)){
            for(int j=y; j<=m; j+=(j & -j)){
                t[i][j][0] += mul ;
                t[i][j][1] += add ;
            }
        }
    }

    void update(int x,int y1,int y2,long long mul,long long add){
        update(M, x, y1, mul, -mul * (y1-1)) ;
        update(M, x, y2, -mul, mul * y2) ;
        update(A, x, y1, add, -add * (y1-1)) ;
        update(A, x, y2, -add, add * y2) ;
    }

    void update(int x1,int y1,int x2,int y2,long long val){
        update(x1, y1, y2, val, -val * (x1-1)) ;
        update(x2, y1, y2, -val, val * x2) ;
    }

    long long query(long long t[lim][lim][2],int x,int y){
        long long mul = 0, add = 0 ;
        for(int i = y; i > 0; i -= (i & -i)){
            mul += t[x][i][0] ;
            add += t[x][i][1] ;
        }
        return mul * x + add ;
    }

    long long query(int x,int y){
        long long mul = 0, add = 0 ;
        for(int i = x; i > 0; i -= (i & -i)){
            mul += query(M, i, y) ;
            add += query(A, i, y) ;
        }
        return mul * x + add ;
    }

    long long query(int x1,int y1,int x2,int y2){
        return query(x2, y2) - query(x1-1,y2) - query(x2,y1-1) + query(x1-1,y1-1) ;
    }

};

int main(){
    


    
    return 0 ;
}