#include<bits/stdc++.h>
using namespace std ;

class genCombinationByBacktracking{
    vector<int> arr ;
public:
    genCombinationByBacktracking(vector<int> a){
        arr = a ;
        cout<< "All Permutation are : " << endl;
        genCombination(0,arr.size()-1) ;
    }

    void genCombination(int lo, int hi){

    }

};


int main(){


    return 0 ;
}
