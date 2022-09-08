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
#define mod 998244353
#define lim 200005




//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,k ;
    cin>> n >> k ;
    vector<int> arr(n) ;
    vector<pii > temp(n);
    for(int i=0; i<n; i++){
        cin>> arr[i] ;
        temp[i] = mk(arr[i],i) ;
    }
    sort(rall(temp)) ;
    vector<int> temp2  ;
    ll ans = 0 ;
    ll res = 1 ;
    for(int i=0; i<k; i++){
        ans += temp[i].ff ;
        temp2.pb(temp[i].ss) ;
    }
    sort(all(temp2)) ;
    for(int i=0; i<k ;i++){
        if(i!=0)
            res = ((res%mod)*((temp2[i]-temp2[i-1])%mod))%mod ;
    }

    cout<< ans <<  " " << res << endl ;

    return 0;
}

