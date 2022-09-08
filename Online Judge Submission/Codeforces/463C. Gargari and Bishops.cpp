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

#define lim 2005
ll lft[2*lim],rgt[2*lim],mx[2] ;
pair<int,int> ans[2] ;

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n ;
    cin>>n ;
    int arr[n+1][n+1] ;
    mx[0] = mx[1] = -1 ;

    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++){
        cin>> arr[i][j] ;
        lft[i-j+n] += arr[i][j] ;
        rgt[i+j] += arr[i][j] ;
    }

    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++){
        int idx = (i+j)%2 ;
        ll val = lft[i-j+n]+rgt[i+j]-arr[i][j] ;
        if(val > mx[idx]){
            ans[idx].ff = i ;
            ans[idx].ss = j ;
            mx[idx] = val ;
        }
    }

    cout<< mx[0]+mx[1] << "\n" ;
    if(ans[0] > ans[1]) swap(ans[0],ans[1]) ;
    cout<< ans[0].ff << " " << ans[0].ss << " " ;
    cout<< ans[1].ff<<" "<< ans[1].ss << "\n";


    return 0;
}
