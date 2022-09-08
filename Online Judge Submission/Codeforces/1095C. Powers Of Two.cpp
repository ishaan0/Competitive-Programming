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

    int n,k ;
    cin>> n >> k ;

    if(n<k){
        cout<< "NO" << endl ;
        return 0 ;
    }

    priority_queue<int> pq ;
    int temp = n ,pos=0;
    while(temp > 0){
        if(temp&1)
            pq.push(1<<pos) ;
        pos++ ;
        temp /= 2;
    }
    if(pq.size() > k){
        cout<< "NO" << endl ;
        return 0 ;
    }

    while(pq.size() < k){
        int tp = pq.top() ;
        pq.pop() ;
        pq.push(tp/2) ;
        pq.push(tp/2) ;
    }
    cout<< "YES" << endl ;
    while(!pq.empty()){
        cout<< pq.top() << " " ;
        pq.pop() ;
    }
    cout<< endl ;

    return 0;
}

