#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e5 + 5 ;
vector<int> adj[lim] ;

void bfs(int src,vector<int>& dis){
    fill(dis.begin(), dis.end(), 1e9) ;
    queue<int> q ;
    q.push(src) ;
    dis[src] = 0 ;

    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;

        for(int v: adj[u]){
            if(dis[v] == 1e9){
                dis[v] = dis[u] + 1 ;
                q.push(v) ;
            }
        }
    }

}


int main(){



    
    return 0 ;
}