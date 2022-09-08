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

    int q ;
    cin>> q ;

    while(q--){
        ll n,m ;
        cin>> n >>m ;
        vector<ll> t(n),l(n),h(n) ;
        for(int i=0; i<n; i++)
            cin>> t[i] >> l[i] >> h[i] ;

        bool flag = true ;
        ll lo=m,hi=m,pt=0 ;
        for(int i=0; i<n; i++){
            ll diff = t[i] - pt ;
            ll tl = lo - diff ;
            ll th = hi + diff ;

            if((tl>=l[i] && tl<=h[i]) || (th>=l[i] && th<=h[i])){
                lo = max(tl,l[i]) ;
                hi = min(th,h[i]) ;
            }
            else if((l[i]>=tl && l[i]<=th) || (h[i]>=tl && h[i]<=th)){
                lo = max(tl,l[i]) ;
                hi = min(th,h[i]) ;
            }
            else{
                flag = false ;
                break ;
            }
            pt = t[i] ;
        }


        if(flag) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;

    }

    return 0;
}

