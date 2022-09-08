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

ll countZero(ll n){
    ll ans = 0 , div = 5;
    while(div <= n){
        ans += n/div ;
        div *= 5 ;
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

    int t,cs=0;
    cin>> t ;

    while(t--){
        ll q ;
        cin>> q ;

        bool flag = false ;
        ll lo = 0 , hi = INT_MAX ;
        while(lo < hi){
            ll mid = (lo+hi)/2 ;
            ll cntZ = countZero(mid) ;

            if(cntZ >= q)
                hi = mid , flag |= (cntZ==q) ;
            else lo = mid + 1 ;

        }
        Case ;
        if(flag) cout<< lo << endl ;
        else cout<< "impossible" << endl ;

    }



    return 0;
}



