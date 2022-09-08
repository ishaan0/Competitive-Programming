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
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>> t ;

    while(t--){
        ll n,x ;
        cin>> n >> x ;
        ll mx = INT_MIN ;
        unordered_set<ll> s ;
        for(int i=0; i<n; i++){
            ll temp ;
            cin>> temp ;
            mx = max(mx,temp) ;
            s.insert(temp) ;
        }
        if(s.count(x))
            cout<< "1" << endl ;
        else if(mx > x){
            cout<< "2" << endl ;
        }
        else{
            ll ans = x/mx ;
            if(x%mx != 0 ) ans++ ;
            cout<< ans << endl ;
        }
    }


    return 0;
}

