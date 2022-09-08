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
    scanf("%d",&t) ;

    while(t--){
        ll n ;
        scanf("%lld",&n) ;

        ll arr[n] ;
        vector<ll> cons ;
        ll four[n+5],best[n+5],odd=0 ;
        ll temp=INT_MAX,val=INT_MAX,val4=INT_MAX ;
        bool flag = false ;

        for(int i=0; i<n; i++){
            scanf("%lld",&arr[i]) ;
            arr[i] = abs(arr[i]) ;
            if(arr[i]%2!=0){
                if(flag) odd++ ;
                else odd = 1 ;
                flag = true ;
            }
            else{
                if(flag)
                    cons.pb(odd),odd=0 ;
                flag = false ;
            }
        }
        if(flag) cons.pb(odd) ;

        ll ans = 0 ;
        for(int i=0; i<cons.size(); i++)
            ans += (cons[i]*(cons[i]+1))/2 ;

        for(int i=n-1; i>=0; i--){
            if(arr[i]%2==0){
                val = temp ;
                best[i] = val ;
                temp = i ;
                if(arr[i]%4==0)
                    val4 = i ;
                four[i] = val4 ;
            }
            else{
                best[i] = val ;
                four[i] = val4 ;
            }
        }

        for(int i=0; i<n; i++){
            ll pos = min(best[i],four[i]) ;
            if(pos != INT_MAX)
                ans += (n-pos) ;

        }

        printf("%lld\n",ans) ;
    }

    return 0;
}




