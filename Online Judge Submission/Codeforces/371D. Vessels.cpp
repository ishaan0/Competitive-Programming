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
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll n ;
    cin>> n ;

    ll arr[n+5],water[n+5], next[n+5] ;
    memset(next, -1, sizeof next) ;
    memset(water, 0, sizeof water) ;
    arr[0]=0 ;
    next[0]=1 ;
    for(int i=1; i<=n; i++){
        cin>> arr[i] ;
        next[i] = i+1 ;
    }


    ll m ;
    cin>> m ;

    for(int i=0; i<m; i++){
        ll num ;
        cin>> num ;
        if(num == 1){
            ll p,x ;
            cin>> p >> x ;
            ll cur = p ;
            while(x!=0 && cur <= n){
                if(x>=arr[cur]){
                    x -= arr[cur] ;
                    water[cur] += arr[cur] ;
                    arr[cur] = 0 ;
                    next[p] = next[cur] ;
                    cur = next[cur] ;
                }
                else{
                    water[cur] += x ;
                    arr[cur] -= x ;
                    x = 0 ;
                }
            }
        }
        else{
            ll k ;
            cin>> k ;
            cout<< water[k] << endl ;
        }
    }



    return 0;
}



