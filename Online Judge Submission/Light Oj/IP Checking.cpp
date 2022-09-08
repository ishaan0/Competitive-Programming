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
#define     ed                  "\n"

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;

int DecimalToBinary(int n){
    int res = 0 ;
    vector<int> arr ;
    while(n!=0){
        arr.pb(n%2) ;
        n /= 2 ;
    }
    for(int i=arr.size()-1; i>=0; i--)
        res = (res*10) + arr[i] ;

    return res ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    vector<int> binary ;
    for(int i=0; i<=255; i++){
        int bin = DecimalToBinary(i);
        binary.pb(bin) ;
    }

    int t,cs=0 ;
    cin>> t ;

    while(t--){
        int a,b,c,d,l,m,n,o ;
        char ch ;
        cin>> a >>ch>> b >>ch>> c >>ch>> d;
        cin>> l >>ch>> m >>ch>> n >>ch>> o;

        if(binary[a]==l && binary[b]==m && binary[c]==n && binary[d]==o)
            cout<< "Case " << ++cs << ": Yes" << endl;
        else cout<< "Case " << ++cs << ": No" << endl;
    }


    return 0;
}



