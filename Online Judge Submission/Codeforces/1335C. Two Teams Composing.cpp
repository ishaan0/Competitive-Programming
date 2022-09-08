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

    int t ;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;
        unordered_set<int> s ;
        map<int,int> m ;
        for(int i=0; i<n; i++){
            int x ;
            cin>>x ;
            s.insert(x) ;
            m[x]++ ;
        }

        int dis = s.size() ;
        int mx = 0 ;
        foreach(m)
            mx = max(mx,value.ss) ;
        int ans = min(dis,mx) ;
        if(ans == mx && ans==dis) ans-- ;
        ans = min(ans,n/2) ;
        cout<< ans << endl ;
    }


    return 0;
}


