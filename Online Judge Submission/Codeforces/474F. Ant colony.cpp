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
int n,arr[lim] ;
int tree[4*lim] ;

void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node] = arr[lo] ;
        return ;
    }
    int left = node*2 ;
    int right = left+1 ;
    int mid = lo + (hi-lo)/2 ;
    build(left,lo,mid) ;
    build(right,mid+1,hi) ;
    tree[node] = __gcd(tree[left],tree[right]) ;
}

int query(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return 0 ;
    if(qi<=lo && hi<=qj){
        return tree[node] ;
    }
    int left = node*2 ;
    int right = left+1 ;
    int mid = lo + (hi-lo)/2 ;
    int lval = query(left,lo,mid,qi,qj) ;
    int rval = query(right,mid+1,hi,qi,qj) ;
    return __gcd(lval,rval) ;
}


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    cin>> n ;
    vector<pii > srch ;
    for(int i=1; i<=n; i++){
        cin>> arr[i] ;
        srch.pb(mk(arr[i],i)) ;
    }
    build(1,1,n) ;
    sort(all(srch)) ;
    int q ;
    cin>> q ;

    while(q--){
        int l,h ;
        cin>> l >> h ;
        int gg = query(1,1,n,l,h) ;
        int cnt = upper_bound(all(srch),mk(gg,h)) - lower_bound(all(srch),mk(gg,l)) ;

        cout<< h-l+1-cnt << endl ;

    }

    return 0;
}


