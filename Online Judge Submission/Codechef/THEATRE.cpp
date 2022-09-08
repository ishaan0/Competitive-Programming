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

/// NOt solved ....

int arr[4][4] ;
int n;
unordered_map<string,int> row ;
unordered_map<int,int> col ;

bool taken[4],fine[4],check[4][4];

int func(int time){
    if(time >= 4) return 0 ;

    int ans = -1 ;
    for(int i=0; i<4; i++){
        if(!taken[i] && arr[i][time]!=0){
            taken[i] = 1 ;

            int temp = ans ;
            int val = arr[i][time] ;
            //cout<< "de-> "<< time << " " <<i <<endl;
            //cout<<"che-> "<<ans<<" "<<arr[i][time] <<endl;
            ans = max(ans,(func(time+1)+arr[i][time])) ;
            //cout<< "after-> " << time << " " << i << endl ;
            //cout<< "ans-> " << ans << endl ;
            if(ans >= temp){
                for(int k=0; k<4; k++){
                    if(k!=i) check[k][time] = 0 ;
                }
            }
            taken[i] = 0 ;
        }
    }

    if(ans == -1){
        ans = max(0,func(time+1)) ;
        fine[time] = 1 ;
    }
    else fine[time] = 0 ;

    return ans ;

}



//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    row["A"] = 0 ;
    row["B"] = 1 ;
    row["C"] = 2 ;
    row["D"] = 3 ;
    col[3] = 0 ;
    col[6] = 1 ;
    col[9] = 2 ;
    col[12] = 3 ;

    int t,ans=0;
    cin>> t;
    while(t--){
        cin>> n ;
        memset(arr,0,sizeof(arr)) ;
        memset(taken,0,sizeof(taken)) ;
        memset(fine,0,sizeof(fine)) ;
        memset(check,0,sizeof(check)) ;
        for(int i=0; i<n; i++){
            string str ;
            int time ;
            cin>> str >> time ;
            int r=row[str] ;
            int c=col[time] ;
            arr[r][c]++ ;
        }

       int sum = func(0) ;
       sum = 0 ;
       int amt[4] = {100,75,50,25} ;
       vector<int> people ;
       for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(check[i][j]) people.pb(arr[i][j]) ;
        sort(rall(people)) ;
       //cout<< "de-> " << people.size() << endl ;
       for(int i=0; i<people.size(); i++)
            sum += (people[i]*amt[i]) ;
       for(int i=0; i<4; i++)
            if(fine[i]) sum -= 100 ;
       cout<< sum << endl ;
       ans += sum ;
    }

    cout<< ans << endl ;

    return 0;
}


