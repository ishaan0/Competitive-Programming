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
        int n,d ;
        cin>> n >> d ;
        vector<int> arr(n) ;
        foreach(arr)
            cin>> value ;

        int ans = arr[0] ;
        for(int i=1,j=1; d>0 && i<n; i++,j++){
            int temp  = d/j ;
            temp = min(temp,arr[i]) ;
            ans += temp ;
            d -= (temp*j) ;
            //cout<< "de-> " << temp<<" "<<ans<<" "<<d <<endl;
        }

        cout<< ans << endl ;
    }

    return 0;
}

