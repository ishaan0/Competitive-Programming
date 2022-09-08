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

bool isPrime(int n){
    if(n<2) return false ;
    if(n == 2) return true ;
    for(int i=2; i*i<=n; i++)
        if(n%i == 0) return false ;
    return true ;
}

vector<int> arr ;
int dp[10000][5] ;

int func(int amt,int k){
    if(amt <= 0) return (amt==0) ;
    int &ans = dp[amt][k] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    for(int i=1; i<=k; i++)
        ans += func(amt-i,i) ;
    return ans ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif


    for(int i=0; i<=90; i++){
        for(int j=0; j<=90; j++){
            if(i<=j){
                int num = (i*i)+(j*j) ;
                if(isPrime(num)) arr.pb(num) ;
            }
        }
    }
    sort(all(arr)) ;
    int t ;
    cin>>t ;
    memset(dp,-1,sizeof dp) ;

    while(t--){
        int n,k ;
        cin>> n >> k ;
        int amt = arr[n-1] ;
        int ans = func(amt,k) ;
        cout<< ans << endl ;
    }

    return 0;
}




