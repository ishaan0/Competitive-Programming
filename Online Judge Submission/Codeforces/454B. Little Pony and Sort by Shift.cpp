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

    int n,cnt = 0,idx=-1;
    cin>> n ;
    vector<int> arr(n),ans ;
    for(int i=0; i<n; i++){
        cin>> arr[i] ;
        if(i && arr[i-1] > arr[i]){
            cnt++ ;
            idx = i ;
        }
    }

    if(cnt == 0) cout<< "0" << endl ;
    else if(cnt == 1 && arr[n-1] <= arr[0])
        cout<< n-idx << endl ;
    else cout<< "-1" << endl ;

    return 0;
}


