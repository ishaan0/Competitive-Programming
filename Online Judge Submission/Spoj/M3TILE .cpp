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

int dp[35] ;

int func(int n){
    if(n == 0) return 1 ;
    if(n==2) return 3 ;
    if(n<4) return 0 ;
    int &ans = dp[n] ;
    if(ans != -1) return ans ;
    ans = 4*func(n-2)-func(n-4) ;
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

    int n ;
    while(cin>> n){
        if(n == -1) break ;
        memset(dp, -1, sizeof dp) ;
        int ans = func(n) ;
        cout<< ans << endl ;
    }

    return 0;
}





