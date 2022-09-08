#include<bits/stdc++.h>
using namespace std ;


// problem link : https://cses.fi/problemset/task/2102/


struct aho_corasick{
    const int max_c = 26 ;
    int N, P ;
    vector< vector<int> > next, out ;
    vector<int> link, out_link ; 

    aho_corasick() : N(0), P(0){ node(); }

    int node(){
        next.emplace_back(max_c, 0) ;
        link.emplace_back(0) ;
        out_link.emplace_back(0) ;
        out.emplace_back(0) ;
        return N++ ;
    }

    inline int get(char c){ return c-'a'; }

    int add_pattern(string pat){
        int u = 0 ;
        for(char c: pat){
            if(!next[u][ get(c) ]) next[u][ get(c) ] = node() ;
            u = next[u][ get(c) ] ;
        }
        out[u].push_back(P) ;
    
        return P++ ;
    }

    void compute(){
        queue<int> q ;
        q.push(0) ;

        while(!q.empty()){
            int u = q.front(); q.pop() ;
            for(int c = 0; c < max_c; c++){
                int v = next[u][c] ;
                if(!v) next[u][c] = next[ link[u] ][c] ;
                else{
                    link[v] = u ? next[ link[u] ][c] : 0 ;
                    out_link[v] = out[ link[v] ].empty() ? out_link[ link[v] ] : link[v] ;
                    q.push(v) ;
                }
            }
        }
    }

    int go(int u,char c){
        while(u && !next[u][ get(c) ]) u = link[u] ;
        return next[u][ get(c) ] ;
    }

    vector<int> search_pattern(string text){
        int u = 0 ;
        vector<int> occurance ;
        vector<bool> freq(N+5, 1) ;
        for(char c: text){
            u = go(u, c) ;
            for(int v = u; v; v = out_link[v]){
                if(freq[v]){
                    for(int id: out[v]) occurance.push_back(id) ;
                    freq[v] = 0 ;
                }
            }
        }
        return occurance ;
    }

} ;

const int lim = 1e5 + 5 ;

char str[lim], pat[5 * lim] ;

int main(){
    scanf("%s", str) ;

    int n ;
    scanf("%d", &n) ;
    
    aho_corasick aho ;

    for(int i = 0; i < n; i++){
        scanf("%s", pat) ;
        aho.add_pattern(pat) ;
    }

    aho.compute() ;
    vector<int> occurance = aho.search_pattern(str) ;

    vector<int> ans(n) ;
    for(auto el: occurance) ans[el]++ ;

    for(auto el: ans){
        if(el > 0) printf("YES\n") ;
        else printf("NO\n") ;
    }
    
    
    return 0 ;
}