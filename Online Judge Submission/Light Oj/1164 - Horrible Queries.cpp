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
#define     sum                  first
#define     prop                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;
#define lim 100005
pair<ll,ll> tree[4*lim] ;

void update(int node,int lo,int hi,int qi,int qj,ll val){
    if(qj<lo || qi>hi) return ;
    if(qi<=lo && hi<=qj){
        tree[node].sum += ((ll)(hi-lo+1)*val) ;
        tree[node].prop += val ;
        return ;
    }
    int left = node*2 ;
    int right = left+1 ;
    int mid = lo+(hi-lo)/2 ;
    update(left,lo,mid,qi,qj,val) ;
    update(right,mid+1,hi,qi,qj,val) ;
    tree[node].sum = tree[left].sum+tree[right].sum+((ll)(hi-lo+1)*tree[node].prop) ;
}

ll query(int node,int lo,int hi,int qi,int qj,ll carry=0){
    if(qj<lo || qi>hi) return 0 ;
    if(qi<=lo && hi<=qj){
        return tree[node].sum+((ll)(hi-lo+1)*carry) ;
    }
    int left = node*2 ;
    int right = left+1 ;
    int mid = lo+(hi-lo)/2 ;
    ll lft = query(left,lo,mid,qi,qj,carry+tree[node].prop) ;
    ll rgt = query(right,mid+1,hi,qi,qj,carry+tree[node].prop) ;
    return (lft+rgt) ;
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
        for(int i=0; i<4*lim; i++){
            tree[i].sum = 0 ;
            tree[i].prop = 0 ;
        }
        int n,q ;
        scanf("%d%d",&n,&q) ;
        printf("Case %d:\n",++cs) ;
        while(q--){
            int chk ;
            scanf("%d",&chk) ;
            if(chk == 0){
                ll x,y,v ;
                scanf("%lld%lld%lld",&x,&y,&v) ;
                update(1,1,n,x+1,y+1,v) ;
            }
            else{
                ll x,y ;
                scanf("%lld%lld",&x,&y) ;
                ll ans = query(1,1,n,x+1,y+1) ;
                printf("%lld\n",ans) ;
            }
        }
    }

    return 0;
}

