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

    ll t ;
    cin>> t ;

    while(t--){
        ll n , m ;
        cin>> n >> m ;

        if(m == 0){
            cout<< "0" << endl ;
            continue ;
        }

        ll temp = (m-1) ;
        ll ans = (m*n) - ((temp*(temp+1))/2) ;
        if(m >= n/2){
            temp = max((n-m)-1,0LL) ;
            ans += (temp*(temp+1))/2 ;
        }
        else{
            ll block = (m+1) ;
            temp = (n-m)/block ;
            ll small = block - ((n-m)%block) ;
            ll large = block - small ;
            ll ts=0,tl=0 ;
            if(small > 0){
                ts = ((small*(small-1))/2) ;
            }
            if(large > 0){
                tl = ((large*(large-1))/2) ;
            }
            ans += (ts*temp*temp) ;
            if(large > 0 && small > 0)
                ans += (small*large*(temp+1)*temp) ;
            ans += (tl*(temp+1)*(temp+1)) ;
        }
        cout<< ans << endl ;
    }


    return 0;
}


