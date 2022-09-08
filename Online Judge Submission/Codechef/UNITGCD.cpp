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
        int n ;
        scanf("%d",&n) ;
        int cnt = n/2,num=1;
        if(n==1){
            printf("1\n1 1\n") ;
            continue ;
        }

        printf("%d\n",cnt) ;
        if(n<=3){
            printf("%d",n) ;
            while(num<=n){
                printf(" %d",num) ;
                num++ ;
            }
            printf("\n") ;
            cnt-- ;
        }
        else {
            printf("3 1 2 3\n") ;
            cnt-- ;
            num = 4 ;
        }

        while(cnt>0){
            if(num+1 <=n)
                printf("2 %d %d\n",num,num+1) ;
            else if(num <= n)
                printf("1 %d\n",num) ;
            else break ;
            num += 2 ;
            cnt-- ;
        }
    }

    return 0;
}



