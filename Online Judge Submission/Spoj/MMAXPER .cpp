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

int n ,dp[1010][2] ;
pii arr[1010] ;

int func(int i,int take){
    if(i==n) return 0 ;
    int &ans = dp[i][take] ;
    if(ans != -1) return ans ;
    int sum = 0,temp=0 ;
    if(i!=0){
        if(take) temp = arr[i-1].ss ;
        else temp = arr[i-1].ff ;
        sum = abs(arr[i].ff - temp) ;
    }
    ans = sum + arr[i].ss + func(i+1,0) ;
    sum = 0 ;
    if(i!=0){
        if(take) temp = arr[i-1].ss ;
        else temp = arr[i-1].ff ;
        sum = abs(arr[i].ss - temp) ;
    }
    ans = max(ans,sum+arr[i].ff+func(i+1,1)) ;

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

    cin>> n;
    for(int i=0; i<n; i++)
        cin>> arr[i].ff >> arr[i].ss ;
    memset(dp, -1, sizeof dp) ;

    int ans = func(0,0) ;
    cout<< ans << endl ;

    return 0;
}


