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
unordered_map<string,bool> m ;
vector<string> arr ;
ll sz,dp[105][105][105] ;


ll func(ll i,ll j,ll k){
    ll lim = arr[0].size()-(sz-1-i) ;
    if(k==arr[0].size() && k<lim) return 1 ;
    if(i>=sz) return 0 ;
    if(k>=lim) return 0 ;
    if(j>=arr[i].size()) return 0 ;



    ll &ans = dp[i][j][k] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    if(tolower(arr[i][j]) == tolower(arr[0][k])){
        ans += func(i,j+1,k+1) ;
        ans += func(i+1,0,k+1) ;
    }
    ans += func(i,j+1,k) ;

    return ans ;

}




ll splitString(string str){
    istringstream ss(str) ;
    ll i=0 ;
    do{
        string word ;
        ss>> word ;
        if(!m.count(word) && word != ""){
            arr.pb(word) ;
            i++ ;
        }
    }
    while(ss);
    return i ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll n ;
    while(cin>> n ){
        if(n == 0) break ;
        m.clear() ;
        for(ll i=0; i<n; i++){
            string temp ;
            cin>> temp ;
            m[temp] = true ;
        }
        string temp ;
        flush ;
        while(getline(cin,temp)){
            if(temp == "LAST CASE")
                break ;
            arr.clear() ;
            memset(dp,-1,sizeof dp) ;
            sz = splitString(temp) ;
            ll ans = func(1,0,0) ;
            cout<< arr[0] ;
            if(ans == 0)
                cout<< " is not a valid abbreviation" << endl ;
            else
                cout<< " can be formed in " << ans << " ways" << endl ;
        }
    }

    return 0;
}



