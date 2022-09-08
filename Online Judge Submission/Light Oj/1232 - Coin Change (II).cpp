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
#define mod 100000007

int coin[105],ways[10005],n,k;

int func(){
    memset(ways,0,sizeof ways) ;
    ways[0] = 1 ;
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++)
            ways[j] = ((ways[j]%mod)+(ways[j-coin[i]]%mod))%mod ;
    }
    return ways[k] ;
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
        cin>> n >> k ;
        for(int i=0; i<n; i++)
            cin>> coin[i] ;
        int ans = func() ;
        Case ;
        cout<< ans << endl ;
    }


    return 0;
}


