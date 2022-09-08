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

bool cmp(pii a,pii b){
    return a.ff > b.ff ;
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n,m,k;
    ll sum = 0;

    cin>>n>>m>>k;

    vector<int>c;
    vector<pii>b;
    c.push_back(-1);

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        b.push_back({x,i});
    }

    sort(all(b),cmp);

    for(int i=0;i<m*k;i++){
        sum+=b[i].first;
        c.push_back(b[i].second);
    }

    cout<<sum<<endl;

    sort(all(c));

    for(int i=m;i<m*k;i+=m)
        cout<<c[i]<<" ";
    cout<<endl;

    return 0;
}


