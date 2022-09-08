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

    int t ;
    cin>>t ;

    while(t--){
        string s,r ;
        cin>> s >> r ;
        ll cnt=1,i=0,n=s.size();
        while(i<n && s[i]==r[i]) i++ ;

        ll prv = i ;
        i++ ;
        vector<ll> dis ;
        while(i<n){
            if(s[i] != r[i]){
                cnt++ ;
                dis.pb(i-prv-1) ;
                prv = i ;
            }
            i++ ;
        }

        ll ans = cnt*cnt ;
        ll k = cnt ;
        sort(all(dis)) ;
        foreach(dis){
            k-- ;
            cnt += value ;
            ll temp = k*cnt ;
            ans = min(ans,temp) ;
        }

        if(s == r) cout<< "0" << endl ;
        else cout<< ans << endl ;

    }


    return 0;
}


