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

int n,bug ;
pii arr[105],dp[105][505] ;

pii func(int i,int rem){
    if(i==n || rem == 0) return pii(0,0) ;
    pii &ans = dp[i][rem] ;
    if(ans.ff != -1) return ans ;

    pii val1 = pii(0,0) ;
    if(rem - arr[i].ff >= 0){
        val1 = func(i+1,rem-arr[i].ff) ;
        val1.ff += arr[i].ff ;
        val1.ss += arr[i].ss ;
    }

    pii val2 = func(i+1,rem) ;
    if(val1.ss == val2.ss){
        if(val1.ff < val2.ff)
            ans = val1 ;
        else ans = val2 ;
    }
    else if(val1.ss > val2.ss)
        ans = val1 ;
    else ans = val2 ;
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

    while(cin>> bug >> n){
        if(bug == 0 && n == 0) break ;
        for(int i=0; i<n; i++)
            cin>> arr[i].ff >> arr[i].ss  ;
        memset(dp, -1, sizeof dp) ;

        pii ans = func(0,bug) ;

        cout<< ans.ff << " "<< ans.ss  << endl ;
    }

    return 0;
}
