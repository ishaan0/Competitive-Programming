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

    ull fact[22] ;
    fact[0] = fact[1] = 1 ;
    for(ull i=2; i<=20; i++)
        fact[i] = fact[i-1]*i ;

    int t,cs=0;
    cin>> t ;

    while(t--){
        ull n ;
        cin>> n ;
        vector<int> ans  ;
        bool flag = false ;
        for(int i= 20; i>=0; i--){
            if(n == 0){
                flag = true ;
                break ;
            }
            if(fact[i] <= n){
                n -= fact[i] ;
                ans.pb(i) ;
            }
        }
        if(n == 0) flag = true ;
        Case ;
        if(!flag){
            cout<< "impossible" << endl ;
            continue ;
        }
        reverse(all(ans)) ;

        for(int i=0; i<ans.size(); i++){
            cout<< ans[i]<< "!" ;
            if(i+1!=ans.size()) cout<< "+" ;
        }
        cout<< endl ;
    }


    return 0;
}

