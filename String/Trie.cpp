#include<bits/stdc++.h>
using namespace std ;
#define lim 1005

int ind ;
bool flag[lim] ;
int trie[lim][26] ;

void add(string str){
    int cur = 0 ;
    for(int i=0; i<str.size(); i++){
        int id = str[i]-'a' ;
        if(!trie[cur][id]) trie[cur][id] = ++ind ;
        cur = trie[cur][id] ;
    }
    flag[cur] = true ;
}

bool query(string str){
    int cur = 0 ;
    for(int i=0; i<str.size(); i++){
        int id = str[i]-'a' ;
        if(!trie[cur][id]) return false ;
        cur = trie[cur][id] ;
    }
    return flag[cur] ;
}


int main(){

    ind = 0 ;
    int n,q ;
    cin>> n ;
    for(int i=0; i<n; i++){
        string str ;
        cin>> str ;
        add(str) ;
    }

    cin>> q ;
    while(q--){
        string str ;
        cin>> str ;
        if(query(str))
            cout<< "Found" << endl ;
        else cout<< "NOt Found" << endl ;
    }


    return 0 ;
}

