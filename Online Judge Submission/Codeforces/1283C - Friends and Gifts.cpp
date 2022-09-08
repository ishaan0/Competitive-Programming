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

    int n;
    cin >> n;
    vector<int>a(n),b,c(n),d;

    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(a[i]){
    		a[i]--;
    		c[a[i]]++;
    	}
    	else b.pb(i);
    }

    for(int i=0;i<n;i++)
    	if(!c[i]) d.pb(i);

    for(int i=0;i<b.size();i++){
    	if(b[i]==d[i]){
    		if(i) swap(b[i],b[i-1]);
    		else swap(b[i],b[i+1]);
        }
    }

    for(int i=0;i<b.size();i++)
    	a[b[i]] = d[i];

    for(int i=0;i<n;i++)
    	cout << a[i]+1 << " ";
    cout<< endl ;

    return 0;
}

