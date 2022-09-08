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

    int t;
    cin>> t;

    while(t--){
        int n ;
        cin>> n ;
        vector<int> arr[n+1] ;
        vector<bool> girl(n+1),boy(n+1) ;
        for(int i=1; i<=n; i++){
            int k ;
            cin>> k ;
            for(int j=0; j<k; j++){
                int temp ;
                cin>> temp ;
                arr[i].pb(temp) ;
            }
        }

        int cnt = 0 ;
        for(int i=1; i<=n; i++){
            foreach(arr[i]){
                if(!boy[value]){
                    boy[value] = girl[i] = true ;
                    cnt++ ;
                    break ;
                }
            }
        }

        if(cnt == n)
            cout<< "OPTIMAL" << endl ;
        else{
            cout<< "IMPROVE" << endl ;
            for(int i=1; i<=n; i++)
                if(!girl[i]){
                    cout<< i << " " ;
                    break ;
                }
            for(int i=1; i<=n; i++)
            if(!boy[i]){
                cout<< i << endl ;
                break ;
            }
        }

    }

    return 0;
}

