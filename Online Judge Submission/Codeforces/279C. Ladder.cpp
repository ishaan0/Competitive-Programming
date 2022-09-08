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
#define     Case                cout<< "Case "<< ++cs << ": "
#define     inf                 LONG_LONG_MIN
#define     INF                 LONG_LONG_MAX
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

ll const lim = 1e5+5 ;
int arr[lim],up[lim],down[lim] ;
pii tree[4*lim] ;

void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node].ff = arr[lo] ;
        tree[node].ss = lo ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    if(tree[2*node].ff > tree[2*node+1].ff){
        tree[node].ff = tree[2*node].ff ;
        tree[node].ss = tree[2*node].ss ;
    }
    else{
        tree[node].ff = tree[2*node+1].ff ;
        tree[node].ss = tree[2*node+1].ss ;
    }
}

pii query(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return pii(INT_MIN,0) ;
    if(qi<=lo && hi<=qj) return tree[node] ;
    int mid = lo+(hi-lo)/2 ;
    pii lft = query(2*node,lo,mid,qi,qj) ;
    pii rgt = query(2*node+1,mid+1,hi,qi,qj) ;
    pii ans ;
    if(lft.ff > rgt.ff){
        ans.ff = lft.ff ;
        ans.ss = lft.ss ;
    }
    else{
        ans.ff = rgt.ff ;
        ans.ss = rgt.ss ;
    }
    return ans ;
}



//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,m ;
    scanf("%d%d",&n,&m) ;
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]) ;
    arr[0] = arr[n+1] = -1 ;
    for(int i=1; i<=n; i++){
        if(arr[i] > arr[i-1]) up[i] = 1 ;
        if(arr[i] < arr[i-1]) down[i] = 1 ;
        up[i] += up[i-1] ;
        down[i] += down[i-1] ;
    }
    build(1,1,n) ;

    while(m--){
        int lo,hi ;
        scanf("%d%d",&lo,&hi) ;
        pii ans = query(1,1,n,lo,hi) ;
        int idx = ans.ss ;
        int val1 = down[idx]-down[lo] ;
        int val2 = up[hi]-up[idx] ;

        if(val1==0 && val2==0)
            printf("Yes\n") ;
        else printf("No\n") ;
    }

    return 0;
}

