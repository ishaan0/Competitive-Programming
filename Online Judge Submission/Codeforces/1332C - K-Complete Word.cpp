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

    int t ;
    cin>> t ;

    while(t--){
        ll n,k ;
        string str ;
        cin>> n >> k >> str ;
        ll ans = 0, temp[k][26] ;
        memset(temp,0,sizeof temp) ;
        for(int i=0; i<k; i++){
            for(int j=i; j<n; j+=k)
                temp[i][str[j]-'a']++ ;
        }

        for(int i=0,j=k-1; i<=j; i++,j--){
            ll total = n/k ;
            ll mx = INT_MIN ;
            if(i!=j){
                total *= 2 ;
                for(int c=0; c<26; c++)
                    mx= max(temp[i][c]+temp[j][c],mx) ;
            }
            else{
                for(int c=0; c<26; c++)
                    mx= max(temp[i][c],mx) ;
            }
            ans += (total-mx) ;
        }

        cout<< ans  << endl ;

    }
    return 0;
}