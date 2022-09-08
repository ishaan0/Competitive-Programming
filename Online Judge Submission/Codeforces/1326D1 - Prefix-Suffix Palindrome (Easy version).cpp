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
        string str ;
        cin>> str ;
        deque<char> tt1,tt2 ;
        int i=0 , j=str.size()-1 ;
        while(i<=j){
            if(str[i] != str[j]){
                break ;
            }
            else if(str[i] == str[j]){
                if(i==j)
                    tt1.push_back(str[i]) ;
                else{
                    tt1.push_back(str[i]) ;
                    tt2.push_front(str[j]) ;
                }
                i++,j-- ;
            }
        }

        string temp1="",temp2="" ;
        while(!tt1.empty()){
            temp1 += tt1.front() ;
            tt1.pop_front() ;
        }
        while(!tt2.empty()){
            temp2 += tt2.front() ;
            tt2.pop_front() ;
        }

        string jj1="",jj2="" ;
        for(int k=j; k>=i; k--){
            bool flag = true ;
            for(int lo=i,hi=k; lo<=hi; lo++,hi--)
            if(str[lo] != str[hi]){
                flag = false ;
                break ;
            }
            if(flag){
                for(int lo=i; lo<=k; lo++)
                    jj1 += str[lo] ;
                break ;
            }
        }

        for(int k=i; k<=j; k++){
            bool flag = true ;
            for(int lo=k,hi=j; lo<=hi; lo++,hi--)
            if(str[lo] != str[hi]){
                flag = false ;
                break ;
            }
            if(flag){
                for(int lo=k; lo<=j; lo++)
                    jj2 += str[lo] ;
                break ;
            }
        }

        string ans = "" ;
        ans += temp1 ;
        if(jj1.size() > jj2.size())
            ans += jj1 ;
        else ans += jj2 ;
        ans += temp2 ;
        cout<< ans << endl ;

    }

    return 0;
}

