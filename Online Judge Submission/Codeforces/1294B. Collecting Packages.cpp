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

bool cmp(pii a,pii b){
    if(a.ff != b.ff)
        return a.ff<b.ff ;
    return a.ss < b.ss ;
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
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;
        vector<pii> arr ;
        for(int i=0; i<n; i++){
            int x,y ;
            cin>> x >>y ;
            arr.pb(mk(x,y)) ;
        }
        //cout<<"de"<<endl ;
        sort(all(arr),cmp) ;
        bool flag = true ;
        vector<char> ans ;
        //cout<< "de"<<endl ;
        int x=0,y=0 ;
        for(int i=0; i<n; i++){
            if(arr[i].ff<x || arr[i].ss<y){
                flag = false ;
                break ;
            }
            int temp =x;
            while(temp<arr[i].ff)
                ans.pb('R'),temp++ ;
            temp = y ;
            while(temp<arr[i].ss)
                ans.pb('U'),temp++ ;

            x = arr[i].ff ;
            y = arr[i].ss ;

        }

        if(!flag) cout<< "NO" << endl ;
        else{
            cout<< "YES" << endl ;
            foreach(ans)
                cout<< value  ;
                cout<< endl ;
        }
    }

    return 0;
}
