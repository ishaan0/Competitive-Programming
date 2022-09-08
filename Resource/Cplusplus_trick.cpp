#include<bits/stdc++.h>
using namespace std ;

#define     Boost       ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)   cont.begin(), cont.end()
#define     rall(cont)  cont.rbegin(), cont.rend()
#define     ll          long long
#define     pb          push_back
#define     mp          make_pair
#define     ff          first
#define     ss          second

/*  
    Some C++ tricks 
*/

int main(){
    Boost ;

    /** All those __builtin function are for integer . To use them
        for long long we need to add ll suffix of the function
        ex : builtin_popcount(10)  -> builtin_popcountll(1000)   */

    cout<< __builtin_ffs(10) << '\n' ;  /// return 1st on bit index + 1 from right , 
                                        /// 10 -> 1010 -> ( 1th bit + 1 ) -> 2
    cout<< __builtin_clz(16) << '\n' ; /// return count of leading zero of binary form

    cout<< __builtin_ctz(16) << '\n' ; /// return count of trailing zero of binary form

    cout<< __builtin_popcount(10) << '\n' /// return number of ON bit of binary form

    /** ----------------------------------------------------------------------------- */

    int a, b, c ;
    tie(a,b,c) = make_tuple(3,5,8) ;    /// Here all value will be assigned 

    tie(a,ignore,c) = make_tuple(300,500,800) ; /// it will ignore 2nd element

    /** ------------------------------------------------------------------------------ */

    for(int i=1; i<=4; i++)
        for(int j=1; j<=3; j++)
            cout<< i << " \n"[j==3] ;   /// it will print enter instead of space if j==3

    /** ------------------------------------------------------------------------------- */

    tuple<int,int,int> tp ;
    tp = make_tuple(1,2,3) ;        /// use tuple instead of struct , it is same as pair
                                    /// but we can store more than 2 values .

    cout<< get<0>(tp) << " " << get<1>(tp) << " " << get<2>(tp) << "\n" ;
    cout<< tuple_size<decltype(tp)>::value << "\n" /// get how many number are set in tuple

    /** -------------------------------------------------------------------------------- */

    vector<int> arr = {1,3,1,3} ;

    sort(arr.begin(), arr.end()) ;
    arr.erase(unique(arr.begin(), arr.end()) , arr.end()) ;  /// delete duplicate elements .

    /// or we can use remove duplicate by resize 
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin()) ;

    /** ---------------------------------------------------------------------------------- */

    vector<int> arr(10), brr(10) ;
    fill(arr.begin(), arr.end(), 3) ;  // fill the vector with 5 . 
    iota(brr.begin(), brr.end(), 0) ;  // fill the vector with 0, 1, 2, ... to the end

    /** ---------------------------------------------------------------------------------- */

    set<int, cmp> s ; 

    /* This part will be on global
        struct cmp{
            bool operator () (int const &a, int const &b) const{
                return a > b ;
            }
        }
    */

    // we can use custor comparator for set and priority queue , but we need to 
    // remember that in priority queue all compare operator will be opposite .

    return 0 ;
}