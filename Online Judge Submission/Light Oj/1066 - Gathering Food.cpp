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

int n,cnt ;
char grid[15][15] ;
int vis[15][15] ;
int dr[4] = {0,0,1,-1} ;
int dc[4] = {-1,1,0,0} ;
pii src2 ;

int bfs(pii src, char dest){
    queue<pii> q ;
    q.push(src) ;
    vis[src.ff][src.ss] = 0 ;

    while(!q.empty()){
        pii uu = q.front() ;
        q.pop() ;

        int ur = uu.ff ;
        int uc = uu.ss ;
        int vr,vc ;
        for(int i=0; i<4; i++){
            vr = ur + dr[i] ;
            vc = uc + dc[i] ;

            if(vr<0||vr>=n||vc<0||vc>=n)
                continue ;
            if(grid[vr][vc] == '#')
                continue ;
            if(vis[vr][vc]==-1 && isalpha(grid[vr][vc]) && grid[vr][vc] > dest)
                continue ;
            if(vis[vr][vc] == -1){
                vis[vr][vc] = vis[ur][uc]+1 ;
                q.push(mk(vr,vc)) ;
                if(grid[vr][vc] == dest){
                    src2 = mk(vr,vc) ;
                    return vis[vr][vc] ;
                }
            }
        }
    }

    return -1 ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0;
    cin>>t ;

    while(t--){
        cnt=0;
        cin>> n;
        for(int i=0; i<n; i++)
            cin>> grid[i] ;
        pii src ;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]>='A' && grid[i][j]<='Z')
                    cnt++ ;
                if(grid[i][j] == 'A')
                    src = mk(i,j) ;
            }
        }
        Case ;
        char ch = 'B' ;
        bool flag = true ;
        int sum = 0 ;
        for(int i=0; i<cnt-1; i++){
            memset(vis, -1, sizeof(vis)) ;
            int temp = bfs(src,ch) ;
            if(temp == -1){
                flag = false ;
                break ;
            }
            sum += temp ;
            src = src2 ;
            ch++ ;
        }

        if(flag) cout<< sum << endl ;
        else cout<< "Impossible" << endl ;

    }


    return 0;
}


