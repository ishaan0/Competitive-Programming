#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const ll lim = 505 ;
const ll inf = 1e9 ;

/*
    Floyd Warshall Algorithm
    This is an all pair shortest path algorithm
    We will get shortest path for every pair .

    Time  : n^3
    space : n^2
*/

int n,m ;
int mat[lim][lim], path[lim][lim] ;

void warshall(){
    /// initialize all paths
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) path[i][j] = 0 ;
            else if(mat[i][j] != inf) path[i][j] = i ;
            else path[i][j] = -1 ;
        }
    }
    /// Run floyd warshal algorithm
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(mat[i][k]==inf || mat[k][j]==inf ||
                    mat[i][k]+mat[k][j] >= mat[i][j]) continue ;
                mat[i][j] = mat[i][k] + mat[k][j] ;
                path[i][j] = path[k][j] ;
            }
            if(mat[i][i] < 0){
                cout<< "Negetive cycle occured !!!\n" ;
                return ;
            }
        }
    }

}

void printPath(int u,int v){
    if(path[u][v] == u) return ;
    printPath(u,path[u][v]) ;
    cout<< path[u][v] << " " ;
}

int main(){
    cin>> n >> m ;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i != j) mat[i][j] = inf ;

    for(int i=0; i<m; i++){
        int u,v,c ;
        cin>> u >> v >> c ;
        mat[u][v] = c ;
        mat[v][u] = c ;
    }

    warshall() ;
    int q ;
    cin>> q ;

    while(q--){
        int u,v ;
        cin>> u >> v ;
        
        if(u == v){
            cout<< u << "\n" ;
            continue ;
        }
        else if(path[u][v] == -1){
            cout<< "path is not possible\n" ;
            continue ;
        }

        cout<< u << " " ;
        printPath(u,v) ; /// print path u to v .
        cout<< v << "\n" ;
    }

    return 0 ;
}