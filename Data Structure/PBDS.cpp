#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;

/**
    ordered set is same as set but it has two more function .
    find_by_order(k) : This will give us kth index value for
                       a sorted set (0 based index) . It will
                       return iterator .
    order_of_key(val): This will give us how many numbers are
                       strictly less than val .
*/

int main(){
    int n ;
    cin>> n ;

    ordered_set<int> s ;
    for(int i=0; i<n; i++){
        int val ;
        cin>> val ;
        s.insert(val) ;
    }

    int q ;
    cin>> q ;

    while(q--){
        int type, val ;
        cin>> type >> val ;
        if(type == 1)
            cout<< *(s.find_by_order(val-1)) << endl ;
        else cout<< s.order_of_key(val) << endl ;
    }

    return 0 ;
}
