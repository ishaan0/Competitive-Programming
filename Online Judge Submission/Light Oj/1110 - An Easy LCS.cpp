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
ll dp[105][105] ;

ll func(ll i,ll j){
    if(i==str1.size() || j==str2.size())
        return 0 ;
    ll &ans = dp[i][j] ;
    if(ans != -1) return ans ;

    if(str1[i] == str2[j])
        ans = 1+func(i+1,j+1) ;
    else ans = max(func(i+1,j),func(i,j+1)) ;
    return ans ;
}

void print(ll a,ll b,ll lcs){

    for(ll add=0; add<lcs; add++){
        for(char ch='a'; ch<='z'; ch++){
            ll i,j,temp=add;
            for(i=a; i<str1.size() && str1[i]!=ch ; i++) ;
            for(j=b; j<str2.size() && str2[j]!=ch ; j++) ;
            if(str1[i]==ch && str2[j]==ch && dp[i][j]+temp == lcs){
                a = i+1 ;
                b = j+1 ;
                temp++ ;
                cout<< ch ;
            }
            if(temp == lcs) break ;
        }

    }
    cout<< endl ;
}


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0 ;
    cin>> t ;

    while(t--){
        cin>> str1 >> str2 ;
        memset(dp,-1,sizeof dp) ;
        ll ans = func(0,0) ;
        Case ;
        if(ans == 0)
            cout<< ":(" << endl ;
        else print(0,0,ans) ;
    }

    return 0;
}


