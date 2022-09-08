#include<bits/stdc++.h>
using namespace std;

#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     pair <int, int>             pii ;


/// Need to move from (x1,y1) to (x2,y2)
/// directional array is used to make a move

int dr[8] = {-1, -1, -2, -2,  1, 1,  2, 2} ;
int dc[8] = {-2,  2, -1,  1, -2, 2, -1, 1} ;
int vis[10][10] ;

int BFS(pii src, pii dest){
    queue<pii > q ;
    memset(vis, -1, sizeof(vis)) ;
    q.push(src) ;
    vis[src.ff][src.ss] = 0 ;
    if(src.ff==dest.ff && src.ss==dest.ss)
        return 0 ;

    while(!q.empty()){
        pii u = q.front() ;
        q.pop() ;
        int ur = u.ff ;
        int uc = u.ss ;
        int vr,vc ;

        for(int i=0; i<8; i++){
            vr = ur + dr[i] ;
            vc = uc + dc[i] ;
            if(vr<1 || vr>8 || vc<1 || vc>8 )
                continue ;
            if(vis[vr][vc] == -1){
                vis[vr][vc] = vis[ur][uc] + 1 ;
                q.push(mk(vr,vc)) ;
                if(vr==dest.ff && vc==dest.ss)
                    return vis[vr][vc] ;
            }
        }
    }

    return vis[dest.ff][dest.ss] ;
}


int main()
{

    pii src, dest ;
    cin>> src.ff >> src.ss >> dest.ff >> dest.ss ;

    int total = BFS(src,dest) ;

    cout<< "Total move needed : " << total << endl ;

    return 0;
}


