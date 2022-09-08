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

    int t,cs = 0 ;
    cin>>t ;

    while(t--){
        int n ;
        cin>> n ;
        vector<int> arr(n) ;
        for(int i=0; i<n; i++){
            cin>> arr[i] ;
            arr[i]++ ;
        }
        sort(all(arr)) ;
        int ans = 0 ;
        for(int i=0; i<n; ){
            int cnt= 0 ;
            int val = arr[i] ;
            while(i<n && val == arr[i]){
                cnt++ ;
                i++ ;
            }
            if(cnt > val){
                int temp = (cnt+val-1)/val ;
                ans += (temp*val) ;
            }
            else ans += val ;
        }
        Case ;
        cout<< ans << endl ;
    }

    return 0;
}



