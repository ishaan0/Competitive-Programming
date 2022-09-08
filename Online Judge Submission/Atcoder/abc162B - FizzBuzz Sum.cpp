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
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll n,sum=0;
    cin>> n ;

    sum = n*(n+1)/2 ;
    ll temp = (n/3) ;
    temp = (temp*(temp+1))/2 ;
    temp *= 3 ;
    sum -= temp ;
    temp = n/5 ;
    temp = (temp*(temp+1))/2 ;
    temp *= 5 ;
    sum -= temp ;
    temp = n/((ll)5*3) ;
    temp = (temp*(temp+1))/2 ;
    temp *= ((ll)5*3) ;
    sum += temp ;

    cout << sum << endl ;

    return 0;
}


