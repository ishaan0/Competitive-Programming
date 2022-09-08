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
        int n;
        cin>> n ;
        vector<int> arr(n) ;
        unordered_set<int> s ;
        for(int i=0; i<n; i++){
            cin>> arr[i] ;
            s.insert(arr[i]) ;
        }

        vector<int> ans ;
        bool flag = false ;
        for(int i=0; i<n; i++){
            int num = arr[i],cnt=0 ;
            flag = true ;
            for(int j=num-1; j>=1; j--){
                if(s.count(j))
                   cnt++ ;
            }

            int need = num/2 ;
            //cout<< "f-> " << cnt <<" "<< need << endl ;
            if(cnt < need){
                flag = false ;
                break ;
            }
            flag = false ;
            for(int j=num+1; j<=2*n; j++){
                if(!s.count(j)){
                    ans.pb(num) ;
                    ans.pb(j) ;
                    s.insert(j) ;
                    flag = true ;
                    break ;
                }
            }
            //cout<< "s-> " << flag << endl ;
            if(!flag) break ;

        }

        if(!flag) cout<< "-1" << endl ;
        else{

            foreach(ans)
                cout<< value << " " ;
                cout<< endl ;
        }
    }

    return 0;
}

