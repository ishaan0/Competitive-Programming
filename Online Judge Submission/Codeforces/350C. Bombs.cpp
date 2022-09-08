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

bool cmp(pii a,pii b){
    int dis1 = abs(a.ff) + abs(a.ss) ;
    int dis2 = abs(b.ff) + abs(b.ss) ;
    return dis1 < dis2 ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,ans=0 ;
    scanf("%d",&n) ;

    vector<pii > arr(n) ;
    foreach(arr){
        scanf("%d%d",&value.ff,&value.ss) ;
        ans += 2 ;
        if(value.ff != 0) ans += 2 ;
        if(value.ss != 0) ans += 2 ;
    }

    sort(all(arr),cmp) ;

    printf("%d\n",ans) ;
    for(int i=0; i<n; i++){
        if(arr[i].ff > 0)
            printf("1 %d R\n",abs(arr[i].ff)) ;
        if(arr[i].ff < 0)
            printf("1 %d L\n",abs(arr[i].ff)) ;
        if(arr[i].ss > 0)
            printf("1 %d U\n",abs(arr[i].ss)) ;
        if(arr[i].ss < 0)
            printf("1 %d D\n",abs(arr[i].ss)) ;

        printf("2\n") ;
        if(arr[i].ff > 0)
            printf("1 %d L\n",abs(arr[i].ff)) ;
        if(arr[i].ff < 0)
            printf("1 %d R\n",abs(arr[i].ff)) ;
        if(arr[i].ss > 0)
            printf("1 %d D\n",abs(arr[i].ss)) ;
        if(arr[i].ss < 0)
            printf("1 %d U\n",abs(arr[i].ss)) ;
        printf("3\n") ;
    }

    return 0;
}


