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

    int n,m,k,mxr=-1,mxc=-1;
    cin>> n >> m >> k ;
    for(int i=0; i<k; i++){
        int r,c ;
        cin>>r >> c ;
        mxr = max(mxr,r) ;
        mxc = max(mxc,c) ;
    }

    string ans = "" ;
    while(mxr > 1){
        ans += "U" ;
        mxr-- ;
    }
    while(mxc > 1){
        ans += "L" ;
        mxc-- ;
    }
    int r,c ;
    for(int i=0; i<k; i++)
        cin>> r >> c ;

    for(int i=1; i<=n; i++){
        if(i!=1) ans += "D" ;
        for(int j=1; j<m; j++){
            if(i&1) ans += "R" ;
            else ans += "L" ;
        }
    }

    cout<< ans.size() << endl ;
    cout<< ans << endl ;

    return 0;
}

