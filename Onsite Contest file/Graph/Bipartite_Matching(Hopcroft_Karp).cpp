#include<bits/stdc++.h>
using namespace std ;

// problem : https://lightoj.com/problem/factors-and-multiples
// complexity : E*sqrt(V) but for random graph E*log(V)

const int lim = 205 ;

namespace bpm{
    int n ;
    vector<int> adj[lim] ;
    vector<int> match, dis ;

    void init(int _n){
        n = _n ;
        match.assign(n+5, 0) ;
        dis.assign(n+5, 0) ;
        for(int i = 0; i <= n; i++)
            adj[i].clear() ;
    }

    bool bfs(){
        queue<int> q ;
        fill(dis.begin(), dis.end(), INT_MAX) ;
        for(int i = 1; i <= n; i++) if(!match[i]){
            dis[i] = 0 ;
            q.push(i) ;
        }
        while(!q.empty()){
            int u = q.front(); q.pop() ;
            if(!u) continue ;
            for(int v: adj[u]) if(dis[match[v]] == INT_MAX){
                dis[match[v]] = dis[u] + 1 ;
                q.push(match[v]) ;
            }
        }
        return dis[0] != INT_MAX ;
    }

    bool dfs(int u){
        if(!u) return true ;
        for(int x: adj[u]){
            int v = match[x] ;
            if(dis[v] == dis[u]+1 && dfs(v)){
                match[u] = x ;
                match[x] = u ;
                return true ;
            }
        }
        dis[u] = INT_MAX ;
        return false ;
    }

    int hopcroft(){
        int ans = 0 ;
        while(bfs()){
            for(int i = 1; i <= n; i++) // one based
                if(!match[i] && dfs(i))
                    ans++ ;
        }
        return ans ;
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

        init(n+m) ;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(B[j]%A[i] == 0){
                    adj[i].push_back(n+j) ;
                }
            }
        }

        cout<< hopcroft() << "\n" ;
    }

    return 0 ;
}