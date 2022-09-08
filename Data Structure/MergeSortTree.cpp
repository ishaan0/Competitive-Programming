#include<bits/stdc++.h>
using namespace std ;
#define     lim     10000
#define     left    2*iter
#define     right   2*iter+1

int arr[lim] ;
vector<int> segtree[4*lim] ;

/// O(nlogn)
void build(int iter,int lo,int hi){
    if(lo == hi){
        segtree[lo].push_back(arr[lo]) ;
        return  ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(left,lo,mid) ;
    build(right,mid+1,hi) ;
    merge(segtree[left].begin(),segtree[left].end(),segtree[right].begin(),
          segtree[right].end(),back_inserter(segtree[iter])) ;
}

/// O(logn)^2
int query(int iter,int lo,int hi,int qi,int qj,int val){
    if(qj<lo || qi>hi) return 0 ;
    if(qi<=lo && hi<=qj){
        int ans = lower_bound(segtree[iter].begin(),
                  segtree[iter].end(),val)-segtree[iter].begin() ;
        return ans ;
    }
    int mid = lo+(hi-lo)/2 ;
    int lft = query(left,lo,mid,qi,qj,val) ;
    int rgt = query(right,mid+1,hi,qi,qj,val) ;
    return (lft+rgt) ;
}


int main(){

    return 0 ;
}
