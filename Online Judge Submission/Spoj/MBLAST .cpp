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
int k ,dp[2005][2005] ;

int func(int i,int j){
    if(i == str1.size())
        return (k*(str2.size()-j)) ;
    else if(j == str2.size())
        return (k*(str1.size()-i)) ;
    int &ans = dp[i][j] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    if(str1[i] == str2[j])
        ans = func(i+1,j+1) ;
    else{
        int val1 = k+func(i+1,j) ;
        int val2 = k+func(i,j+1) ;
        int val3 = abs(str1[i]-str2[j])+func(i+1,j+1) ;
        ans = min(val1,val2) ;
        ans = min(ans,val3) ;
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

    memset(dp, -1, sizeof dp) ;
    cin>> str1 >> str2 >> k ;
    int ans = func(0,0) ;
    cout<< ans << endl ;
    return 0;
}







