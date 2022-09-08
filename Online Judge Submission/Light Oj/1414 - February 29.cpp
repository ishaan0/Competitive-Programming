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


bool isLeapYear(int y){
    if((y%400==0) || (y%100!=0 && y%4==0))
        return true ;
    return false ;
}

//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t,cs=0;
    cin>> t;

    while(t--){
        string m1,m2,comma ;
        ll d1,d2,y1,y2 ;
        cin>> m1 >> d1 >> comma >> y1 ;
        cin>> m2 >> d2>> comma >> y2 ;

        ll leapYear =((y2/4)-(y2/100)+(y2/400)) - ((y1/4)-(y1/100)+(y1/400)) ;

        if(isLeapYear(y1)){
            if(m1=="February" || m1=="January")
                leapYear++ ;
        }

        if(isLeapYear(y2)){
            if(m2=="January" || (m2=="February" && d2<29))
                leapYear-- ;
        }

        cout<< "Case "<< ++cs <<": " << leapYear << endl;
    }


    return 0;
}



