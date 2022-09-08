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

bool mark[1010] ;
vector<int> primes ;

void seive(){
    int i,j,n=1005,lim=sqrt(lim)+2 ;
    mark[0] = mark[1] = true ;
    for(int i=4; i<=n; i+=2)
        mark[i] = true ;
    primes.pb(2) ;
    for(int i=3; i<=n; i+=2){
        if(!mark[i]){
            primes.pb(i) ;
            if(i<=lim)
            for(int j=i*i; j<=n; j+=i*2)
            mark[j] = true ;
        }
    }
}


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
    seive() ;

    while(t--){
        int n ;
        cin>> n ;
        vector<int> arr(n) ;
        foreach(arr)
            cin>> value ;
        int col=0,used[n] ;
        memset(used,-1,sizeof used) ;
        for(int i=0; i<primes.size(); i++){
            bool flag = true ;
            for(int j=0; j<n; j++){
                if(used[j]==-1 && arr[j]%primes[i] == 0){
                    if(flag) col++,flag=false ;
                    used[j] = col ;
                }
            }
        }

        cout<< col << endl ;
        for(int i=0; i<n; i++)
            cout<< used[i] << " " ;
        cout<< endl ;
    }

    return 0;
}

