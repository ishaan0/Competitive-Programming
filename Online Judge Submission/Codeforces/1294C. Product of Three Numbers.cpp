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

vector<ll> factor ;
void fact(ll n){
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            factor.pb(i) ;
            factor.pb(n/i) ;

        }
    }
    if(n>1) factor.pb(n) ;
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
        factor.clear() ;
        ll n ;
        cin>> n ;
        fact(n) ;
        sort(all(factor)) ;

        bool flag = false ;
        vector<ll> ans ;
        ll lim = factor.size() ;
        lim = lim-1 ;


        for(int i=0; i<lim; i++){

            ll temp = factor[i]*factor[i+1] ;
            if(temp == n){
                for(int j=i-1; j>=1; j--){
                    for(int k=j-1; k>=0; k--){
                        if(factor[j]*factor[k] == factor[i]){
                            flag = true ;
                            ans.pb(factor[k]) ;
                            ans.pb(factor[j]) ;
                            ans.pb(factor[i+1]) ;
                            break ;
                        }
                        else if(factor[j]*factor[k] == factor[i+1]){
                            flag = true ;
                            ans.pb(factor[k]) ;
                            ans.pb(factor[j]) ;
                            ans.pb(factor[i]) ;
                            break ;
                        }
                    }
                    if(flag) break ;
                }
            }

            if(flag) break ;
        }

        if(flag){
            cout<< "YES" << endl ;
            foreach(ans)
                cout<< value << " " ;
            cout<< endl ;
        }
        else cout<< "NO" << endl ;
    }

    return 0;
}
