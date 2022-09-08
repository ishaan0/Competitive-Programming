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

struct node{
    int z,o,t,prop;
    node(){
        z = 1 ;
        o = t =prop= 0 ;
    }
};

node tree[4*lim] ;

void build(int node,int lo,int hi){
    if(lo == hi)
        return ;
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    tree[node].z = tree[2*node].z+tree[2*node+1].z ;
}


void update(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return ;
    else if(qi<=lo && hi<=qj){
        swap(tree[node].z,tree[node].o) ;
        swap(tree[node].z,tree[node].t) ;
        tree[node].prop++ ;
        return ;
    }
    int mid = lo + (hi-lo)/2 ;
    update(2*node,lo,mid,qi,qj) ;
    update(2*node+1,mid+1,hi,qi,qj) ;
    tree[node].z = tree[2*node].z+tree[2*node+1].z ;
    tree[node].o = tree[2*node].o+tree[2*node+1].o ;
    tree[node].t = tree[2*node].t+tree[2*node+1].t ;
    int chng = tree[node].prop%3 ;
    for(int i=0; i<chng; i++){
        swap(tree[node].z,tree[node].o) ;
        swap(tree[node].z,tree[node].t) ;
    }
}

int query(int node,int lo,int hi,int qi,int qj,int carry=0){
    if(qj<lo || qi>hi) return 0;
    else if(qi<=lo && hi<=qj){
        int z=tree[node].z ,o=tree[node].o,t=tree[node].t ;
        int chng = carry%3 ;
        for(int i=0; i<chng; i++){
            swap(z,o) ;
            swap(z,t) ;
        }
        return z ;
    }
    int mid = lo+(hi-lo)/2 ;
    int l = query(2*node,lo,mid,qi,qj,tree[node].prop+carry) ;
    int r = query(2*node+1,mid+1,hi,qi,qj,tree[node].prop+carry) ;
    return (l+r) ;
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
    scanf("%d%d",&n,&q) ;
    build(1,1,n) ;
    while(q--){
        int chk,a,b;
        scanf("%d%d%d",&chk,&a,&b) ;
        a++,b++ ;
        if(chk == 0)
            update(1,1,n,a,b) ;
        else{
            int ans = query(1,1,n,a,b) ;
            printf("%d\n",ans) ;
        }
    }

    return 0;
}



