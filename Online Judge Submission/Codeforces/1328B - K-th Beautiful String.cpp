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

    vector<ll> sum ;
    sum.pb(0),sum.pb(1) ;
    for(ll i=2; i<=100005; i++)
        sum.pb(sum[i-1]+i) ;
    int t ;
    cin>> t ;

    while(t--){
        ll n,k,p1=0,p2=0;
        cin>> n >> k ;
        p1 = lower_bound(all(sum),k)-sum.begin() ;
        ll rem = sum[p1]-k ;
        p1 = n-1-p1 ;
        p2 = p1+1+rem ;
        for(int i=0; i<n; i++){
            if(i==p1 || i==p2)
                cout<< "b" ;
            else cout<< "a" ;
        }
        cout<< endl ;
    }

    return 0;
}

