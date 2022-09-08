#include<bits/stdc++.h>
using namespace std ;

// problem : lightoj-1149
// complexity : v( v + e ) or v^3 if e = v^2

const int lim = 105 ;

namespace bpm{
    int match[lim] ;// only for B set
    bool vis[lim] ;
    vector<int> adj[lim] ;

    bool dfs(int u){
        for(int v: adj[u]){
            if(vis[v]) continue ;
            vis[v] = 1 ;
            if(match[v]==-1 || dfs(match[v])){
                match[v] = u ;
                return true ;
            }
        }
        return false ;
    }

    int khun(int n){
        memset(match, -1, sizeof match) ;
        int cnt = 0 ;

        for(int i = 1; i <= n; i++){// one based
            if(adj[i].size() == 0) continue ;
            memset(vis, 0, sizeof vis) ;
            if(dfs(i)) cnt++ ;
        }
        return cnt ;
    }
}

using namespace bpm ;


int main(){
    int t, cs = 0 ;
    cin>> t ;

    while(t--){
        cout<< "Case " << ++cs << ": " ;
        int n, m ;
        cin>> n ;
        vector<int> A(n+1) ;
        for(int i = 1; i <= n; i++) cin>> A[i] ;

        cin>> m ;
        vector<int> B(m+1) ;
        for(int i = 1; i <= m; i++) cin>> B[i] ;

        for(int i = 0; i <= n; i++) adj[i].clear() ;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(B[j]%A[i] == 0)
                    adj[i].push_back(j) ;
            }
        }

        cout<< khun(n) << "\n" ;
    }


    
    return 0 ;
}