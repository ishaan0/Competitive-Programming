#include<bits/stdc++.h>
using namespace std ;

/*
    Suffix array : 
    abcdef -> "", f, ef, def, cdef, bcdef, abcdef
    
    SA[i] = sorted list's ith suffix start position in actual string .
    RA[i] = suffix of actual string which start at i, rank number
             in sorted suffix array or position at sorted list.
    lcp[i] = longest common prefix for consecutive suffix in 
             sorted suffix array . lcp[i] means common prefix 
             between i and i-1 suffixes from sorted list.

    Time : n * logn

*/

namespace sa{
    int n ;
    string str ;
    vector<int> SA, RA, lcp ;

    void count_sort(){
        vector<int> cnt(n) ;
        for(int i: RA)
            cnt[i]++ ;

        vector<int> SA_new(n), left_idx(n) ;
        left_idx[0] = 0 ;

        for(int i=1; i<n; i++)
            left_idx[i] = left_idx[i-1] + cnt[i-1] ;

        for(int i: SA){
            int id = RA[i] ;
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
        RA[ SA[0] ] = 0 ;

        for(int i=1; i<n; i++){
            RA[ SA[i] ] = RA[ SA[i-1] ] ;
            if(arr[i].first != arr[i-1].first)
                RA[ SA[i] ]++ ;
        }

        for(int k=0; (1<<k) < n; k++){
            for(int i=0; i<n; i++)
                SA[i] = ( SA[i] - (1<<k) + n ) % n ;
            count_sort() ;

            vector<int> rank_new(n) ;
            rank_new[ SA[0] ] = 0 ;

            for(int i=1; i<n; i++){
                pair<int,int> prev = { RA[ SA[i-1] ], RA[ (SA[i-1] + (1<<k))%n ] } ;
                pair<int,int> cur = { RA[ SA[i] ], RA[ (SA[i] + (1<<k))%n ] } ;

                rank_new[ SA[i] ] = rank_new[ SA[i-1] ] ;
                if(cur != prev) rank_new[ SA[i] ]++ ;
            }
            RA = rank_new ;
        }
    }

    void build_lcp(){
        int k = 0 ;
        for(int i=0; i<n; i++){
            if(RA[i] <= 0) continue ;
            int j = SA[ RA[i]-1 ] ; 
            while(i+k<n && j+k<n && str[ i+k ] == str[ j+k ]) k++ ;
            lcp[ RA[i] ] = k ;
            if(k > 0) k-- ;
        }
    }

    void init(string _str){
        str = _str + "$" ; 
        n = str.size() ;
        SA.assign(n, 0) ;
        RA.assign(n, 0) ;
        lcp.assign(n, 0) ;
        build_suffix_array() ;
        build_lcp() ;
    }

    void print_all(){
        cout<< endl << str << endl ;
        cout<< "R L S\n\n" ;
        for(int i = 0; i < n; i++)
            cout<< RA[i] << " " << lcp[i] << " " << SA[i] << " " << str.substr(SA[i], n-SA[i]) << "\n" ;
    }


}



int main(){
    sa::init("aacaab") ;

    sa::print_all() ;
    
    return 0 ;
}