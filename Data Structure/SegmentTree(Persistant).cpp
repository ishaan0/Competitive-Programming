#include<bits/stdc++.h>
using namespace std ;

/**
    Persistent Segment Tree
    This set extra node in each update .
    Here we can track all version
    after update also .
*/

const int lim = 105 ;
int arr[lim] ;

struct node{
    int val ;
    node *left, *right ;
    node(int vl=0,node* lft,node* rgt){
        val = vl ;
        left = lft ;
        right = rgt ;
    }
};

void build(node* n,int lo,int hi){
    if(lo == hi){
        n->val = arr[lo] ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    n->left = new node() ;
    n->right = new node() ;
    build(n->left,lo,mid) ;
    build(n->right,mid+1,hi) ;
    n->val = (n->left->val) + (n->right->val) ;
}

void update(node* prev,node* cur,int lo,int hi,int qi,int val){
    if(qi<lo || qi>hi) return ;
    if(lo == hi){
        cur->val = val ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    if(qi<=mid){
        cur->right = prev->right ;
        cur->left = new node() ;
        update(prev->left,cur->left,lo,mid,qi,val) ;
    }
    else{
        cur->left = prev->left ;
        cur->right = new node()
        update(prev->right,cur->right,mid+1,hi,qi,val) ;
    }
    cur->val = (cur->left->val) + (cur->right->val) ;
}

int query(node* n,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return 0 ;
    if(qi<=lo && hi<=qj) return n->val ;
    int mid = lo+(hi-lo)/2 ;
    int lft = query(n->left,lo,mid,qi,qj) ;
    int rgt = query(n->right,mid+1,hi,qi,qj) ;
    return lft+rgt ;
}



int main(){
    node* version[lim] ;
    int n ;
    cin>> n ;
    for(int i=1; i<=n; i++) cin>> arr[i] ;

    node* root = new node() ;
    build(root,1,n) ;
    version[0] = root ;

    version[1] = new node() ;
    update(version[0],version[1],1,n,2,10) ;
    version[2] = new node() ;
    update(version[1],version[2],1,n,4,12) ;

    cout<< query(version[0],1,n,1,6) ;
    cout<< query(version[1],1,n,2,5) ;
    cout<< query(version[2],1,n,1,8) ;

    return 0 ;
}
