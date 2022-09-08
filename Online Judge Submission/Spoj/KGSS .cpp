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
pii tree[4*lim] ;
int arr[lim] ;

void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node].ff = arr[lo] ;
        tree[node].ss = 0 ;
        return  ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    vector<int> temp = {tree[2*node].ff,tree[2*node].ss,tree[2*node+1].ff,
                  tree[2*node+1].ss} ;
    sort(rall(temp)) ;
    tree[node].ff = temp[0] ;
    tree[node].ss = temp[1] ;
}


void update(int node,int lo,int hi,int qi,int val){
    if(qi<lo || qi>hi) return ;
    if(lo == hi){
        tree[node].ff =  val ;
        tree[node].ss = 0 ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    update(2*node,lo,mid,qi,val) ;
    update(2*node+1,mid+1,hi,qi,val) ;
    vector<int> temp = {tree[2*node].ff,tree[2*node].ss,tree[2*node+1].ff,
                  tree[2*node+1].ss} ;
    sort(rall(temp)) ;
    tree[node].ff = temp[0] ;
    tree[node].ss = temp[1] ;
}

pii query(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return pii(0,0) ;
    if(qi<=lo && hi<=qj)
        return tree[node] ;
    int mid = lo+(hi-lo)/2 ;
    pii lft = query(2*node,lo,mid,qi,qj) ;
    pii rgt = query(2*node+1,mid+1,hi,qi,qj) ;
    vector<int> temp = {lft.ff,lft.ss,rgt.ff,rgt.ss} ;
    sort(rall(temp)) ;
    return pii(temp[0],temp[1]) ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,q ;
    cin>> n ;
    for(int i=1; i<=n; i++)
        cin>> arr[i] ;
    build(1,1,n) ;
    cin>> q ;

    while(q--){
        int a,b ;
        string chk ;
        cin>> chk >> a >> b ;
        if(chk == "U")
            update(1,1,n,a,b) ;
        else if(chk == "Q"){
            pii ans = query(1,1,n,a,b) ;
            cout<< (ans.ff+ans.ss) << endl ;
        }
    }


    return 0;
}




