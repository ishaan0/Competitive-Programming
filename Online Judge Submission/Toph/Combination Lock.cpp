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
const ll mod = 1e9+7 ;




//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0 ;
    cin>> t ;

    while(t--){
        ll n,ans=1 ;
        cin>> n ;
        for(int i=0; i<n; i++){
            ll d,k,temp=1;
            cin>> d >> k ;
            for(int i=0; i<d; i++)
                temp *= 10 ;
            temp += 2*k ;
            temp /= (2*k+1) ;
            ans = (ans%mod) * (temp%mod) ;
        }
        ans %= mod ;
        cout<< "Case "<< ++cs << ": " << ans << endl ;
    }


    return 0;
}


