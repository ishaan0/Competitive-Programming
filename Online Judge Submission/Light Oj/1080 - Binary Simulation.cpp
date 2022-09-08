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
string str ;
int tree[4*lim] ;

void update(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return ;
    if(qi<=lo && hi<=qj){
        tree[node]++ ;
        return ;
    }
    int left = node*2 ;
    int right = left+1 ;
    int mid = lo+(hi-lo)/2 ;
    update(left,lo,mid,qi,qj) ;
    update(right,mid+1,hi,qi,qj) ;
}

void query(int node,int lo,int hi,int q){
    if(tree[node] != 0 && lo!=hi){
        tree[2*node] += tree[node] ;
        tree[2*node+1] += tree[node] ;
        tree[node] = 0 ;
    }
    if(q<lo || q>hi) return ;
    if(lo == hi){
        if(tree[node]%2 == 1){
            if(str[lo] == '1') str[lo] = '0' ;
            else str[lo] = '1' ;
        }
        tree[node] = 0 ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    query(2*node,lo,mid,q) ;
    query(2*node+1,mid+1,hi,q) ;
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
        memset(tree,0,sizeof(tree)) ;
        cin>> str ;
        str = "0"+str ;
        int sz = str.size()-1 ;

        printf("Case %d:\n",++cs) ;
        int q ;
        scanf("%d",&q) ;
        while(q--){
            char temp[2] ;
            scanf("%s",&temp) ;

            if(temp[0] == 'I'){
                int i,j ;
                scanf("%d%d",&i,&j) ;
                update(1,1,sz,i,j) ;
            }
            else{
                int i ;
                scanf("%d",&i) ;
                query(1,1,sz,i) ;
                printf("%c\n",str[i]) ;
            }
        }
    }


    return 0;
}
