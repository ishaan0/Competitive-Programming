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

int fact[105][105] ;

void factorize(int n){
    int temp = n ;
    for(int i=2; i*i<=n; i++){
        if(n%i!=0) continue ;
        int cnt = 0 ;
        while(n%i==0){
            cnt++ ;
            n/=i ;
        }
        fact[temp][i] = cnt ;
    }
    if(n>1) fact[temp][n]= 1 ;
}

void preCal(){
    for(int i=2; i<105; i++)
        factorize(i) ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif


    preCal() ;
    int t,cs=0;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;
        Case ;
        cout<< n << " =" ;
        for(int i=2; i<=n; i++){
            int cnt=0 ;
            for(int j=2; j<=n; j++)
                cnt += fact[j][i] ;
            if(cnt > 0){
                if(i != 2) cout<< " *" ;
                cout<< " " << i << " (" << cnt<< ")" ;
            }
        }
        cout<< endl ;
    }

    return 0;
}



