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
        cin>>  n ;
        vector<int> arr(n) ;
        foreach(arr)
            cin>> value ;

        if(n==1){
            cout<<"Yes"<<endl;
            continue ;
        }
        bool flag= true ;
        int i=0,j=n-1 ;
        int st=0,ed=0 ;
        for(; i<j; i++,j--){
            if(arr[i]<st || arr[j]<ed){
                flag = false ;
                break ;
            }
            st++ ;
            ed++ ;

        }

        if(n&1){
            if(arr[i]<st && arr[i]<ed) flag = false ;
        }
        else{
            i-- ;
            j++ ;
            st-- ;
            ed-- ;
            if(arr[i] == arr[j] && arr[i]==ed&&arr[j]==st) flag = false ;
            //cout<< "de-> "<< arr[i] << " "<<arr[j]<<endl;
        }

        if(flag) cout<< "Yes" << endl ;
        else cout<< "No" << endl ;
    }


    return 0;
}
