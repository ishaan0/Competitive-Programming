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


void print(ll day,ll nw,ll tt){
    cout<< "Day = "<< day <<", New = "<< nw <<", Total = " << tt << endl;
}

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
        ll n,prv= 1,cur=1;
        cin>> n ;
        cout<< "Case " << ++cs << ":" << endl ;
        print(1,0,1) ;
        for(ll i=2; i<=n; i++){
            cur *= 3 ;
            print(i,cur-prv,cur) ;
            prv = cur ;
        }
    }

    return 0;
}


