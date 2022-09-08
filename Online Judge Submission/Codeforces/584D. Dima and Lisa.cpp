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

bool isPrime(int n){
    if(n%2==0) return false ;
    for(int i=3; i*i<=n; i+=2)
        if(n%i==0) return false ;
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

    int n ;
    cin>> n ;

    if(isPrime(n)){
        cout<< "1" << endl << n << endl ;
        return 0 ;
    }

    cout<< "3" << endl << "3 " ;
    n -= 3 ;
    for(int i=3; i<=n; i+=2)
    if(isPrime(i) && isPrime(n-i)){
        cout<< i << " " << n-i << endl ;
        return 0 ;
    }

    return 0;
}



