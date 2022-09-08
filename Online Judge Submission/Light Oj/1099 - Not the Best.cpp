#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs <<": "
#define     inf                 LLONG_MIN
#define     INF                 LLONG_MAX
#define     mp                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

/** Debugging Tool **/
TS void show(const T& v) {    cerr << v << ' ' ;}
TM void show(const T1& first,const T2&... rest){show(first);show(rest...);}
TP ostream& operator<<(ostream& os,const pair<F,S>& p){return os<<"("<<p.ff<<", "<<p.ss<<")";}
TS ostream& operator<<(ostream& os,const vector<T>& v){os << "{"; typename vector< T >::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if( it != v.begin() )os<<", ";os<<*it;}return os<<"}";}
TS ostream& operator<<(ostream& os,const set<T>& v){os<<"[";typename set<T>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
TP ostream& operator<<(ostream& os,const map<F,S>& v){os<<"[";typename map<F,S>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<it->ff<<" = "<<it->ss;}return os<<"]";}
/** Ends **/

vector<pii > adj[5005] ;
int dis1[5005], dis2[5005] ;

struct cmp{
    bool operator () (pii const &a, pii const &b) const{
        return a.ss > b.ss ;
    }
};

void dijkstra(){
    priority_queue<pii,vector<pii>,cmp> pq ;
    pq.push(mp(1,0)) ;
    dis1[1] = 0 ;

    while(!pq.empty()){
        pii node = pq.top() ;
        pq.pop() ;
        int u = node.ff ;

        for(pii el: adj[u]){
            int v = el.ff ;
            int w = el.ss ;
            if(node.ss+w < dis1[v]){
                dis2[v] = dis1[v] ;
                dis1[v] = node.ss + w ;
                pq.push(mp(v,dis1[v])) ;
            }
            else if(node.ss+w > dis1[v] && node.ss+w < dis2[v]){
                dis2[v] = node.ss + w ;
                pq.push(mp(v,dis2[v])) ;
            }
        }
    }

}

void reset(){
    for(int i=0; i<5005; i++){
        adj[i].clear() ;
        dis1[i] = dis2[i] = INT_MAX ;
    }
}

int main()
{
    Boost;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0 ;
    cin>> t ;

    while(t--){
        reset() ;
        int n,r ;
        cin>> n >> r ;
        for(int i=0; i<r; i++){
            int u,v,w ;
            cin>> u >> v >> w ;
            adj[u].pb(mp(v,w)) ;
            adj[v].pb(mp(u,w)) ;
        }
        Case ;
        dijkstra() ;
        cout<< dis2[n] << endl ;
    }


    return 0;
}

