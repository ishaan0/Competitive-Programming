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
        int n,q ;
        scanf("%d%d",&n,&q) ;
        vector<pii > range ;
        vector<int> query,points ;
        unordered_map<int,int> m ;
        for(int i=0; i<n; i++){
            int l,r ;
            scanf("%d%d",&l,&r) ;
            range.pb(mk(l,r)) ;
            points.pb(l) ;
            points.pb(r) ;
        }
        for(int i=0; i<q; i++){
            int p ;
            scanf("%d",&p) ;
            points.pb(p) ;
            query.pb(p) ;
        }
        sort(all(points)) ;
        int idx=0 ;
        for(int i=0; i<points.size(); i++){
            if(!m.count(points[i]))
                m[points[i]] = idx++ ;
        }
        int freq[300005] ;
        memset(freq,0,sizeof(freq)) ;
        for(int i=0; i<n; i++){
            int l = m[range[i].ff] ;
            int r = m[range[i].ss] ;
            freq[l]++ ;
            freq[r+1]-- ;
        }
        for(int i=1; i<300005; i++)
            freq[i] += freq[i-1] ;
        printf("Case %d:\n",++cs) ;
        for(int i=0; i<q; i++){
            int p = m[query[i]] ;
            printf("%d\n",freq[p]) ;
        }
    }

    return 0;
}


