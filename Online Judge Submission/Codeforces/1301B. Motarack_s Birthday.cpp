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
        int n;
        cin>> n ;
        vector<int> arr(n) ;

        int m=0,mn=INT_MAX,mx=INT_MIN ;
        for(int i=0; i<n; i++){
            cin>> arr[i] ;
            if(i!=0 && arr[i]!=-1 && arr[i-1]!=-1)
                m = max(m,abs(arr[i]-arr[i-1])) ;
        }

        for(int i=0; i<n-1; i++){
            if(arr[i]!=-1 && arr[i+1]==-1){
                mn = min(mn,arr[i]) ;
                mx = max(mx,arr[i]) ;
            }
        }

        for(int i=1; i<n; i++){
            if(arr[i]!=-1 && arr[i-1]==-1){
                mn = min(mn,arr[i]) ;
                mx = max(mx,arr[i]) ;
            }
        }

        if(mn == INT_MAX){
            cout<< "0 0" << endl ;
            continue ;
        }

        int k = abs(mx-mn) ;
        k = (k+1)/2 ;

        m = max(m,k) ;
        k += mn ;

        cout<< m << " " << k << endl ;

    }

    return 0;
}
