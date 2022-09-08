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

string str1,str2,str3 ;
int dp[55][55][55] ;

int func(int i,int j,int k){
    if(i>=str1.size() || j>=str2.size() || k>=str3.size())
        return 0 ;
    int &ans = dp[i][j][k] ;
    if(ans != -1) return ans ;

    if(str1[i] == str2[j] && str1[i]==str3[k]){
        ans = 1 + func(i+1,j+1,k+1) ;
    }
    else{
        ans = func(i+1,j,k) ;
        ans = max(ans,func(i,j+1,k)) ;
        ans = max(ans,func(i,j,k+1)) ;
        ans = max(ans,func(i+1,j+1,k)) ;
        ans = max(ans,func(i,j+1,k+1)) ;
        ans = max(ans,func(i+1,j,k+1)) ;
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
        cin>> str1>>str2>>str3 ;
        memset(dp,-1,sizeof dp) ;
        int ans = func(0,0,0) ;
        Case ;
        cout<< ans << endl ;
    }

    return 0;
}


