#include<bits/stdc++.h>
using namespace std ;


struct Trie{
    #define max_leaf  30
    struct node{
        int endPoint ;
        node* next[max_leaf] ;
        node(){
            endPoint = 0 ;
            for(int i = 0; i < max_leaf; i++) next[i] = NULL ;
        }
    };
    node* rootNode ;

    Trie(){rootNode = new node ;}

    void add_str(string str){
        int len = str.size() ;
        node* cur = rootNode ;
        for(int i = 0; i < len; i++){
            int ch = str[i] - 'a' ;
            if(cur->next[ch] == NULL) cur->next[ch] = new node ;
            cur = cur->next[ch] ;
        }
        cur->endPoint++ ;
    }

    bool search_str(string str){
        int len = str.size() ;
        node* cur = rootNode ;
        for(int i = 0; i < len; i++){
            int ch = str[i] - 'a' ;
            if(cur->next[ch] == NULL) return false ;
            cur = cur->next[ch] ;
        }
        return (cur->endPoint > 0) ;
    }

    void delete_trie(node* cur){
        for(int i = 0; i < max_leaf; i++)
            if(cur->next[i]) delete_trie(cur->next[i]) ;
        delete (cur) ;
    }
    ~Trie(){ delete_trie(rootNode) ;}
};

int main(){
    Trie tr ;

    int n ;
    cin>> n ;

    for(int i = 0; i < n; i++){
        string str ;
        cin>> str ;
        tr.insert_str(str) ;
    }

    int q ;
    cin>> q ;
    while(q--){
        string str ;
        cin>> str ;
        if(tr.search_str(str))
            cout<< "Found !!!\n" ;
        else cout<< "Not found !!\n" ;
    }
    
    return 0 ;
}