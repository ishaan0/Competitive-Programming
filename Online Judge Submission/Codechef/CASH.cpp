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
    cin>>t ;

    while(t--){
        ll n,k ;
        cin>> n >> k ;
        vector<ll> arr(n) ;
        ll ans = 0 ;
        foreach(arr){
            cin>> value ;
            ans += (value%k) ;
        }

        for(int i=n-1; i>=0; i--){
            if(arr[i]%k!=0){
                ll temp = arr[i]%k ;
                temp = arr[i]-temp ;
                temp = (((temp/k)*k)+k)-temp ;
                if(temp <= ans){
                    arr[i] += temp ;
                    ans -= temp ;
                }
            }
        }

        ans = ans%k ;

        cout<< ans << endl ;

    }


    return 0;
}


