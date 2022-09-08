#include<bits/stdc++.h>
using namespace std ;

#define sz      100000
#define left    2*node
#define right   2*node+1
#define first   prop
#define second  sum

int input[sz]
pair<int,int> tree[4*sz] ;

/// build  in O( n )
void buildTree(int node, int lo, int hi){

    if(lo == hi){
        tree[node].sum = input[lo] ;
        tree[node].prop = 0 ;
        return ;
    }

    int mid = lo + (hi-lo)/2 ;

    buildTree(left,lo,mid) ;
    buildTree(right,mid+1,hi) ;

    tree[node].sum = tree[left].sum + tree[right].sum ;
}

/// range update in O(logn)
void update(int node,int lo,int hi,int i,int j,int val){
    if(i>hi || j<lo)
        return ;
    else if(i<=lo && hi<=j){
        tree[node].sum += (hi-lo+1)*val ;
        tree[node].prop += val ;
        return ;
    }

    int mid = lo + (hi-lo)/2 ;

    update(left,lo,mid,i,j,val) ;
    update(right,mid+1,hi,i,j,val) ;

    tree[node].sum = tree[left].sum+tree[right].sum+(hi-lo+1)*tree[node].prop ;
}

/// query in O(logn)
int query(int node,int lo,int hi,int i,int j,int carry=0){

    if(lo>j || hi<i)
        return 0;
    else if(i<=lo && hi<=j){
        return tree[node].sum + carry*(hi-lo+1) ;
    }

    int mid = lo + (hi-lo)/2 ;

    int leftQuery = query(left,lo,mid,i,j,carry+tree[node].prop) ;
    int rightQuery = query(right,mid+1,hi,i,j,carry+tree[node].prop) ;

    return leftQuery + rightQuery ;
}

int main(){


    return 0 ;
}
