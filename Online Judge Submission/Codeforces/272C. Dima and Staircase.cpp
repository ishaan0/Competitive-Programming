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
#define     val                  first
#define     prop                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;

#define lim 100005
ll arr[lim] ;
pair<ll,ll> tree[4*lim] ;

void build(ll node,ll lo,ll hi){
    if(lo == hi){
        tree[node].val = arr[lo] ;
        tree[node].prop = 0 ;
        return ;
    }
    ll mid = lo + (hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    tree[node] = max(tree[2*node],tree[2*node+1]) ;
}

void update(ll node,ll lo,ll hi,ll qi,ll qj,ll mx){
    if(qj<lo || qi>hi)
        return ;
    else if(qi<=lo && hi<=qj){
        tree[node].val = max(tree[node].val,mx) ;
        tree[node].prop = max(tree[node].prop,mx) ;
        return ;
    }
    ll mid = lo+(hi-lo)/2 ;
    update(2*node,lo,mid,qi,qj,mx) ;
    update(2*node+1,mid+1,hi,qi,qj,mx) ;
    tree[node].val = max(tree[node*2].val,tree[node*2+1].val) ;
    tree[node].val = max(tree[node].val,tree[node].prop) ;
}

ll query(ll node,ll lo,ll hi,ll qi,ll qj,ll carry=0){
    if(qj<lo || qi>hi)
        return 0 ;
    else if(qi<=lo && hi<=qj){
        return max(tree[node].val,carry) ;
    }
    ll mid = lo+(hi-lo)/2 ;
    ll lft = query(2*node,lo,mid,qi,qj,max(carry,tree[node].prop)) ;
    ll rgt = query(2*node+1,mid+1,hi,qi,qj,max(carry,tree[node].prop)) ;
    return max(lft,rgt) ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll n ;
    cin>> n ;
    for(int i=1; i<=n; i++)
        cin>> arr[i] ;
    build(1,1,n) ;
    ll m ;
    cin>> m ;
    while(m--){
        ll w,h ;
        cin>>w >> h ;
        ll ans = query(1,1,n,1,w) ;
        cout<< ans << endl ;
        update(1,1,n,1,w,ans+h) ;
    }

    return 0;
}

