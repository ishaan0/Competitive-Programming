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
int arr[110] ;
pii dp[110][110] ;

pii func(int i,int j){
    if(i==j) return pii(arr[i],0) ;
    pii &ans = dp[i][j] ;
    if(ans.ff != -1) return ans ;
    ans = pii(0,INT_MAX) ;
    for(int k=i; k<j; k++){
        pii val1 = func(i,k) ;
        pii val2 = func(k+1,j) ;
        pii val ;
        val.ff = (val1.ff+val2.ff)%100 ;
        val.ss = (val1.ff*val2.ff)+(val1.ss+val2.ss) ;
        if(val.ss < ans.ss)
            ans = val ;
    }
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

    while(cin>> n ){
        for(int i=0; i<n; i++)
            cin>> arr[i] ;
        memset(dp, -1, sizeof dp) ;
        pii ans = func(0,n-1) ;
        cout<< ans.ss << endl ;
    }

    return 0;
}

