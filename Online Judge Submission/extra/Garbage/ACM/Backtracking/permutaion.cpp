#include<bits/stdc++.h>
using namespace std ;

/// using STL generate permutation of an array
class genPermutationByStl{
public:

    genPermutationByStl(vector<int>& arr){
        sort(arr.begin(), arr.end()) ;
        cout<< "All Permutation are :" << endl;
        do{
            display(arr) ;
        }while(next_permutation(arr.begin(),arr.end())) ;
    }

    void display(vector<int> arr){
        for(auto &value : arr)
            cout<< value << " ";
        cout<< endl;
    }

};


/// using backtraking generate permutation of an array
class genPermutationByBacktrack{
    vector<int> arr ;
public:
    genPermutationByBacktrack(vector<int> a){
        arr = a ;
        cout<< "All Permutation are :" << endl;
        genPermutation(0,arr.size()-1) ;
    }

    void genPermutation(int lo, int hi){
        if(lo == hi)
            display() ;
        else for(int i=lo; i<=hi; i++){
              swap(arr[lo],arr[i]) ;
              genPermutation(lo+1,hi) ;
              swap(arr[lo],arr[i]) ;
            }
    }

    void display(){
        for(auto &value: arr)
            cout<< value << " ";
        cout<< endl;
    }
};

/// using backtraking generate permutation by 1 to n
class genPermutationFron1ToN{
    vector<bool> used ;
    vector<int> number ;
public:
    genPermutationFron1ToN(int n){
        used.resize(n+1) ;
        number.resize(n+1) ;
        cout<< "All Permutation are :" << endl;
        genPermutation(1,n) ;
    }

    void genPermutation(int lo, int hi){
        if(lo == hi+1)
            display() ;
        else{
            for(int i=1; i<=hi; i++) if(!used[i]){
                used[i] = true ;
                number[lo] = i ;
                genPermutation(lo+1, hi) ;
                used[i] = false ;
            }
        }
    }

    void display(){
        for(auto &value: number)
            if(value != 0)
            cout<< value << " " ;
        cout<< endl ;
    }

};
int main(){

    vector<int> arr = {1,2,3} ;

    genPermutationByStl ob1(arr) ;

    genPermutationByBacktrack ob2(arr) ;

    genPermutationFron1ToN ob3(3) ;

    return 0 ;
}
