#include<bits/stdc++.h>
using namespace std ;

#define     ll      long long
#define     pb      push_back
#define     ff      first
#define     ss      second
#define     nl      "\n"

template<typename CS>
struct csum_2D{
    int n, m ;
    vector<vector<CS> > pre ;
    csum_2D(int nn,int mm){
        n = nn , m = mm ;
        pre.assign(n+5, vector<CS>(m+5, 0)) ;
    }

    inline void add(int x,int y,CS val){
        pre[x][y] = val ;
    }

    void build(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                pre[i][j] += ( pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] ) ;
            }
        }
    }

    CS query(int lx,int ly,int hx,int hy){
        return pre[hx][hy] - pre[hx][ly-1] - pre[lx-1][hy] + pre[lx-1][ly-1] ;
    }
};


int main(){       
    int n, m ;
    cin>> n >> m ;

    csum_2D<long long> sum(n, m) ;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ll val ;
            cin>> val ;
            sum.add(i, j, val) ;
        }
    }

    sum.build() ;

    cout<< sum.query(2, 2, 3, 3) << nl ;

    
    return 0 ;
}