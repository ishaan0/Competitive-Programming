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

pair<int,int> tree[4*lim] ;

void update(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return  ;
    else if(qi<=lo && hi<=qj){
        tree[node].ff = (hi-lo+1) - tree[node].ff ;
        tree[node].ss++ ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    update(2*node,lo,mid,qi,qj) ;
    update(2*node+1,mid+1,hi,qi,qj) ;
    tree[node].ff = tree[2*node].ff+tree[2*node+1].ff ;
    if(tree[node].ss%2!=0) tree[node].ff = (hi-lo+1)-tree[node].ff ;
}

int query(int node,int lo,int hi,int qi,int qj,int carry=0){
    if(qj<lo || qi>hi) return 0;
    else if(qi<=lo && hi<=qj){
        int val = tree[node].ff ;
        if(carry%2 != 0)
            val = (hi-lo+1) - val ;
        return val ;
    }
    int mid = lo+(hi-lo)/2 ;
    int ans = query(2*node,lo,mid,qi,qj,carry+tree[node].ss) ;
    ans += query(2*node+1,mid+1,hi,qi,qj,carry+tree[node].ss) ;
    return ans ;
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
    scanf("%d%d",&n,&m) ;

    for(int i=0; i<m; i++){
        int bin,l,r ;
        scanf("%d%d%d",&bin,&l,&r) ;
        if(bin == 0)
            update(1,1,n,l,r) ;
        else{
            int ans = query(1,1,n,l,r) ;
            printf("%d\n",ans) ;
        }
    }

    return 0;
}


