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

    int t ,cs= 0 ;
    cin>> t ;

    while(t--){
        ll n,x,y,d ;
        cin>> n ;
        double m = ceil(sqrt(n*1.0)) ;
        d = m*m - n ;
        if(d < m){
            x = d+1 ;
            y = m ;
        }
        else{
            x = m ;
            y =  n-(m-1)*(m-1) ;
        }
        if((ll)m%2 == 0)
            swap(x,y) ;

        cout<<"Case " << ++cs <<": "<< x <<" "<< y << endl ;
    }


    return 0;
}



