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

    int t ;
    cin>> t ;

    while(t--){
        ll n ;
        cin>> n ;
        vector<ll> arr(n) ;
        foreach(arr) cin>> value ;

        ll prv=arr[0],sum = 0;
        for(int i=0; i<n; i++){
            if(arr[i] < 0){
                if(prv > 0){
                    sum += prv ;
                    prv = arr[i] ;
                }
                prv = max(prv,arr[i]) ;
            }
            else{
                if(prv < 0){
                    sum += prv ;
                    prv = arr[i] ;
                }
                prv = max(prv,arr[i]) ;
            }
        }
        sum += prv ;
        cout<< sum << endl ;
    }


    return 0;
}



