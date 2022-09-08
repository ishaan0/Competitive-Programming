#include<bits/stdc++.h>
using namespace std ;

/*
    KMP -> Knuth-Morris-Pratt
    This is string matching algorithm
    lps -> longest prefix suffix , means
           longest prefix where suffix are 
           also same. Also called prefix function.
    Time : O( n + m) , where n -> text size, m -> pattern size
*/


vector<int> prefix_function(string pattern){
    int m = pattern.size() , i = 1, j = 0 ;
    vector<int> lps(m) ;
    while(i < m){
        if(pattern[j] == pattern[i])
            lps[i++] = ++j ;
        else if(j != 0) j = lps[j-1] ;
        else lps[i++] = 0 ;
    }
    return lps ;
}

vector<int> kmp(string text, string pattern){
    vector<int> lps = prefix_function(pattern), occurence ;
    int i = 0, j = 0, n = text.size(), m = pattern.size() ;
    // i -> text , j -> pattern
    while(i < n){
        if(text[i] == pattern[j]) i++, j++ ;
        else if(j != 0) j = lps[j-1] ;
        else i++ ;

        if(j == m){
            occurence.push_back(i - m) ;
            j = lps[j-1] ;
        }
    }

    return occurence ;
}


int main(){
    string text, pattern ;
    getline(cin, text) ;
    getline(cin, pattern) ;

    vector<int> occurence = kmp(text, pattern) ;

    if(occurence.size() == 0) cout<< "No match found\n" ;
    else{
        cout<< "Found at positon : " ;
        for(int el: occurence) cout<< el << " " ;
        cout<< "\n" ;
    }
    
    return 0 ;
}