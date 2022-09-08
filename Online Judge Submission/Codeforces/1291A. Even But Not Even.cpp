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
        int n ;
        cin>> n ;
        string str ;
        cin>> str ;

        bool flag = true ;
        int sum=0 ,odd=0,even=0;
        for(int i=0; i<n; i++){
            sum += str[i]-'0' ;
            if((str[i]-'0')%2==0) even++ ;
            else odd++ ;
        }

        if(odd==0 || odd==1){
            cout<< "-1" << endl ;
            continue ;
        }


        if(sum%2==0){
            int i=n-1 ;
            while(i>=0 && (str[i])%2==0)
                str[i] = '*',i--;
            flag = false ;
        }

        if(flag){
            flag = false ;
            int i=n-1 ;
            while(i>=0 && (str[i])%2==0)
                str[i] = '*',i--;

            for(; i>=0; i--)
            if((str[i]-'0')%2 != 0){
                if(flag){
                    str[i] = '*' ;
                    break ;
                }
                flag = true ;
            }
        }
        flag = true ;
        for(int i=0; i<n; i++){
            if(str[i] != '0') flag = false ;
            else if(flag) str[i] = '*' ;
            else break ;
        }

        for(int i=0; i<n; i++)
            if(str[i]!='*') cout<<str[i] ;
        cout<< endl ;

    }


    return 0;
}
