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


char func(char a,char b){
    if(a > b) swap(a,b) ;
    if(a=='B' && b=='G') return 'R' ;
    else if(a=='B' && b=='R') return 'G' ;
    else if(a=='G' && b=='R') return 'B' ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n ;
    string str ;
    cin>> n >> str ;
    
    vector<int> r(n),g(n),b(n) ;
    if(str[n-1] == 'R') r[n-1] = 1 ;
    else if(str[n-1] == 'G') g[n-1] = 1 ;
    else if(str[n-1] == 'B') b[n-1] = 1 ;
    for(int i=n-2; i>=0; i--){
        r[i] = r[i+1] ;
        g[i] = g[i+1] ;
        b[i] = b[i+1] ;
        if(str[i] == 'R') r[i]++;
        else if(str[i] == 'G') g[i]++ ;
        else if(str[i] == 'B') b[i]++ ;
    }
    
    ll sum = 0 ;
    for(int i=0; i<n; i++){
        ll temp = 0;
        for(int j=i+1; j<n; j++){
            if(str[i] == str[j]) continue ;
            char ch = func(str[i],str[j]) ;
            if(ch == 'R') temp += r[j] ;
            else if(ch == 'G') temp += g[j] ;
            else if(ch == 'B') temp += b[j] ;
            int diff = j-i ;
            if(j+diff <n && str[j+diff] == ch) temp-- ;
        }
        sum += temp ;
    }
    
    cout<< sum << endl ;

    return 0;
}


