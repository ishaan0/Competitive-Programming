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
const int lim = 1e6+5 ;

int zero2[lim] ;
int zero5[lim] ;

void func(ll n){
    ll cnt = 0 ;
    ll temp = n ;
    ll div = 2 ;
    while(temp/div){
        cnt += temp/div ;
        div *= 2 ;
    }
    div = 5 ;
    zero2[n] = cnt ;
    temp = n ;
    cnt = 0 ;
    while(temp/div){
        cnt += temp/div ;
        div *= 5 ;
    }
    zero5[n] = cnt ;
}

int f(int n,int num){
    int cnt= 0 ;
    while(n%num == 0){
        cnt++ ;
        n /= num ;
    }
    return cnt ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    for(int i=0; i<lim; i++)
        func(i) ;
    int t,cs=0 ;
    cin>> t ;

    while(t--){
        int n,r,p,q ;
        cin>> n >> r >> p >> q ;
        int two = zero2[n]-zero2[max(0,n-r)]-zero2[r]+(f(p,2)*q) ;
        int five = zero5[n]-zero5[max(0,n-r)]-zero5[r]+(f(p,5)*q) ;
        int ans = min(two,five) ;
        Case ;
        cout<< ans << endl ;
    }


    return 0;
}



