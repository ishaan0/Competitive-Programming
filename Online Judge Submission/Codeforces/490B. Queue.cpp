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
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int n ;
    cin>> n ;

    vector<int> frnt(n),bck(n) ;
    unordered_map<int,int> next,prev;
    int start = 0 ;
    for(int i=0; i<n; i++){
        cin>> frnt[i] >> bck[i] ;
        next[frnt[i]] = bck[i] ;
        prev[bck[i]] = frnt[i] ;
    }
    sort(all(frnt)) ;
    sort(all(bck)) ;
    deque<int> arr1,arr2 ;
    unordered_set<int> s ;
    bool flag = false ;
    while(true){
        int temp = next[start] ;
        s.insert(start) ;
        int pos = lower_bound(all(frnt),temp)-frnt.begin() ;
        if(flag)
            arr1.push_back(start) ;
        else  flag=true ;
        if(temp == 0 )
            break ;
        if(pos==n || frnt[pos]!=temp){
            arr1.push_back(temp) ;
            break ;
        }
        start = temp ;
    }

    for(int i=0; i<n; i++)
        if(s.find(frnt[i]) == s.end()){
            start = frnt[i] ;
            break ;
        }
    int mem = start ;
    while(true){
        int temp = next[start] ;
        int pos = lower_bound(all(frnt),temp)-frnt.begin() ;
        arr2.push_back(start);

        if(temp == 0)
            break ;
        if(pos==n || frnt[pos]!=temp){
            arr2.push_back(temp) ;
            break ;
        }
        start = temp ;
    }

    start = next[mem] ;
    flag = false ;
    while(true){
        int temp = prev[start] ;
        int pos = lower_bound(all(bck),temp)-bck.begin() ;
        if(flag)
            arr2.push_front(temp) ;
        else flag = true ;
        if(temp == 0)
            break ;
        if(pos==n || bck[pos]!=temp){
            break ;
        }
        start = temp ;
    }

    int i=0,j=0,k=1 ;
    for(; i<arr1.size()&&j<arr2.size(); ){
        if(k&1){
            cout<< arr2[j] << " ";
            j++,k++ ;
        }
        else{
            cout<< arr1[i] << " " ;
            i++,k++ ;
        }
    }

    while(i<arr1.size())
        cout<< arr1[i++] << " " ;
    while(j<arr2.size())
        cout<< arr2[j++] << " " ;

    cout<< endl ;


    return 0;
}



