#include<bits/stdc++.h>
using namespace std ;

/**
    This algorithm represent a fraction
    into sum of other fraction .
    6/14 ->  1/3 + 1/11 + 1/231
*/

void func(int nr,int dr){
    if(nr == 0 || dr == 0)
        cout<< "No Solution" << endl , return ;
    if(dr%nr == 0)
        cout<< "1/" << dr/nr << endl , return ;
    if(nr%dr == 0)
        cout<< nr/dr << endl , return ;
    if(nr > dr){
        cout<< nr/dr << " + " ;
        func(nr%dr,dr) ;
        return ;
    }
    int n = dr/nr + 1 ;
    cout<< "1/" << n << " + " ;
    func(nr*n-dr,dr*n) ;
}

int main(){
    int nr = 6 , dr = 14 ;
    cout<< "Egyptian fraction of " << nr<<"/"<<dr <<" -> " ;
    func(nr,dr) ;
    return 0 ;
}
