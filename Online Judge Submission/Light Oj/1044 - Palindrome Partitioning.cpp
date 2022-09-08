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

string str ;
ll dp1[1005][1005],dp2[1005] ;

ll func1(ll i,ll j){
    if(i>=j) return 1 ;
    ll &ans = dp1[i][j] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    if(str[i] == str[j] && func1(i+1,j-1))
          ans = 1 ;
    return ans ;
}

ll func2(ll i){

    ll &ans = dp2[i] ;
    if(ans != -1) return ans ;
    ans = INT_MAX ;
    if(func1(0,i)) ans = 1 ;
    for(ll j=i; j>0; j--)
        if(func1(j,i)) ans = min(ans,1+func2(j-1)) ;
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
        cin>> str ;
        memset(dp1,-1,sizeof dp1) ;
        memset(dp2,-1,sizeof dp2) ;
        ll ans = func2(str.size()-1) ;
        Case ;
        cout<< ans << endl ;
    }


    return 0;
}


