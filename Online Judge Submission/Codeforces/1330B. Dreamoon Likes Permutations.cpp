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
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ;
    cin>>t ;

    while(t--){
        ll n ;
        cin>> n ;
        ll arr[n+5],pref[n+5],suf[n+5] ;
        bool frnt[n+5],bck[n+5] ;
        unordered_set<ll> s ;
        memset(pref,0,sizeof pref) ;
        memset(suf,0,sizeof suf) ;
        memset(frnt,0,sizeof frnt) ;
        memset(bck,0,sizeof bck) ;

        for(int i=1; i<=n; i++){
            cin>> arr[i] ;
            pref[i] = pref[i-1]+arr[i] ;
        }
        for(int i=n; i>=1; i--)
            suf[i] = suf[i+1]+arr[i] ;

        bool flag = false ;
        for(int i=1; i<=n; i++){
            if(s.count(arr[i]) || flag){
                flag = true ;
                frnt[i] = true ;
            }
            s.insert(arr[i]) ;
        }
        s.clear() ;
        flag = false ;
        for(int i=n; i>=1; i--){
            if(s.count(arr[i]) || flag){
                flag = true ;
                bck[i] = true ;
            }
            s.insert(arr[i]) ;
        }

        vector<pair<int,int> > ans ;
        for(int i=1; i<n; i++){
            ll sum1 = ((ll)i*(i+1))/2 ;
            ll sum2 = ((ll)(n-i)*(n-i+1))/2 ;
            if(sum1 == pref[i] && sum2 == suf[i+1]){
                if(!frnt[i] && !bck[i+1])
                    ans.pb(mk(i,n-i)) ;

            }
        }

        cout<< ans.size() << endl ;
        for(int i=0; i<ans.size(); i++)
            cout<< ans[i].ff <<" "<< ans[i].ss << endl ;
    }

    return 0;
}

