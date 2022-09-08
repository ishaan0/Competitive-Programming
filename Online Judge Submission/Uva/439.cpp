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

int dr[8] = {-1, -1, -2, -2,  1, 1,  2, 2} ;
int dc[8] = {-2,  2, -1,  1, -2, 2, -1, 1} ;
int vis[10][10] ;

int BFS(pii src, pii dest){
    queue<pii > q ;
    memset(vis, -1, sizeof(vis)) ;
    q.push(src) ;
    vis[src.ff][src.ss] = 0 ;
    if(src.ff==dest.ff && src.ss==dest.ss)
        return 0 ;

    while(!q.empty()){
        pii u = q.front() ;
        q.pop() ;
        int ur = u.ff ;
        int uc = u.ss ;
        int vr,vc ;

        for(int i=0; i<8; i++){
            vr = ur + dr[i] ;
            vc = uc + dc[i] ;
            if(vr<1 || vr>8 || vc<1 || vc>8 )
                continue ;
            if(vis[vr][vc] == -1){
                vis[vr][vc] = vis[ur][uc] + 1 ;
                q.push(mk(vr,vc)) ;
                if(vr==dest.ff && vc==dest.ss)
                    return vis[vr][vc] ;
            }
        }
    }

    return vis[dest.ff][dest.ss] ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    string a,b ;
    while(cin>> a >> b){
        pii src,dest ;
        src.ff = a[1] - '0' ;
        src.ss = a[0] - 'a' + 1;
        dest.ff = b[1] - '0' ;
        dest.ss = b[0] - 'a' + 1;
        int ans = BFS(src,dest) ;
        cout<< "To get from "<<a<<" to "<<b<<" takes "<<ans<<" knight moves."<<endl;
    }


    return 0;
}

