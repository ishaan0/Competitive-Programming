#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &value: cont)
#define     show(val)           cout<< #val << " -> " << val << endl
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs << ": "
#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;

int k,l,m,dp[1000005] ;

int func(int rem){
    if(rem<=0) return 0 ;
    int &ans = dp[rem] ;
    if(ans != -1) return ans ;
    int arr[] = {rem-k,rem-l,rem-1} ;
    ans = 0 ;
    for(int i=0; i<3; i++)
        if(arr[i]>=0 && func(arr[i])==0)
            ans = 1 ;
    return ans ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    cin>> k >> l >> m ;
    memset(dp,-1,sizeof dp) ;
    string ans = "" ;

    for(int i=0; i<m; i++){
        int val  ;
        cin>> val ;
        if(func(val)) ans += "A" ;
        else ans += "B" ;
    }

    cout<< ans << endl ;

    return 0;
}








