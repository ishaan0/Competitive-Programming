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

vector<int> ans ;
const ll m1 = 1423172537 ;
const ll b = 71 ;

void matchStr(string text,string pat){
    int n = text.size(),m = pat.size() ;
    ll ph = 0,th = 0 ;
    for(int i=0; i<m; i++){
        ph = ph*b + (pat[i]-'a'+1) ;
        th = th*b + (text[i]-'a'+1) ;
        ph %= m1 ;
        th %= m1 ;
    }

    if(th == ph)
        ans.pb(1) ;
    ll baspo = 1 ;
    for(int i=0; i<m-1; i++){
        baspo *= b ;
        baspo %= m1 ;
    }

    for(int i=m; i<n; i++){
        th = th - (text[i-m]-'a'+1)*baspo ;
        th %= m1 ;
        th = (th+m1)%m1 ;
        th = th*b + (text[i]-'a'+1) ;
        th %= m1 ;
        if(th == ph) ans.pb(i-m+2) ;
    }
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>>t ;

    while(t--){
        ans.clear() ;
        string text,pat ;
        cin>> text >> pat ;
        matchStr(text,pat) ;
        if(ans.size() == 0){
            cout<< "Not Found" << endl << endl ;
            continue ;
        }
        cout<< ans.size() << endl ;
        for(int i=0; i<ans.size(); i++){
            if(i) cout<< " " ;
            cout<< ans[i] ;
        }
        cout<< endl << endl ;
    }

    return 0;
}


