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
    cin>> t ;

    while(t--){
        vector<string> str(10) ;
        for(int i=1; i<=9; i++)
            cin>> str[i] ;

        str[1][0] = (str[1][0] == '1') ? '2' : '1' ;
        str[4][1] = (str[4][1] == '1') ? '2' : '1' ;
        str[7][2] = (str[7][2] == '1') ? '2' : '1' ;
        str[2][3] = (str[2][3] == '1') ? '2' : '1' ;
        str[5][4] = (str[5][4] == '1') ? '2' : '1' ;
        str[8][5] = (str[8][5] == '1') ? '2' : '1' ;
        str[3][6] = (str[3][6] == '1') ? '2' : '1' ;
        str[6][7] = (str[6][7] == '1') ? '2' : '1' ;
        str[9][8] = (str[9][8] == '1') ? '2' : '1' ;

        for(int i=1; i<=9; i++)
            cout<< str[i] << endl ;
    }


    return 0;
}


