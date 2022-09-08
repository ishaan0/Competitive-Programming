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


bool func(int n,int k){
    vector<int> p ;
    while(n%2==0){
        p.pb(2) ;
        n /= 2 ;
    }

    for(int i=3; i*i<=n; i++){
        while(n%i==0){
            p.pb(i) ;
            n /= i ;
        }
    }

    if(n>2) p.pb(n) ;
    if(p.size() < k) return false ;
    return true ;
}

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
        int x,k ;
        cin>> x >> k ;

        if(func(x,k))
            cout<< "1" << endl ;
        else cout<< "0" << endl ;
    }

    return 0;
}


