#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ;
const int blk = 350 ;

int n, q, cnt, arr[lim], freq[lim] ;

struct query{   // 0 based
    int l, r, idx ;
    bool operator < (const query& ob) const{
        if(l/blk == ob.l/blk) return ((l/blk)&1) ? r > ob.r : r < ob.r ;
        return l < ob.l ;
    }
};

inline void Add(int i){
    freq[ arr[i] ]++ ;
    if(freq[ arr[i] ] == 1) cnt++ ;
}

inline void Remove(int i){
    freq[ arr[i] ]-- ;
    if(freq[ arr[i] ] == 0) cnt-- ;
}


vector<query > Q ;

void MO(){
    vector<int> ans(Q.size()) ;
    sort(Q.begin(), Q.end()) ;
    int curL = 0, curR = -1 ;

    for(query q: Q){
        while(curL > q.l)      
            Add(--curL) ;
        while(curR < q.r)     
            Add(++curR) ;
        while(curL < q.l)      
            Remove(curL++) ;
        while(curR > q.r) 
            Remove(curR--) ;
        ans[q.idx] = cnt ;
    }

    for(int el: ans) cout<< el << "\n" ;
}


int main(){
    cin>> n ;
    for(int i = 0; i < n; i++) cin>> arr[i] ;

    cin>> q ;
    for(int i = 0; i < q; i++){
        query range ;
        cin>> range.l >> range.r ;
        range.l--, range.r-- ;
        range.idx = i ;
        Q.push_back(range) ;
    }

    MO() ;
    
    return 0 ;
}