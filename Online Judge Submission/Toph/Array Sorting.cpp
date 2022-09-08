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

    int t,cs=0;
    cin>> t ;

    while(t--){

        ll n,k,x ;
        cin>> n >> k >> x ;
        vector<int> arr(n) ;
        foreach(arr) cin>> value ;

        ll prv = 0 ;
        bool flag = true ;
        for(int i=0; i<n; i++){
            if(arr[i] < prv){
                ll diff = prv - arr[i] ;
                ll cnt = diff/x ;
                if(cnt > k){
                    flag = false ;
                    break ;
                }
                k -= cnt ;
                arr[i] += (cnt*x) ;
                if(diff%x!=0 && k<=0){
                    flag = false ;
                    break ;
                }
                k-- ;
                arr[i] += x ;
            }
            prv = arr[i] ;
        }
        cout<< "Case "<< ++cs << ": " ;
        if(flag) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
    }

    return 0;
}



