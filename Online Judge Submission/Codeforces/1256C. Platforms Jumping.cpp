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

    int n,m,d,sum=0 ;
    cin>> n >> m >> d ;

    vector<int> arr(m) ;
    foreach(arr){
        cin>> value ;
        sum += value ;
    }

    int dest = d ,k=-1,i=1,cnt=0;
    vector<int> ans ;
    for(i=1; k<m && i<=n; i++){
        if(sum == (n-i+1)) break ;
        if(i==dest){
            k++ ;
            dest = i+arr[k]-1+d ;
            cnt = arr[k]-1 ;
            ans.pb(k+1) ;
            sum-- ;
        }
        else if(cnt>0){
            ans.pb(k+1) ;
            sum-- ;
            cnt-- ;
        }
        else ans.pb(0) ;
    }

    k++ ;
    while(i<=n && k<m){
        cnt = arr[k] ;
        while(i<=n && cnt){
            ans.pb(k+1) ;
            i++ ;
            cnt-- ;
        }
        k++ ;
    }

    if(i>n && k==m){
        cout<< "YES" << endl ;
        foreach(ans)
            cout<< value << " " ;
        cout<< endl ;
    }
    else cout<< "NO" << endl ;




    return 0;
}


