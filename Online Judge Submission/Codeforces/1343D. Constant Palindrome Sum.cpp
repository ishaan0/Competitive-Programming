#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
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
const int lim = 4e5+5 ;

int arr[lim] ;
pii tree[4*lim] ;

void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node].ff = arr[lo] ;
        tree[node].ss = 0 ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    tree[node].ff = tree[2*node].ff + tree[2*node+1].ff ;
    tree[node].ss = 0 ;
}

void update(int node,int lo,int hi,int qi,int qj,int val){
    if(qj<lo || qi>hi) return ;
    else if(qi<=lo && hi<=qj){
        tree[node].ff += (hi-lo+1)*val ;
        tree[node].ss += val ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    update(2*node,lo,mid,qi,qj,val) ;
    update(2*node+1,mid+1,hi,qi,qj,val) ;
    tree[node].ff = tree[2*node].ff + tree[2*node+1].ff + (tree[node].ff*(hi-lo+1));
}

int query(int node,int lo,int hi,int qi,int qj,int val=0){
    if(qj<lo || qi>hi) return 0 ;
    else if(qi<=lo && hi<=qj)
        return tree[node].ff + ((hi-lo+1)*val) ;
    int mid = lo+(hi-lo)/2 ;
    int lft = query(2*node,lo,mid,qi,qj,val+tree[node].ss) ;
    int rgt = query(2*node+1,mid+1,hi,qi,qj,val+tree[node].ss) ;
    return lft+rgt ;
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>> t ;

    while(t--){
        int n,k ;
        cin>> n >> k ;
        for(int i=1; i<=2*k; i++) arr[i] = n ;
        build(1,1,2*k) ;

        vector<int> a(n+1) ;
        for(int i=1; i<=n; i++)
            cin>> a[i] ;

        for(int i=1; i<=n/2; i++){
            update(1,1,2*k,a[i]+a[n-i+1],k+max(a[i],a[n-i+1]),-1) ;
            update(1,1,2*k,1+min(a[i],a[n-i+1]),a[i]+a[n-i+1],-1) ;
        }

        int mn = INT_MAX ;
        for(int i=1; i<=2*k; i++)
            mn = min(mn,query(1,1,2*k,i,i)) ;

        cout<< mn << endl ;
    }


    return 0;
}



