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



vector<pair<ll,ll> > adj[205] ;
struct Node{
    ll u,cost ;
};

bool operator<(Node a, Node b){
    return a.cost < b.cost ;
}

priority_queue<Node> pq ;
ll cost[205] ;
bool taken[205] ;

void clearPq(){
    while(!pq.empty())
        pq.pop() ;
}

ll prims(ll src,ll dest){
    for(int i=0; i<205; i++){
        cost[i] = INT_MIN ;
        taken[i] = false ;
    }
    clearPq() ;
    cost[src] = 0 ;
    Node temp ;
    temp.u = src ;
    temp.cost = 0 ;
    pq.push(temp) ;

    ll ans = 9999999999 ;
    while(!pq.empty()){
        Node cur = pq.top() ;
        pq.pop() ;
        //cout<< "ans-> " << ans << endl ;
        if(cur.u == dest)
            return min(cur.cost,ans) ;
        if(taken[cur.u])
            continue ;
        if(cur.cost != 0)
            ans = min(ans,cur.cost) ;
        taken[cur.u] = true ;

        for(pii v: adj[cur.u]){
            if(taken[v.ff])
                continue ;
            if(v.ss > cost[v.ff]){
                temp.u = v.ff ;
                temp.cost = v.ss ;
                pq.push(temp) ;
                cost[v.ff] = v.ss ;
            }
        }
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

    ll n,r,cs=0;
    while(cin>>n>>r){
        if(n==0 && r== 0)
            break ;
        for(int i=0; i<205; i++)
            adj[i].clear() ;
        unordered_map<string, ll> m ;
        ll number = 0 ;
        for(int i=0; i<r; i++){
            string a,b ;
            ll w ;
            cin>> a>>b >> w ;

            if(!m.count(a)) m[a] = number++ ;
            if(!m.count(b)) m[b] = number++ ;
            adj[m[a]].pb(mk(m[b],w)) ;
            adj[m[b]].pb(mk(m[a],w)) ;
        }

        string src,dest ;
        cin>> src>> dest ;
        if(!m.count(src)) m[src] = number++ ;
        if(!m.count(dest)) m[dest] = number++ ;
        ll ans = prims(m[src],m[dest]) ;
        cout<< "Scenario #"<< ++cs<<endl;
        cout<< ans << " tons" << endl<<endl;
    }

    return 0;
}


