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
ll dp[5005][3] ;

ll func(ll i,int last){
    if(i>=str.size()) return 1 ;
    if(last==0 && str[i]=='0' ) return 0 ;
    ll &ans = dp[i][last] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    if(str[i] != '0')
        ans += func(i+1,1) ;
    if(i!=0 && last == 1){
        if(str[i-1] == '1' || (str[i-1]=='2' && str[i]>='0' && str[i]<='6'))
            ans += func(i+1,0) ;
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

    while(cin>> str){
        memset(dp,-1,sizeof dp) ;
        if(str == "0") break ;
        ll ans = func(0,1) ;
        cout<< ans << endl ;
    }

    return 0;
}



