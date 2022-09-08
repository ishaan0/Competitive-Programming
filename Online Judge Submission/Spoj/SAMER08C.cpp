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


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll n,m ;

    while(cin>> n >>m){
        if(n==0 && m == 0) break ;
        int row[m],col[n] ;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                cin>> row[j] ;
            for(int j=0; j<m; j++){
                int prv1=0,prv2=0 ;
                if(j-1>=0) prv1 = row[j-1] ;
                if(j-2>=0) prv2 = row[j-2] ;
                row[j] = max(row[j]+prv2,prv1) ;
            }
            col[i] = row[m-1] ;
        }

        for(int i=0; i<n; i++){
            int prv1=0,prv2=0 ;
            if(i-1>=0) prv1 = col[i-1] ;
            if(i-2>=0) prv2 = col[i-2] ;
            col[i] = max(col[i]+prv2,prv1) ;
        }

        cout<< col[n-1] << endl ;
    }

    return 0;
}



