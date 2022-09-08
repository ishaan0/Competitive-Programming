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



#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n ;
    cin>> n ;
    vector<int> arr(n) ;
    foreach(arr) cin>> value ;
    sort(all(arr)) ;

    ll ans = INT_MIN ;
    for(int i=0; i<n; i++){
        int lo = i, hi= n-1 ;
        int pos = -1 ;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2 ;
            if(arr[i]*2 >= arr[mid]){
                pos = mid ;
                lo = mid+1 ;
            }
            else hi = mid-1 ;
        }
        ans = max(ans,(ll)pos-i+1) ;
    }

    ans = (ll)n - ans ;

    cout<< ans << endl ;

    return 0;
}


