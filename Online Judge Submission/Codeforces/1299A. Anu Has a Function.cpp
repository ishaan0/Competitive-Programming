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
    vector<int> arr(n) ;
    bool bits[n+2][32] ;
    memset(bits,0,sizeof bits) ;

    for(int i=0; i<n; i++){
        cin>> arr[i] ;
        int temp = arr[i] ;
        for(int j=0; j<30; j++)
            bits[i][j] = temp%2, temp/=2 ;
    }

    int p= -1 ;
    for(int i=29; i>=0; i--){
        int cnt=0,tp=-1 ;
        for(int j=0; j<n; j++)
            if(bits[j][i]) cnt++ , tp=j;
        if(cnt == 1){
            p = tp ;
            cout<< arr[p] << " " ;
            break ;
        }
    }

    for(int i=0; i<n; i++)
        if(i != p)
        cout<< arr[i] << " " ;
    cout<< endl ;

    return 0;
}

