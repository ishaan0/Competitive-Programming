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
    cin>> t ;
    while(t--){
        int a,b,x,y ;
        cin>>a>>b>>x>>y ;

        x++,y++ ;
        int ans = 0 ;

        int tx = x-1 ;
        int ty = b ;
        ans = max(ans, tx*ty) ;

        tx = a ;
        ty = y-1 ;
        ans = max(ans, tx*ty) ;

        tx = a-x ;
        ty = b ;
        ans = max(ans, tx*ty) ;

        tx = a ;
        ty = b-y ;
        ans = max(ans, tx*ty) ;

        cout<< ans << endl ;
    }

    return 0;
}

