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
        int n,x=0,y=0;
        string str ;
        cin>> n >> str ;
        char last = 'A' ;
        for(int i=0; i<n; i++){
            if(str[i] == 'L' && last!='L' && last!='R')
                x-- ;
            else if(str[i] == 'R' && last!='L' && last!='R')
                x++ ;
            else if(str[i] == 'U' && last!='U' && last!='D')
                y++ ;
            else if(str[i] == 'D' && last!='U' && last!='D')
                y-- ;
            last = str[i] ;
        }

        cout<< x << " " << y << endl ;
    }


    return 0;
}

