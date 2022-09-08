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

vector<int> p,r ;
void init(int n){
    p.resize(n+5) ;
    r.resize(n+5) ;
    for(int i=0; i<n+5; i++){
        p[i] = i ;
        r[i] = 1 ;
    }
}

int findP(int n){
    if(p[n] == n) return n ;
    return p[n] = findP(p[n]) ;
}

void unionSet(int u,int v){
    //cout<< "de-> " << u << " " << v <<endl ;
    int x = findP(u) ;
    int y = findP(v) ;
    if(x == y) return ;
    if(r[x] > r[y])
        p[y] = p[x] ;
    else if(r[y] > r[x])
        p[x] = p[y] ;
    else{
        p[x] = p[y] ;
        r[x]++ ;
    }
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

    init(n) ;
    for(int i=0; i<m; i++){
        int k,u,v;
        cin>> k ;
        int temp[k] ;
        for(int j=0; j<k; j++)
            cin>> temp[j] ;
        if(k>0) u = temp[0] ;
        for(int j=1; j<k; j++){
            v = temp[j] ;
            unionSet(u,v) ;
            u = v ;
        }
    }

    vector<int> group(n+5) ;
    for(int i=0; i<n+5; i++){
        //cout<< "de-> " << i << " " << p[i] << endl ;
        group[findP(i)]++ ;
    }
    for(int i=1; i<=n; i++)
        cout<< group[findP(i)] << " " ;
    cout<< endl ;

    return 0;
}


