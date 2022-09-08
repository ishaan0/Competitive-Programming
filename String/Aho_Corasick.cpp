#include<bits/stdc++.h>
using namespace std ;



struct aho_corasick{

    struct node{
        int nxt[27], val, par, fail, cnt ;
        node(){
            val = par = fail = cnt = 0 ;
            memset(nxt, 0, sizeof nxt) ;
        }
    };

    int n ;
    vector<node> trie ;
    vector<int> pos, occurence ;
    aho_corasick(int _n){
        n = _n ;
        trie.resize(1, node()) ;
        pos.resize(n+5, 0) ;
        occurence.resize(5, 0) ;
    }

    void add_pat(string pat,int id){
        int cur = 0 ;
        for(int el: pat){
            int ch = el - 'a' ;
            if(trie[cur].nxt[ch] == 0){
                trie[cur].nxt[ch] = trie.size() ;
                trie.push_back(node()) ;
                occurence.push_back(0) ;
            }
            int p = cur ;
            cur = trie[cur].nxt[ch] ;
            trie[cur].par = p ;
        }
        trie[cur].cnt++ ;
        pos[id] = cur ;
    }

    void gen_fail(){
        queue<int> q ;
        q.push(0) ;

        while(!q.empty()){
            int u = q.front() ;
            q.pop() ;

            for(int ch=0; ch<26; ch++){
                int v = trie[u].nxt[ch] ;
                if(!v) continue ;
                q.push(v) ;

                int temp = u ;
                while(temp){
                    int f = trie[temp].fail ;
                    if(trie[f].nxt[ch] != 0){
                        trie[v].fail = trie[f].nxt[ch] ;
                        break ;
                    }
                    temp = f ;
                }

                if(!temp) trie[v].fail = 0 ;

            }
        }
    }

    vector<int> search_pat(string text){
        gen_fail() ;

        int cur = 0 ;
        for(int i=0; i<text.size(); i++){
            int ch = text[i] - 'a' ;
            while( cur && trie[cur].nxt[ch] == 0)
                cur = trie[cur].fail ;

            cur = trie[cur].nxt[ch] ;
            int temp = cur ;
            while(temp){
                occurence[temp]++ ;
                temp = trie[temp].fail ;
            }
        }

        vector<int> ret ;
        for(int i=0; i<n; i++){
            int x = occurence[ pos[i] ] ;
            ret.push_back(x) ;
        }
        return ret ;
    }
};



int main(){
    int n ;
    cin>> n ;

    string text ;
    cin>> text ;

    aho_corasick aho(n) ;
    for(int i=0; i<n; i++){
        string pat ;
        cin>> pat ;
        aho.add_pat(pat, i) ;
    }

    vector<int> ans = aho.search_pat(text) ;
    
    for(int el: ans) cout<< el << "\n" ;

    return 0 ;
}