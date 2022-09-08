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
#define mod 998244353
#define lim 200005




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
        string ans1="1",ans2="1" ;
        bool flag= true ;
        for(int i=1; i<n; i++){
            if(str[i] == '0'){
                ans1 += "0" ;
                ans2 += "0" ;
            }
            else if(str[i] == '1'){
                if(flag){
                    ans1 += "1" ;
                    ans2 += "0" ;
                    flag = false ;
                }
                else{
                    ans1 += "0" ;
                    ans2 += "1" ;
                }
            }
            else if(str[i] == '2'){
                if(flag){
                    ans1 += "1" ;
                    ans2 += "1" ;
                }
                else{
                    ans1 += "0" ;
                    ans2 += "2" ;
                }
            }
        }

        cout<< ans1 << endl ;
        cout<< ans2 << endl ;
    }

    return 0;
}

