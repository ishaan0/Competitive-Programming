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

    int t ;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;
        vector<ll> a(n),b(n),one(n),neg(n) ;
        for(int i=0; i<n; i++){
            cin>> a[i] ;
            if(i){
                one[i]=one[i-1];
                neg[i]=neg[i-1] ;
                if(a[i-1] == 1) one[i]++ ;
                else if(a[i-1] == -1) neg[i]++ ;
            }
        }
        for(int i=0; i<n; i++)
            cin>> b[i] ;

        bool flag = true ;
        for(int i=0; i<n; i++){
            if(a[i] > b[i] && neg[i] == 0){
                flag = false ;
                break ;
            }
            else if(a[i] < b[i] && one[i] == 0){
                flag = false ;
                break ;
            }
        }

        if(flag) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
    }

    return 0;
}




