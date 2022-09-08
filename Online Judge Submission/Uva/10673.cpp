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

int egcdd(int a,int b,int &x,int &y){
    if(a == 0){
        x = 0 ;
        y = 1 ;
        return b ;
    }
    int x1,y1 ;
    int gcdd = egcdd(b%a,a,x1,y1) ;
    x = y1 - (b/a)*x1 ;
    y = x1 ;
    return gcdd ;
}


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll t ;
    cin>>t ;

    while(t--){
        int x,k ;
        cin>> x >> k ;
        int a = x/k ;
        int b = (x+k-1)/k ;
        int xx=0,yy=0 ;
        int gcdd = egcdd(a,b,xx,yy) ;
        x = x/gcdd ;
        xx = x*xx ;
        yy = x*yy ;
        cout<< xx <<" "<< yy << endl ;
    }

    return 0;
}


