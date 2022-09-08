#include<bits/stdc++.h>
using namespace std ;

/*
    Suffix array
    abcdef -> "", f, ef, def, cdef, bcdef, abcdef

    Time : n * logn * logn

*/


int main(){
    string str ;
    cin>> str ;
    str = str + "$" ;

    int n = str.size() ;
    vector<int> pos(n), grp(n) ;

    vector<pair<char, int> > arr(n) ;
    for(int i=0; i<n; i++)
        arr[i] = {str[i], i} ;
    
    sort(arr.begin(), arr.end()) ;
    for(int i=0; i<n; i++)
        pos[i] = arr[i].second ;
    grp[ pos[0] ] = 0 ;

    for(int i=1; i<n; i++){
        if(arr[i].first == arr[i-1].first)
            grp[ pos[i] ] = grp[ pos[i-1] ] ;
        else grp[ pos[i] ] = grp[ pos[i-1] ] + 1 ;
    }


    for(int k=0; (1<<k) < n; k++){

        vector< pair<pair<int,int>, int > > brr(n) ;
        for(int i=0; i<n; i++)
            brr[i] = {{grp[i], grp[ (i + (1<<k))%n ]}, i} ;
        
        sort(brr.begin(), brr.end()) ;
        for(int i=0; i<n; i++)
            pos[i] = brr[i].second ;
        grp[ pos[0] ] = 0 ;

        for(int i=1; i<n; i++){
            if(brr[i].first == brr[i-1].first)
                grp[ pos[i] ] = grp[ pos[i-1] ] ;
            else grp[ pos[i] ] = grp[ pos[i-1] ] + 1 ;
        }
    }

    for(int i=0; i<n; i++){
        cout<< pos[i] << " " << str.substr(pos[i], n-pos[i]) << "\n" ;
    }

    
    return 0 ;
}