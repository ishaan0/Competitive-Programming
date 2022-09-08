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



//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n ,m ;
    cin>> n >> m ;

    if(n == m+1){
        while(n!=0 && m!=0){
            cout<< "01" ;
            n--,m-- ;
        }
        cout<< "0" << endl ;
        return 0 ;
    }
    if(n==1){
        if(m<=4){
            for(int i=0; i<min(m,2); i++,m--)
                cout<< "1" ;
            cout<< "0" ;
            while(m--) cout<< "1" ;
            cout<< endl ;
        }
        else cout<< "-1" << endl ;
        return 0 ;
    }
    if(n==2){
        if(m<=6){
            if(m<=2) cout<< "10" ;
            else cout<< "110" ;
            if(m<=3) cout<< "10" ;
            else cout<< "110" ;
            if(m==5) cout<< "1" ;
            else if(m==6) cout<< "11" ;
            cout<< endl ;
        }
        else cout<< "-1" << endl ;
        return 0 ;
    }

    if(n<=m && n*2+2 >= m){
        int cnt = m/n,lim = (m%n <= 2) ? 0 : m%n ;
        cnt++ ;
        string ans = "" ;
        for(int i=0; i<n; i++){
            if(i==lim) cnt-- ;
            for(int j=0; j<cnt; j++)
                ans += "1" ;
            ans += "0" ;

        }
        cnt = (m%n <= 2) ? m%n : 0 ;
        while(cnt--) ans += "1" ;
        cout<< ans << endl ;

    }
    else cout<< "-1" << endl ;


    return 0;
}


