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

    int n ;
    while(cin>> n ){
        if(n==0) break ;
        set<pii> s ;
        vector<pii > arr(n) ;
        for(int i=0; i<n; i++)
            cin>> arr[i].ff >> arr[i].ss ;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dx = arr[j].ff-arr[i].ff ;
                int dy = arr[j].ss-arr[i].ss ;
                int gcd = __gcd(dx,dy) ;
                dx /= gcd ;
                dy /= gcd ;
                if(dx<0) dx=-dx, dy=-dy ;
                s.insert(mk(dx,dy)) ;
            }
        }
        cout<< s.size() << endl ;
    }
    return 0;
}


