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


vector<int> tree[4*lim] ;
int arr[lim] ;

void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node].pb(arr[lo]) ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),
          tree[2*node+1].end(),back_inserter(tree[node])) ;
}

int query(int node,int lo,int hi,int qi,int qj,int val){
    if(qj<lo || qi>hi) return 0 ;
    if(qi<=lo && hi<=qj ){
        int k = upper_bound(all(tree[node]),val)-tree[node].begin() ;
        return k ;
    }
    int mid = lo+(hi-lo)/2 ;
    int lft = query(2*node,lo,mid,qi,qj,val) ;
    int rgt = query(2*node+1,mid+1,hi,qi,qj,val) ;
    return lft+rgt ;
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
    vector<int> vv ;
    for(int i=1; i<=n; i++){
        cin>> arr[i] ;
        vv.pb(arr[i]) ;
    }
    sort(all(vv)) ;
    for(int i=1; i<=n; i++)
        arr[i] = lower_bound(all(vv),arr[i]) - vv.begin()+1 ;

    build(1,1,n) ;

    while(m--){
        int i,j,k,lo=1,hi=n ,ans=0;
        cin>> i >> j >> k ;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2 ;
            int temp = query(1,1,n,i,j,mid) ;

            if(temp >= k){
                ans = mid ;
                hi = mid-1 ;
            }
            else lo = mid+1 ;
        }

        cout<< vv[ans-1] << endl ;

    }

    return 0;
}




