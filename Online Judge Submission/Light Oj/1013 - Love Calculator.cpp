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
pair<ll,ll> dp[35][35] ;

pair<ll,ll> func(ll i,ll j){
    //cout<< "de-> " << i<< " " << j << endl ;
    if(i==str1.size())
        return pair<ll,ll> (str2.size()-j,1) ;
    else if(j==str2.size())
        return pair<ll,ll> (str1.size()-i,1) ;
    pair<ll,ll> &ans = dp[i][j] ;
    if(ans.ff != -1) return ans ;
    if(str1[i] == str2[j]){
        ans = func(i+1,j+1) ;
        ans.ff += 1 ;
    }
    else{
        pair<ll,ll> val1 = func(i+1,j) ,val2 = func(i,j+1);
        if(val1.ff == val2.ff){
            ans = val1 ;
            ans.ss += val2.ss ;
        }
        else if(val1.ff < val2.ff)
            ans = val1 ;
        else ans = val2 ;
        ans.ff += 1 ;
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

    int t ,cs=0 ;
    cin>> t ;

    while(t--){
        cin>> str1 >> str2 ;
        memset(dp,-1,sizeof dp) ;
        pair<ll,ll> ans = func(0,0) ;
        Case ;
        cout<< ans.ff << " " << ans.ss << endl ;
    }


    return 0;
}


