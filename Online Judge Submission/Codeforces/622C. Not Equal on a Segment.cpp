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
const int lim = 2*(1e5)+5 ;

vector<int> tree[4*lim] ;
vector<int> index[4*lim] ;
int arr[lim],n,m ;

void mergeArr(int left,int right,int node){
    int i=0,j=0 ;
    while(i<tree[left].size() && j<tree[right].size()){
        if(tree[left][i] < tree[right][j]){
            tree[node].pb(tree[left][i]) ;
            index[node].pb(index[left][i]) ;
            i++ ;
        }
        else{
            tree[node].pb(tree[right][j]) ;
            index[node].pb(index[right][j]) ;
            j++ ;
        }
    }
    while(i<tree[left].size()){
        tree[node].pb(tree[left][i]) ;
        index[node].pb(index[left][i]) ;
        i++ ;
    }
    while(j<tree[right].size()){
        tree[node].pb(tree[right][j]) ;
        index[node].pb(index[right][j]) ;
        j++ ;
    }
}

void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node].pb(arr[lo]) ;
        index[node].pb(lo) ;
        return  ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    mergeArr(2*node,2*node+1,node) ;
}

int query(int node,int lo,int hi,int qi,int qj,int val){
    if(qj<lo || qi>hi) return -1 ;
    if(qi<=lo && hi<=qj){
        int pos = -1 ;
        int sz = tree[node].size() ;
        if(tree[node][0] != val) pos = index[node][0] ;
        else if(tree[node][sz-1] != val) pos = index[node][sz-1] ;
        return pos ;
    }
    int mid = lo+(hi-lo)/2 ;
    int lft = query(2*node,lo,mid,qi,qj,val) ;
    int rgt = query(2*node+1,mid+1,hi,qi,qj,val) ;
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

    cin>> n >> m ;
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]) ;
    build(1,1,n) ;

    while(m--){
        int l,r,val ;
        scanf("%d%d%d",&l,&r,&val) ;
        int ans = query(1,1,n,l,r,val) ;
        printf("%d\n",ans) ;
    }


    return 0;
}


