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
#define lim 132000
int arr[lim] ;
int tree[4*lim] ;

bool build(int node,int lo,int hi){
    if(lo == hi){
        tree[node] = arr[lo] ;
        return true ;
    }
    int left = 2*node ;
    int right = left+1 ;
    int mid = lo + (hi-lo)/2 ;
    bool flag = build(left,lo,mid) ;
    flag = build(right,mid+1,hi) ;

    if(flag){
        tree[node] = tree[left] | tree[right] ;
        return false ;
    }
    else{
        tree[node] = tree[left] ^ tree[right] ;
        return true ;
    }
}

int update(int node,int lo,int hi,int qi,int val){

    if(qi<lo || qi>hi)
        return -1 ;
    if(lo == hi){
        tree[node] = val ;
        return 1 ;
    }
    int left = 2*node ;
    int right = left+1 ;
    int mid = lo + (hi-lo)/2 ;
    int chkL = update(left,lo,mid,qi,val) ;
    int chkR = update(right,mid+1,hi,qi,val) ;
    bool flag ;
    if(chkL == -1) flag = (bool)chkR ;
    if(chkR == -1) flag = (bool) chkL ;


    if(flag){
        tree[node] = tree[left] | tree[right] ;
        return 0 ;
    }
    else{
        tree[node] = tree[left] ^ tree[right] ;
        return 1 ;
    }

}


int findS(int n){
    int sz = 1 ;
    for(int i=1; i<=n; i++)
        sz *= 2 ;
    return sz ;
}

//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,m ;
    cin>> n >> m ;
    int sz = findS(n) ;
    for(int i=1; i<=sz; i++)
        cin>> arr[i] ;
    build(1,1,sz) ;
    for(int i=0; i<m; i++){
        int p,b ;
        cin>> p >> b ;
        update(1,1,sz,p,b) ;
        cout<< tree[1] << endl ;
    }

    return 0;
}


