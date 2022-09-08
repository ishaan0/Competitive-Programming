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
    cin>> t;

    while(t--){
        int n ;
        string str ;
        cin>> n >> str ;
        map<pii, int> m ;
        int x=0,y=0 ;
        int lo=-1, hi=-1,mn= INT_MAX;
        m[mk(0,0)] = 0 ;
        for(int i=0; i<n; i++){
            if(str[i] == 'L') x-- ;
            else if(str[i] == 'R') x++ ;
            else if(str[i] == 'U') y-- ;
            else if(str[i] == 'D') y++ ;
            int right = i+1 ;

            if(m.find(mk(x,y)) != m.end()){
                int left = m[mk(x,y)] ;
                int dis = right - left ;
                if(dis<mn){
                    mn = dis ;
                    lo = left+1 ;
                    hi = right ;
                }

            }
            m[mk(x,y)] = right ;

        }

        if(lo == -1) cout<< "-1" << endl ;
        else cout<< lo << " " << hi << endl ;


    }


    return 0;
}
