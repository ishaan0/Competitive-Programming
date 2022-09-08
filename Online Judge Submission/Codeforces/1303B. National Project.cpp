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
    cin>> t;

    while(t--){
        ll n,g,b ;
        cin>> n >>g >> b ;
        ll bad = n/2 ;
        ll good = n-bad ;

        if(good<=g){
            cout<< n << endl ;
            continue ;
        }
        ll ans = 0 ;
        ll tg = (good/g) ;

        if((tg-1)*b >= bad){
            bad = 0 ;
        }
        else{
            bad -= ((tg-1)*b) ;
        }

        ans += (tg*g) + ((tg-1)*b) ;
        ll rem = (good%g) ;

        if(rem > 0){
            bad = max(bad-b,(ll)0) ;
            ans += b ;
        }
        rem += bad ;
        ans += rem ;
        cout<< ans << endl ;

    }

    return 0;
}
