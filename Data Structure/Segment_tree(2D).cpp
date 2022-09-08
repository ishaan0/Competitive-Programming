#include<bits/stdc++.h>
using namespace std ;

const ll lim = 5e2 + 5 ; 

int n,m ;
int segtree[4*lim][4*lim], arr[lim][lim] ;

inline void mrg_r(int iter_r,int iter_c){
    segtree[iter_r][iter_c] = segtree[2*iter_r][iter_c] + segtree[2*iter_r+1][iter_c] ;
}

inline void mrg_c(int iter_r,int iter_c){
    segtree[iter_r][iter_c] = segtree[iter_r][2*iter_c] + segtree[iter_r][2*iter_c+1] ;
}

void build_col(int iter_r,int lo_r,int hi_r,int iter_c,int lo_c,int hi_c){
    if(lo_c == hi_c){
        if(lo_r == hi_r) segtree[iter_r][iter_c] = arr[lo_r][lo_c] ;
        else mrg_r(iter_r,iter_c) ;
        return ;
    }
    int mid = lo_c + (hi_c - lo_c)/2 ;
    build_col(iter_r,lo_r,hi_r,2*iter_c,lo_c,mid) ;
    build_col(iter_r,lo_r,hi_r,2*iter_c+1,mid+1,hi_c) ;
    mrg_c(iter_r,iter_c) ;
}

void build_row(int iter_r,int lo_r,int hi_r){
    if(lo_r == hi_r){
        build_col(iter_r,lo_r,hi_r,1,1,m) ;
        return ;
    }
    int mid = lo_r + (hi_r - lo_r)/2 ;
    build_row(2*iter_r, lo_r, mid) ;
    build_row(2*iter_r+1, mid+1, hi_r) ;
    build_col(iter_r,lo_r,hi_r,1,1,m) ;
}

int query_c(iter_r,int iter_c,int lo_c,int hi_c,int qi_c,int qj_c){
    if(qj_c < lo_c || qi_c > hi_c) return 0 ;
    if(qi_c <= lo_c && hi_c <= qj_c) return segtree[iter_r][iter_c] ;
    int mid = lo_c + (hi_c - lo_c)/2 ;
    int L = query_c(iter_r,2*iter_c,lo_c,mid,qi_c,qj_c) ;
    int R = query_c(iter_r,2*iter_c+1,mid+1,hi_c,qi_c,qj_c) ;
    return L + R ;
}

int query_r(int iter_r,int lo_r,int hi_r,int qi_r,int qj_r,int qi_c,int qj_c){
    if(qj_r < lo_r || qi_r > hi_r) return 0 ;
    if(qi_r <= lo_r && hi_r <= qj_r)
        return query_c(iter_r,1,1,m,qi_c,qj_c) ;
    int mid = lo_r + (hi_r - lo_r)/2 ;
    int L = query_r(2*iter_r,lo_r,mid,qi_r,qj_r,qi_c,qj_c) ;
    int R = query_r(2*iter_r+1,mid+1,hi_r,qi_r,qj_r,qi_c,qj_c) ;
    return L + R ;
}

void update_c(int iter_r,int lo_r,int hi_r,int iter_c,int lo_c,int hi_c,int r,int c,int val){
    if(c < lo_c || c > hi_c) return ;
    if(c <= lo_c && hi_c <= c){
        if(lo_r == hi_r) tree[iter_r][iter_c] = val ;
        else mrg_r(iter_r,iter_c) ;
        return ;
    }
    int mid = lo_c + (hi_c - lo_c)/2 ;
    update_c(iter_r,lo_r,hi_r,2*iter_c,lo_c,mid,r,c,val) ;
    update_c(iter_r,lo_r,hi_r,2*iter_c+1,mid+1,hi_c,r,c,val) ;
    mrg_c(iter_r,iter_c) ;
}

void update_r(int iter_r,int lo_r,int hi_r,int r,int c,int val){
    if(r < lo_r || r > hi_r) return ;
    if(r <= lo_r && hi_r <= r) update_c(iter_r,lo_r,hi_r,1,1,m,r,c,val) ;
}


int main(){
    


    
    return 0 ;
}