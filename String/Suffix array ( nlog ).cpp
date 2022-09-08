#include<bits/stdc++.h>
using namespace std ;

/*
    Suffix array : 
    abcdef -> "", f, ef, def, cdef, bcdef, abcdef
    
    SA[i] = sorted list's ith suffix start position in actual string .
    _rank[i] = suffix of actual string which start at i, rank number
             in sorted suffix array or position at sorted list.
    lcp[i] = longest common prefix for consecutive suffix in 
             sorted suffix array . lcp[i] means common prefix 
             between i and i-1 suffixes from sorted list.

    Time : n * logn

*/

namespace sa{
    int n ;
    string str ;
    vector<int> SA, _rank, lcp ;

    void count_sort(){
        vector<int> cnt(n) ;
        for(int i: _rank)
            cnt[i]++ ;

        vector<int> SA_new(n), left_idx(n) ;
        left_idx[0] = 0 ;

        for(int i=1; i<n; i++)
            left_idx[i] = left_idx[i-1] + cnt[i-1] ;

        for(int i: SA){
            int id = _rank[i] ;
            SA_new[ left_idx[id] ] = i ;
            left_idx[id]++ ;  
        }
        SA = SA_new ;
    }

    void build_suffix_array(){
        vector<pair<char, int> > arr(n) ;
        for(int i=0; i<n; i++)
            arr[i] = {str[i], i} ;
        sort(arr.begin(), arr.end()) ;

        for(int i=0; i<n; i++) SA[i] = arr[i].second ;
        _rank[ SA[0] ] = 0 ;

        for(int i=1; i<n; i++){
            _rank[ SA[i] ] = _rank[ SA[i-1] ] ;
            if(arr[i].first != arr[i-1].first)
                _rank[ SA[i] ]++ ;
        }

        for(int k=0; (1<<k) < n; k++){
            for(int i=0; i<n; i++)
                SA[i] = ( SA[i] - (1<<k) + n ) % n ;
            count_sort() ;

            vector<int> _rank_new(n) ;
            _rank_new[ SA[0] ] = 0 ;

            for(int i=1; i<n; i++){
                pair<int,int> prev = { _rank[ SA[i-1] ], _rank[ (SA[i-1] + (1<<k))%n ] } ;
                pair<int,int> cur = { _rank[ SA[i] ], _rank[ (SA[i] + (1<<k))%n ] } ;

                _rank_new[ SA[i] ] = _rank_new[ SA[i-1] ] ;
                if(cur != prev) _rank_new[ SA[i] ]++ ;
            }
            _rank = _rank_new ;
        }
    }

    void build_lcp(){
        int k = 0 ;
        for(int i=0; i<n-1; i++){
            int pi = _rank[i] ;
            int j = SA[ pi-1 ] ; 
            while(i+k<n && j+k<n && str[ i+k ] == str[ j+k ]) k++ ;
            lcp[ pi ] = k ;
            k = max(0, k-1) ;
        }
    }

    void init(string _str){
        str = _str + "$" ; 
        n = str.size() ;
        SA.resize(n, 0) ;
        _rank.resize(n, 0) ;
        lcp.resize(n, 0) ;
        build_suffix_array() ;
        build_lcp() ;
    }

    void print_suffix(){
        cout<< "Suffixes :\n" ;
        for(int i=0; i<n; i++)
            cout<< SA[i] << " " << str.substr(SA[i], n-SA[i]) << "\n" ;
    }

    void print_lcp(){
        cout<< "LCP :\n" ;
        for(int i=0; i<n; i++)
            cout<< lcp[i] << "\n" ;
    }


}



int main(){
    sa::init("aacaac") ;

    sa::print_suffix() ;
    sa::print_lcp() ;
    
    return 0 ;
}