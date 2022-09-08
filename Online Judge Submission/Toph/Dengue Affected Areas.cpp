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
const int lim = 100005 ;


vector<int> tree[4*lim] ;
int arr[lim] ;

void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node].pb(arr[lo]) ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    merge(all(tree[2*node]),all(tree[2*node+1]),back_inserter(tree[node])) ;
}

pair<int,pair<int,int> > query(int node,int lo,int hi,int qi,int qj,int val1,int val2){
    if(qj<lo || qi>hi) return mk(0,mk(INT_MAX,INT_MIN)) ;
    else if(qi<=lo && hi<=qj){
        int lwr = lower_bound(all(tree[node]),val1) - tree[node].begin() ;
        int upr = upper_bound(all(tree[node]),val2) - tree[node].begin() ;
        if(upr - lwr == 0) return mk(0,mk(INT_MAX,INT_MIN)) ;
        return mk(upr-lwr,mk(tree[node][lwr],tree[node][upr-1])) ;
    }
    int mid = lo+(hi-lo)/2 ;
    pair<int,pair<int,int> > lft = query(2*node,lo,mid,qi,qj,val1,val2) ;
    pair<int,pair<int,int> > rgt = query(2*node+1,mid+1,hi,qi,qj,val1,val2);
    lft.ff += rgt.ff ;
    lft.ss.ff = min(lft.ss.ff,rgt.ss.ff) ;
    lft.ss.ss = max(lft.ss.ss,rgt.ss.ss) ;
    return lft ;

}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n ,m  ;
    scanf("%d%d",&n,&m) ;
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]) ;
    build(1,1,n) ;

    while(m--){
        int l,r,p,q ;
        scanf("%d%d%d%d",&l,&r,&p,&q) ;
        pair<int,pair<int,int> > ans = query(1,1,n,l,r,p,q) ;
        if(ans.ff == 0) ans.ss.ff = ans.ss.ss = -1 ;
        printf("%d %d %d\n",ans.ff,ans.ss.ff,ans.ss.ss) ;
    }

    return 0;
}


