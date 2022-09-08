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

int n,a,b,k ;


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    cin>> n>>a>>b>>k ;

    int cnt=0 ;
    vector<int> rem ;
    for(int i=0; i<n ;i++){
        int temp ;
        cin>> temp ;
        if(temp%(a+b) <= a && temp%(a+b)!=0) cnt++ ;
        else if(temp%(a+b) > a){
            int r = (temp%(a+b)) - a ;
            if(r >= 0) rem.pb(r) ;
        }
        else if(temp%(a+b) == 0)
            rem.pb(b) ;
    }

    sort(all(rem)) ;
    for(int i=0; k>0 && i<rem.size(); i++){
        int trick = rem[i]/a ;
        if(rem[i]%a!=0) trick++ ;
        if(trick > k)
            break ;
        k -= trick ;
        cnt++ ;
    }

    cout<< cnt << endl ;

    return 0;
}
