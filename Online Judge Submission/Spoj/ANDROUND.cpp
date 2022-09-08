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
#define lim 20005

int tree[4*lim] ;
int arr[lim] ;

void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node] = arr[lo] ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    tree[node] = tree[2*node] & tree[2*node+1] ;
}

int query(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return INT_MAX ;
    if(qi<=lo && hi<=qj)
        return tree[node] ;
    int mid = lo+(hi-lo)/2 ;
    int lft = query(2*node,lo,mid,qi,qj) ;
    int rgt = query(2*node+1,mid+1,hi,qi,qj) ;
    return (lft&rgt) ;
}



//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>> t ;

    while(t--){
        int n,k ;
        cin>>n >> k ;

        vector<int> res ;
        for(int i=1; i<=n; i++)
            cin>> arr[i] ;
        build(1,1,n) ;
        k = min(n-1,k) ;
        for(int i=1; i<=n; i++){
            int lo = i-k ;
            int hi = i+k ;
            int ans ;

            if(lo < 1){
                ans = query(1,1,n,1,i) ;
                ans &= query(1,1,n,n+lo,n) ;
            }
            else ans = query(1,1,n,lo,i) ;

            if(hi>n){
                int rem = hi-n ;
                ans &= query(1,1,n,i,n) ;
                ans &= query(1,1,n,1,rem) ;
            }
            else ans &= query(1,1,n,i,hi) ;

            res.pb(ans) ;
        }
        foreach(res)
            cout<< value <<" " ;
        cout<< endl ;
    }


    return 0;
}





