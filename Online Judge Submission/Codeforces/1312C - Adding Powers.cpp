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

    int t ;
    cin>> t ;

    while(t--){
        ll n,k ;
        cin>> n >>  k ;
        vector<ll> arr(n) ;
        foreach(arr)
            cin>> value ;

        bool flag= false ;
        unordered_map<ll,bool> m;
        foreach(arr){
            int cnt = 0 ;
            while(value > 0){
                if(value % k == 0){
                    value /= k ;
                    cnt++ ;
                }
                else{
                    value-- ;
                    if(!m.count(cnt))
                        m[cnt] = true ;
                    else{ flag = true ;break ;}
                }
            }
            if(flag) break ;
        }

        if(flag) cout<< "NO" << endl;
        else cout<< "YES" << endl ;

    }

    return 0;
}

