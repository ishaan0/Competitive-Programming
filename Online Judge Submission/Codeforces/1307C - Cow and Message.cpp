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

    string str ;
    cin>> str ;
    int sz = str.size() ;
    int rev[sz+5][28] ;
    memset(rev,0,sizeof(rev)) ;

    ll mx = -1 ;
    ll cnt[28] ;
    memset(cnt,0,sizeof(cnt)) ;

    for(int i=0; i<sz; i++){
        int idx = str[i]-'a' ;
        cnt[idx]++ ;
        mx = max(mx,cnt[idx]) ;
    }

    for(int i=sz-1; i>=0; i--){
        if(i!=sz-1){
            for(int j=0; j<26; j++)
                rev[i][j] = rev[i+1][j] ;
        }
        int idx = str[i]-'a' ;
        rev[i][idx]++ ;
    }


    map< pair<char,char> ,ll> m ;
    for(int i=0; i<sz-1; i++){
        for(int j=0; j<26; j++){
            pair<char,char> temp = mk(str[i],((char)j+'a')) ;
            ll ed = rev[i+1][j] ;
            m[temp] += (ed) ;
        }
    }

    foreach(m){
        mx = max(mx,value.ss) ;
    }

    cout<< mx << endl ;

    return 0;
}

