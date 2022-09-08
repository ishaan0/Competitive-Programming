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

int n,mw,p[1005],w[1005],dp[1005][35] ;

int func(int i,int have){
    if(i>=n) return 0 ;
    int &ans = dp[i][have] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    if(have+w[i] <= mw)
        ans += p[i]+func(i+1,w[i]+have) ;
    ans = max(ans,func(i+1,have)) ;
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

    int t ;
    cin>> t ;
    while(t--){
        cin>> n ;
        for(int i=0; i<n; i++)
            cin>> p[i] >> w[i] ;

        int g ,total=0 ;
        cin>> g ;
        while(g--){
            cin>> mw ;
            memset(dp,-1,sizeof dp) ;
            total += func(0,0) ;
        }

        cout<< total << endl ;

    }


    return 0;
}




