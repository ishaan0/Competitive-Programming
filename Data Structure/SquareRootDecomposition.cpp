#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ;
const int blk = 350 ;

int n, arr[lim] ;
long long B[400] ;

void preCal(){
    memset(B, 0, sizeof B) ;
    memset(lazy, 0, sizeof lazy) ;
    for(int i = 0; i < n; i++)  // 0 based
        B[i/blk] += arr[i] ;
}

void update(int i,long long val){
    B[i/blk] += (val - arr[i]) ;
    arr[i] = val ;
}

long long query(int l,int r){
    int lb = l/blk , rb = r/blk ;
    long long sum = 0 ;

    if(lb==rb){
        for(int i = l; i <= r; i++) sum += arr[i] ;
        return sum ;
    } 

    for(int i = l, l_end = (lb+1)*blk; i < l_end; i++) sum += arr[i] ;
    for(int i = lb+1; i < rb; i++) sum += B[i] ;
    for(int i = rb*blk; i <= r; i++) sum += arr[i] ;

    return sum ;
}


// another efficient way of sqrt
vector<long long> pref ;
vector<pair<int,long long> > upd ;
int n, arr[lim] ;

void build(){
    pref = {0} ;
    for(int i = 0; i < n; i++)
        pref.push_back(pref.back()+arr[i]) ;
}

void update(int i,long long val){   // 0 based
    if(upd.size()*1LL*upd.size() > n)
            upd.clear(), build() ;
    upd.push_back({i, val-arr[i]}) ;
    arr[i] = val ;
}

long long query(int l,int r){ // 0 based
    if(upd.size()*1LL*upd.size() > n)
            upd.clear(), build() ;
    long long ans = pref[r+1] - pref[l] ;
    for(auto el: upd) if(el.first >= l && el.first <= r)
        ans += el.second ;
    return ans ;
}


int main(){



    
    return 0 ;
}