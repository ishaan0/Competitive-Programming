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
        string str ;
        cin>> str ;
        int used[30] ;
        char side[110] ;
        memset(used,0,sizeof(used)) ;
        for(int i=0; i<110; i++) side[i] = '0' ;
        bool flag = true ;
        int cur = 50,next=1;
        foreach(str){
            if(!used[value-'a']){
                cur += next ;
                if(side[cur] != '0'){
                    flag = false ;
                    break ;
                }
                side[cur] = value ;
                used[value-'a'] = 1 ;
            }
            else{
                if(side[cur+1] == value) cur++,next = 1 ;
                else if(side[cur-1]==value) cur--,next = -1 ;
                else{
                    flag = false ;
                    break ;
                }
            }
        }

        if(!flag){
            cout<< "NO" <<endl ;
            continue ;
        }

        cout<< "YES" << endl ;
        for(int i=0; i<110; i++)
            if(side[i] != '0') cout<< side[i] ;
        for(int i=0; i<=25; i++)
            if(!used[i]) cout<< (char)(i+'a') ;
        cout<< endl ;
    }

    return 0;
}
