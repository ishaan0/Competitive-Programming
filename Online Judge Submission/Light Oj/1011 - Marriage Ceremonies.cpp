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

int n ;
int arr[20][20] ;
int dp[17][(1<<16)+5] ;

int setBit(int mask,int pos){ return mask=(mask|(1<<pos)); }
bool chkBit(int mask,int pos){ return (bool)(mask&(1<<pos)); }

int func(int in,int mask){
    if(in == n) return 0 ;
    int &ans = dp[in][mask] ;
    if(ans != -1) return ans ;
    ans = 0 ;

    for(int i=0; i<n; i++){
        if(!chkBit(mask,i))
            ans = max(ans,arr[in][i]+func(in+1,setBit(mask,i))) ;
    }
    return ans ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0 ;
    cin>> t ;

    while(t--){
        cin>> n  ;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>> arr[i][j] ;
        memset(dp, -1, sizeof dp) ;
        int ans = func(0,0) ;
        Case ;
        cout<< ans << endl ;
    }

    return 0;
}


