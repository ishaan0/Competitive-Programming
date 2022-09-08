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

    int t ;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;
        int arr[n+1],pre[n+1][30] ;
        memset(pre,0,sizeof pre) ;
        for(int i=1; i<=n; i++){
            cin>> arr[i] ;
            pre[i][arr[i]] = 1 ;
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=26; j++)
                pre[i][j] += pre[i-1][j] ;

        int ans = 0 ;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                int a = 0,b = 0 ;
                for(int k=1; k<=26; k++){
                    a = max(a,2*min(pre[i-1][k],pre[n][k]-pre[j][k])) ;
                    b = max(b,pre[j][k]-pre[i-1][k]) ;
                }

                ans = max(ans,a+b) ;
            }
        }

        cout<< ans << endl ;
    }

    return 0;
}



