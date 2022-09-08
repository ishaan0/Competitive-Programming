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

int arr[lim],tree[4*lim] ;
void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node] = arr[lo] ;
        return ;
    }
    int left = 2*node ;
    int right = left+1 ;
    int mid = lo + (hi-lo)/2 ;
    build(left,lo,mid) ;
    build(right,mid+1,hi) ;

    tree[node] = min(tree[left],tree[right]) ;
}

int query(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return INT_MAX ;
    if(qi<=lo && hi<=qj) return tree[node] ;
    int left = 2*node ;
    int right = left+1 ;
    int mid = lo + (hi-lo)/2 ;
    int lmn = query(left,lo,mid,qi,qj) ;
    int rmn = query(right,mid+1,hi,qi,qj) ;
    return min(lmn,rmn) ;
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
        int n,q ;
        scanf("%d%d",&n,&q) ;
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]) ;
        build(1,1,n) ;
        printf("Case %d:\n",++cs) ;
        while(q--){
            int l,r ;
            scanf("%d%d",&l,&r) ;
            int ans = query(1,1,n,l,r) ;
            printf("%d\n",ans) ;
        }
    }


    return 0;
}


