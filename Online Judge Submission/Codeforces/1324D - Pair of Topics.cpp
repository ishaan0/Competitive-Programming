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

    ll n,cnt=0 ;
    cin>> n ;
    vector<ll> a(n),b(n),rem ;
    for(int i=0; i<n; i++)
        cin>> a[i] ;
    for(int i=0; i<n; i++){
        cin>> b[i] ;
        if(a[i] > b[i])
            cnt++ ;
        else rem.pb(b[i]-a[i]) ;
    }

    ll ans= (cnt*(cnt-1))/2 ;
    sort(all(rem)) ;
    for(int i=0; i<n; i++){
        if(a[i] > b[i]){
            int pos = lower_bound(all(rem),a[i]-b[i])-rem.begin() ;
            ans += pos ;
        }
    }

    cout<< ans << endl ;

    return 0;
}

