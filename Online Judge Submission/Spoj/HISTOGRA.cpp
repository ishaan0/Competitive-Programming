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

ll arr[lim],n;

pair<ll,ll> tree[4*lim] ;

void build(ll node,ll lo,ll hi){
    if(lo == hi){
        tree[node].ff = arr[lo] ;
        tree[node].ss = lo ;
        return  ;
    }
    ll mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    tree[node].ff = min(tree[2*node].ff,tree[2*node+1].ff) ;
    if(tree[node].ff == tree[2*node].ff)
        tree[node].ss = tree[2*node].ss ;
    else tree[node].ss = tree[2*node+1].ss ;
}

pair<ll,ll> query(ll node,ll lo,ll hi,ll qi,ll qj){
    if(qj<lo || qi>hi) return pair<ll,ll>(INT_MAX,0) ;
    else if(qi<=lo && hi<=qj)
        return tree[node] ;
    ll mid = lo+(hi-lo)/2 ;
    pair<ll,ll> lft = query(2*node,lo,mid,qi,qj) ;
    pair<ll,ll> rgt = query(2*node+1,mid+1,hi,qi,qj) ;
    if(lft.ff < rgt.ff) return lft ;
    else return rgt ;
}

ll func(ll lo,ll hi){
    if(lo == hi) return arr[lo] ;
    else if(lo>hi) return INT_MIN ;
    pair<ll,ll> tp = query(1,1,n,lo,hi) ;
    ll h = tp.ff ;
    ll pos = tp.ss ;
    ll ans = (hi-lo+1)*h ;
    ans = max(ans,func(lo,pos-1)) ;
    ans = max(ans,func(pos+1,hi)) ;
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

    while(true){
        scanf("%lld",&n) ;
        if(n==0) break ;
        memset(arr,0,sizeof arr) ;
        memset(tree,0,sizeof tree) ;
        for(int i=1; i<=n; i++)
            scanf("%lld",&arr[i]) ;
        build(1,1,n) ;
        ll ans = func(1,n) ;
        printf("%lld\n",ans) ;
    }

    return 0;
}



