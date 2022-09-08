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
const ll mod = 1423172537 ;
const ll base = 61 ;

void matchPat(string text,string pat){
    ll n = text.size() ;
    ll m = pat.size() ;
    ll th= 0, ph = 0 ;

    for(int i=0; i<m; i++){
        ph = ph*base + (pat[i]-'a'+1) ;
        th = th*base + (text[i]-'a'+1) ;
        ph %= mod  ;
        th %= mod ;
    }
    bool flag = true ;
    if(th == ph) cout<< 0 << endl,flag = false ;
    ll basepo = 1 ;
    for(int i=0; i<m-1; i++){
        basepo *= base ;
        basepo %= mod ;
    }

    for(int i=m; i<n; i++){
        th = th - (text[i-m]-'a'+1)*basepo ;
        th %= mod ;
        th = (th + mod)%mod ;
        th = th*base + (text[i]-'a'+1) ;
        th %= mod ;

        if(th == ph) cout<< i-m+1 << endl,flag = false ;
    }
    if(flag) cout<< endl ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll n ;
    while(cin>> n){
        string pat,text ;
        cin>> pat >> text ;
        matchPat(text,pat) ;
    }

    return 0;
}


