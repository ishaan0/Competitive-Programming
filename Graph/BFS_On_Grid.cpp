#include<bits/stdc++.h>
using namespace std ;
#define lim 10005
#define pii pair<int,int>
#define ff first
#define ss second

/// Here we are given a 2D grid
/// Where we can visit any adjacent cell
/// But can't visit cell with block
/// We are using a directional array to move
/// In vis array we will store time or distance

int n,m ;
char grid[lim][lim] ;
int vis[lim][lim] ;
int dr[4] = {0, 0, -1, 1} ;
int dc[4] = {-1, 1, 0, 0} ;

int BFS(pii src, pii dest){
    queue<pii > q ;
    memset(vis, -1 , sizeof(vis)) ;
    vis[src.ff][src.ss] = 0 ;
    q.push(src) ;

    while(!q.empty()){
        pii u = q.front() ;
        q.pop() ;
        int ur = u.ff ;
        int uc = u.ss ;
        int vr, vc ;

        for(int i=0; i<4; i++){
            vr = ur + dr[i] ;
            vc = uc + dc[i] ;

            if(vr<0 || vr==n || vc<0 || vc==m) // cell is out of grid
                continue ;
            if(grid[vr][vc]== '*') // assume * means block
                continue ;

            if(vis[vr][vc] == -1){
                vis[vr][vc] = vis[ur][uc] + 1 ;
                q.push({vr,vc}) ;
                if(vr==dest.ff && vc==dest.ss) // found destination cell
                    return vis[vr][vc] ;
            }
        }

    }
    return vis[dest.ff][dest.ss] ;
}

int main(){


    return 0 ;
}
