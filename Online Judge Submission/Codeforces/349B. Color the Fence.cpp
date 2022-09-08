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



//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll n,mn=INT_MAX ;
    cin>> n;
    vector<ll> arr(10) ;
    for(int i=1; i<=9; i++){
        cin>> arr[i] ;
        mn = min(mn,arr[i]) ;
    }

    ll len = n/mn ;
    if(len == 0)
        return cout<< "-1" << endl , 0 ;

    vector<int> ans ;
    ll sum = 0 ;
    for(int i=1; i<=len; i++){
        for(int j=9; j>=1; j--){
            ll temp = sum+arr[j]+(len-i)*mn ;
            if(temp <= n){
                ans.pb(j) ;
                sum += arr[j] ;
                break ;
            }
        }
    }


    foreach(ans) cout<< value ;
    cout<< endl ;

    return 0;
}


