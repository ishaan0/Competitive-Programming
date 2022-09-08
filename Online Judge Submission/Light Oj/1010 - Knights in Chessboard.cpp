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

    int t,cs=0 ;
    cin>> t ;

    while(t--){
        ll m,n ;
        cin>> m >> n ;
        ll ans ;
        if(m == 1) ans = n ;
        else if(n==1) ans = m ;
        else if(m==2){
            ans = (n/4)*4 ;
            if(n%4==1) ans += 2 ;
            else if(n%4 > 1) ans += 4 ;
        }
        else if(n==2){
            ans = (m/4)*4 ;
            if(m%4==1) ans += 2 ;
            else if(m%4 > 1) ans += 4 ;
        }
        else ans = ((n*m)+1)/2 ;
        Case ;
        cout<< ans << endl ;
    }


    return 0;
}

