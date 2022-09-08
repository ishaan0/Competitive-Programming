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

    int n ;
    cin>> n ;
    vector<int> me(n),frnd(n) ;
    foreach(me)
        cin>> value ;
    foreach(frnd)
        cin>> value ;

    bool flag = false ;
    int p1=0,p2=0 ;
    for(int i=0; i<n; i++){
        if(me[i] == 1 && frnd[i] == 0) p1++ ;
        if(frnd[i] == 1 && me[i] == 0) p2++ ;
    }
    if(p1== 0) flag = true ;

    if(flag){
        cout<< "-1" << endl ;
        return 0 ;
    }
    int ans = (p2+1)/p1 ;
    if((p2+1)%p1 != 0) ans++ ;

    cout<< ans << endl ;



    return 0;
}

