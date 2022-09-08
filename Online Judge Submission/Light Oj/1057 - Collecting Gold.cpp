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


int n,m,tar,num ;
int dp[20][(1<<16)+5] ;
int adj[20][20] ;

int setBit(int n,int pos){ return (n|(1<<pos)); }
bool checkBit(int n,int pos){ return (bool)(n&(1<<pos)); }

int tsp(int u,int mask){
    if(mask == tar) return adj[u][0] ;
    int &ans = dp[u][mask] ;
    if(ans != -1) return ans ;

    ans = INT_MAX ;
    for(int v=1; v<=num; v++){
        if(!checkBit(mask,v))
            ans = min(ans,adj[u][v]+tsp(v,setBit(mask,v))) ;
    }
    return ans ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0 ;
    cin>> t ;

    while(t--){
        cin>> n >>  m ;
        string temp ;
        pii  g[20] ;
        num = 0 ;
        for(int i=0; i<n; i++){
            cin>> temp ;
            for(int j=0; j<m; j++){
                if(temp[j] == 'x')
                    g[0] = mk(i,j) ;
                else if(temp[j] == 'g')
                    g[++num] = mk(i,j) ;
            }
        }

        for(int i=0; i<=num; i++){
            for(int j=i+1; j<=num; j++){
                adj[i][j] = adj[j][i] = max(abs(g[i].ff-g[j].ff),abs(g[i].ss-g[j].ss)) ;
            }
        }

        memset(dp,-1,sizeof dp) ;
        tar = (1<<(num+1))-1 ;
        int ans = tsp(0,1) ;
        Case ;
        cout<< ans << endl ;
    }


    return 0;
}




