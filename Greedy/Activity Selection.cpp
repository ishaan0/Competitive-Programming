#include<bits/stdc++.h>
using namespace std ;
#define pii pair<int,int>

/**
    If I have some time schedule then
    to do more work, I need to pick
    those work whose end time is earlier
*/

bool cmp(pii a,pii b){
    if(a.ss == b.ss)
        return a.ff < b.ff ;
    return a.ss < b.ss ;
}

int main(){
    int n,ans=1;
    cin>> n ;
    vector<pii > arr(n) ;
    for(int i=0; i<n; i++)
        cin>> arr[i].first >> arr[i].second ;

    sort(arr.begin(),arr.end(),cmp) ;

    int prev = arr[0].ss ;
    for(int i=1; i<n; i++){
        if(arr[i].ff > prev){
            prev = arr[i].ss ;
            ans++ ;
        }
    }

    cout<< ans << endl ;

    return 0 ;
}
