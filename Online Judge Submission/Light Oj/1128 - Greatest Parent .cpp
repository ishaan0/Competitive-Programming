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

#define lim 100005

int n,q ;
int par[lim][20], temp[lim] ;
ll dis[lim] ;

void build(){
    for(int i=0; i<n; i++)
        par[i][0] = temp[i] ;

    for(int j=1; (1<<j)<n; j++)
        for(int i=0; i<n; i++)
            if(par[i][j-1] != -1)
                par[i][j] = par[ par[i][j-1] ][j-1] ;
}

int query(int k,ll val){
    int lg = log2(n) ;
    for(int i=lg; i>=0; i--){
        if(dis[ par[k][i] ] >= val)
            k = par[k][i] ;
    }
    return k ;
}

void reset(){
    memset(par,-1,sizeof par) ;
    memset(temp,-1,sizeof temp) ;
    memset(dis,-1,sizeof dis) ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0 ;
    scanf("%d",&t) ;

    while(t--){
        reset() ;
        scanf("%d%d",&n,&q) ;

        for(int i=1; i<n; i++)
           scanf("%d%lld",&temp[i],&dis[i]) ;
        temp[0] = 0 ;
        dis[0] = 1 ;
        build() ;
        printf("Case %d:\n",++cs) ;
        while(q--){
            ll k,val ;
            scanf("%lld%lld",&k,&val) ;
            int ans = query(k,val) ;
            printf("%d\n",ans) ;
        }
    }


    return 0;
}



