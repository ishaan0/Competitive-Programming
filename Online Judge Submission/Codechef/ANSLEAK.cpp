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
    scanf("%d",&t) ;

    while(t--){
        int n,m,k ;
        scanf("%d%d%d",&n,&m,&k) ;
        vector<int> ans ;
        for(int i=0; i<n; i++){
            unordered_map<int,int> m ;
            for(int j=0; j<k; j++){
                int temp ;
                scanf("%d",&temp) ;
                m[temp]++ ;
            }
            int mx = INT_MIN,val=0 ;
            foreach(m){
                if(value.ss >= mx){
                    mx = value.ss ;
                    val = value.ff ;
                }
            }
            ans.pb(val) ;
        }

        for(int i=0; i<ans.size(); i++){
            if(i) printf(" ") ;
            printf("%d",ans[i]) ;
        }
        printf("\n") ;
    }

    return 0;
}




