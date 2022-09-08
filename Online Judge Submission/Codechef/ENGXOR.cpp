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
    scanf("%d",&t) ;
    while(t--){
        int n,m ;
        scanf("%d%d",&n,&m) ;
        int odd=0,even=0 ;
        for(int i=0; i<n; i++){
            int temp ;
            scanf("%d",&temp) ;
            int cnt = 0 ;
            while(temp!=0){
                cnt += (temp%2) ;
                temp /= 2 ;
            }
            if(cnt&1) odd++ ;
            else even++ ;
        }

        while(m--){
            int q ;
            scanf("%d",&q) ;
            int cnt = 0 ;
            while(q!=0){
                cnt += (q%2) ;
                q /= 2 ;
            }
            if(cnt&1)
                printf("%d %d\n",odd,even) ;
            else printf("%d %d\n",even,odd) ;
        }
    }

    return 0;
}


