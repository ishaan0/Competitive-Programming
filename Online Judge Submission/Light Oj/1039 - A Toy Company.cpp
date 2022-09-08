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
#define     PI                  3.1415926535897932384
#define     eps                 1e-9
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

struct data{
    int a,b,c ;
    data(){a=b=c=0;}
    data(int aa,int bb,int cc){
        a=aa,b=bb,c=cc ;
    }
};

string st,ed ;
vector<data> arr ;
int vis[26][26][26] ;
int n ;

inline bool checkBit(int num,int pos){return (bool)(num & (1<<pos));}
inline int makeDig(string str){
    int dig = 0 ;
    for(int i=0; i<str.size(); i++){
        int pos = str[i]-'a' ;
        dig |= (1<<pos) ;
    }
    return dig ;
}
inline bool isForbidden(data temp){
    for(int i=0; i<n; i++){
        if(checkBit(arr[i].a,temp.a) && checkBit(arr[i].b,temp.b)
           && checkBit(arr[i].c,temp.c)) return true ;
    }
    return false ;
}



int bfs(){
    if(st == ed) return 0 ;
    queue<data> q ;
    q.push(data(st[0]-'a',st[1]-'a',st[2]-'a')) ;
    vis[st[0]-'a'][st[1]-'a'][st[2]-'a'] = 0 ;
    while(!q.empty()){
        data u = q.front() ;
        q.pop() ;
        if(isForbidden(u)) continue ;
        if(ed[0]-'a'==u.a && ed[1]-'a'==u.b &&
           ed[2]-'a'==u.c) return vis[u.a][u.b][u.c] ;
        int temp[] = {u.a,u.b,u.c} ;
        for(int i=0; i<3; i++){
            int id = temp[i] ;
            temp[i]++ ;
            if(temp[i] > 25) temp[i] = 0 ;
            if(vis[temp[0]][temp[1]][temp[2]]==-1){
                q.push(data(temp[0],temp[1],temp[2])) ;
                vis[temp[0]][temp[1]][temp[2]] = vis[u.a][u.b][u.c]+1 ;
            }
            temp[i] = id ;
        }
        for(int i=0; i<3; i++){
            int id = temp[i] ;
            temp[i]-- ;
            if(temp[i] < 0) temp[i] = 25 ;
            if(vis[temp[0]][temp[1]][temp[2]]==-1){
                q.push(data(temp[0],temp[1],temp[2])) ;
                vis[temp[0]][temp[1]][temp[2]] = vis[u.a][u.b][u.c]+1 ;
            }
            temp[i] = id ;
        }
    }
}


void solve(){
    arr.clear() ;
    cin>> st >> ed ;
    cin>> n ;
    for(int i=0; i<n; i++){
        data temp ;
        string a,b,c ;
        cin>> a >> b >> c ;
        temp.a = makeDig(a) ;
        temp.b = makeDig(b) ;
        temp.c = makeDig(c) ;
        arr.pb(temp) ;
    }

    for(int tt=0; tt<n; tt++){
        if(checkBit(arr[tt].a,st[0]-'a') && checkBit(arr[tt].b,st[1]-'a')
        && checkBit(arr[tt].c,st[2]-'a') ){
            cout<< "-1" << endl ;
            return ;
        }
    }
    for(int tt=0; tt<n; tt++){
        if(checkBit(arr[tt].a,ed[0]-'a') && checkBit(arr[tt].b,ed[1]-'a')
        && checkBit(arr[tt].c,ed[2]-'a') ){
            cout<< "-1" << endl ;
            return ;
        }
    }
    memset(vis,-1,sizeof vis) ;
    ll ans = bfs() ;
    cout<< ans << endl ;
}


int main()
{
    Boost;

    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t = 1,cs = 0 ;
    cin>> t ;

    while(t--){
        Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}


