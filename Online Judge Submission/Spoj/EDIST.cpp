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

string str1,str2 ;
int dp[2005][2005] ;

int func(int i,int j){
    if(i ==  str1.size()) return (str2.size()-j) ;
    if(j == str2.size()) return (str1.size()-i) ;
    int &ans = dp[i][j] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    if(str1[i] == str2[j])
        ans = func(i+1,j+1) ;
    else{
        ans = func(i+1,j) ;
        ans = min(ans,func(i,j+1)) ;
        ans = min(ans,func(i+1,j+1)) ;
        ans++ ;
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

    int t ;
    cin>> t ;

    while(t--){
        memset(dp,-1,sizeof dp) ;
        cin>> str1 >> str2 ;
        int ans = func(0,0) ;
        cout<< ans << endl ;
    }


    return 0;
}

