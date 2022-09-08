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

    int k ;
    string str ;
    cin>> k >> str ;
    int sz = str.size() ;
    vector<int> one ;
    for(int i=0; i<sz; i++)
        if(str[i] == '1') one.pb(i+1) ;
    if(one.size() < k)
        return cout<< "0" << endl, 0 ;
    if(k == 0){
        ll ans = 0,prv = 0 ;
        for(int i=0; i<one.size(); i++){
            ll diff = one[i]-prv-1 ;
            ans += diff*(diff+1)/2 ;
            prv = one[i] ;
        }
        ll diff = sz-prv ;
        ans += diff*(diff+1)/2 ;
        cout<< ans << endl ;
        return 0 ;
    }

    ll cnt = 0 ;
    for(int i=0; i+k-1<one.size(); i++){
        ll left = 0, right = 0 ;
        if(i+k < one.size())
            right += one[i+k]-one[i+k-1] ;
        else right += sz - one[i+k-1] + 1 ;
        if(i-1>=0)
            left += one[i] - one[i-1] ;
        else left = one[i] ;

        cnt += left*right ;
    }

    cout<< cnt << endl ;

    return 0;
}


