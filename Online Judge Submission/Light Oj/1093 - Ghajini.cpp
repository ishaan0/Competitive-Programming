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

ll arr[lim] ;
vector<pair<ll,ll> > tree(4*lim) ;
void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node].ff = tree[node].ss = arr[lo] ;
        return ;
    }
    int left = 2*node ;
    int right = left+1 ;
    int mid = lo + (hi-lo)/2 ;
    build(left,lo,mid) ;
    build(right,mid+1,hi) ;

    tree[node].ff = min(tree[left].ff,tree[right].ff) ;
    tree[node].ss = max(tree[left].ss,tree[right].ss) ;

}

pair<ll,ll> query(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return mk(INT_MAX,INT_MIN) ;
    if(qi<=lo && hi<=qj) return tree[node] ;
    int left = 2*node ;
    int right = left+1 ;
    int mid = lo + (hi-lo)/2 ;
    pair<ll,ll> lmn = query(left,lo,mid,qi,qj) ;
    pair<ll,ll> rmn = query(right,mid+1,hi,qi,qj) ;
    pair<ll,ll> temp = mk(min(lmn.ff,rmn.ff),max(lmn.ss,rmn.ss)) ;
    return temp ;
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
    scanf("%d",&t) ;

    while(t--){
        int n,d ;
        scanf("%d%d",&n,&d) ;
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]) ;
        build(1,1,n) ;
        ll mx = INT_MIN ;
        for(int i=1; i<=n-d+1; i++){
            int lo = i ;
            int hi = lo+d-1 ;
            pair<ll,ll> temp = query(1,1,n,lo,hi) ;
            ll diff = temp.ss - temp.ff ;
            mx = max(mx,diff) ;
        }

        printf("Case %d: %lld\n",++cs,mx) ;

    }


    return 0;
}


