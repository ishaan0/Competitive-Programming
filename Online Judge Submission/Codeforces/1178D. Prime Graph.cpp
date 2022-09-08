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

vector<int> primes ;
bool mark[1020] ;
void seive(){
    int i,j,n=1010,lim=sqrt(n)+2 ;
    for(i=4; i<=n; i+=2)
        mark[i] = true ;
    primes.pb(2) ;
    mark[0] = mark[1] = true ;
    for(i=3; i<=n; i++){
        if(!mark[i]){
            primes.pb(i) ;
            if(i<=lim){
                for(j=i*i; j<=n; j+=2*i)
                    mark[j] = true ;
            }
        }
    }
}


//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    seive() ;
    int n ;
    cin>> n ;
    int pos = lower_bound(all(primes),n)-primes.begin() ;
    int pm = primes[pos] ;

    cout<< pm << endl ;
    for(int i=1; i<n; i++)
        cout<< i <<" "<< i+1 <<endl ;
    cout<< n <<" " << 1 <<endl ;
    if(pm != n){
        int rem= pm-n ;
        int lo=1,hi=3 ;
        int cnt = 0 ;
        for(int i=1; i<=rem; i++){
            cout<< lo << " " << hi << endl ;
            cnt++ ;
            lo++ ;
            hi++ ;
            if(cnt == 2){
                lo = hi ;
                hi += 2 ;
                cnt=0 ;
            }

        }
    }

    return 0;
}


