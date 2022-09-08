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

const int lim = 1e5+5 ;

int arr[lim], n ;

namespace STACK{
    stack<pair<int,int> > stk ;

    void add_value(int val){
        int mn = (stk.empty()) ? val : min(val, stk.top().ss) ;
        stk.push(mp(val, mn)) ;
    }
    int del_value(){
        int val = stk.top().ff ;
        stk.pop() ;
        return val ;
    }
    int get_min(){
        return stk.top().ss ;
    }
}

namespace QUEUE{
    int cnt_add = 0 , cnt_del = 0 ;
    deque<pair<int,int> > q ;

    void add_value(int val){
        while(!q.empty() && val < q.back().ff)
            q.pop_back() ;
        q.push_back(mp(val,cnt_add++)) ;
    }
    void del_value(){
        if(!q.empty() && q.front().ss == cnt_del)
            q.pop_front() ;
        cnt_del++ ;
    } 
    int get_min(){
        return q.front().ff ;
    }
}


int main(){
    Boost ;

    cin>> n ;
    for(int i=0; i<n; i++) cin>> arr[i] ;

    for(int i=0; i<n; i++){
        STACK::add_value(arr[i]) ;
        QUEUE::add_value(arr[i]) ;
    }

    cout<< STACK::get_min() << "\n" ;
    cout<< QUEUE::get_min() << "\n" ;

    
    return 0 ;
}