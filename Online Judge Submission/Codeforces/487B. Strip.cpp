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



int mn[20][lim], mx[20][lim] ;
int arr[lim] ;

void build(int n){
    for(int i=0; i<n; i++)
        mn[0][i] = mx[0][i] = arr[i] ;

    for(int i=1; (1<<i)<=n; i++){
        for(int j=0; (j+(1<<i)-1)<n; j++){
            int x = mn[i-1][j] ;
            int y = mn[i-1][j+(1<<(i-1))] ;
            mn[i][j] = min(x,y) ;
            x = mx[i-1][j] ;
            y = mx[i-1][j+(1<<(i-1))] ;
            mx[i][j] = max(x,y) ;
        }
    }
}

pii query(int i,int j){
    int k = log2(j-i+1) ;
    int x = mn[k][i] ;
    int y = mn[k][j-(1<<k)+1] ;
    pii ans ;
    ans.ff = min(x,y) ;
    x = mx[k][i] ;
    y = mx[k][j-(1<<k)+1] ;
    ans.ss = max(x,y) ;
    return ans ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll n,s,l ;
    cin>>  n >> s >> l ;
    for(int i=0; i<n; i++)
        cin>> arr[i] ;
    build(n) ;

    map<int,int> ok ;
    int idx ;
    ok[-1] = 0 ;

    for(int i=0; i<n; i++){
		int lo=1, hi=i+1;
		while(lo<=hi){
			int mid=(lo+hi)/2 ;
			pii diff = query(mid-1,i) ;
			if(diff.ss-diff.ff <= s) idx = mid, hi = mid-1 ;
			else lo = mid+1 ;
		}

		auto it = ok.lower_bound(idx-2);
		if(it != ok.end() && i-(*it).first >= l)  ok[i] = (*it).second+1  ;
	}

    if(!ok.count(n-1)) cout<< "-1" <<endl ;
    else cout<< ok[n-1] << endl ;

    return 0;
}



