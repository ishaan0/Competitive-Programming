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
#define     ed                  "\n"

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

    ll n,sum = 0 ;
    cin>> n ;
    vector<ll> arr(n+1) ;
    for(int i=1; i<=n; i++){
        cin>> arr[i] ;
        sum += arr[i] ;
    }
    if(sum%3!=0)
        cout<< "0" << endl ;
    else{
        ll temp = 0 ;
        sum /= 3 ;
        vector<ll> cnt(n+2) ;
        for(int i=n; i>=1; i--){
            temp += arr[i] ;
            if(temp == sum)
                cnt[i] = 1 ;
            cnt[i] += cnt[i+1] ;
        }
        temp = 0 ;
        ll ans = 0 ;
        for(int i=1; i+2<=n; i++){
            temp += arr[i] ;
            if(temp == sum)
                ans += cnt[i+2] ;
        }

        cout<< ans << endl ;
    }

    return 0;
}


