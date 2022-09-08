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
        ll n,val=1;
        cin>> n ;
        ll fact[110] ;
        memset(fact,0,sizeof fact) ;
        for(int i=0; i<n; i++){
            ll temp ;
            cin>> temp ;
            for(int i=2; i*i<=temp; i++){
                while(temp%i == 0){
                    temp /= i ;
                    fact[i]++ ;
                }
            }
            if(temp>1) fact[temp]++ ;
        }
        bool flag = true ;
        for(int i=0; i<110; i++)
        if(fact[i]%2 != 0){
            flag = false ;
            break ;
        }

        if(flag) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;


    }


    return 0;
}


