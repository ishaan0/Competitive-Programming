#include<bits/stdc++.h>
using namespace std ;



int main(){
    int n ;
    cin>> n ;

    vector<int> arr(n) ;    
    for(int i=0; i<n; i++)
        cin>> arr[i] ;

    stack<int> stk ;
    int area = 0, i = 0 ;
    for( ; i<n; i++){
        if(stk.empty() || arr[i] >= arr[ stk.top() ])
            stk.push(i) ;
        else{
            while(!stk.empty() && arr[i] < arr[ stk.top() ]){
                int tp = stk.top() ;
                stk.pop() ;
                area = max(area, arr[tp] * ((stk.empty()) ? i : (i - stk.top() - 1))) ;
            }
            stk.push(i) ;
        }
    } 

    while(!stk.empty()){
        int tp = stk.top() ;    
        stk.pop() ;
        area = max(area, arr[tp] * ((stk.empty()) ? i : i-stk.top()-1 )) ;
    }

    cout<< area << "\n" ;
    
    return 0 ;
}