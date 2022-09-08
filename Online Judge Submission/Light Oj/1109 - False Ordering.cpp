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

bool cmp(pii a,pii b){
    if(a.ss < b.ss) return true ;
    else if(a.ss > b.ss) return false ;
    return a.ff > b.ff ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    vector<pii> arr(1001) ;
    for(int i=1; i<1001; i++){
        arr[i].ff = i ;
        arr[i].ss = 0 ;
    }
    for(int i=1; i<1001; i++)
        for(int j=i; j<1001; j+=i)
            arr[j].ss++ ;
    sort(all(arr),cmp) ;
    int t,cs=0 ;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;
        Case ;
        cout<< arr[n].ff << endl ;
    }

    return 0;
}



