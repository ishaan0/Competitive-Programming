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

    int n,m ;
    cin>> n >> m ;
    bool used[n] ;
    memset(used,0,sizeof(used)) ;
    vector<string> str(n),rev;

    for(int i=0; i<n; i++){
        cin>> str[i] ;
        string temp = str[i] ;
        reverse(all(temp)) ;
        rev.pb(temp) ;
    }

    deque<string> st,ed ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!used[i] && i!=j){
                if(str[i] == rev[j]){
                    used[i] = true ;
                    used[j] = true ;
                    st.push_back(str[i]) ;
                    ed.push_front(str[j]) ;
                }
            }
        }
    }

    unordered_map<string,int> mm ;
    bool flag = false ;
    for(int i=0; i<n; i++){
        if(!used[i]){
            int sz = (str[i].size()) ;
            bool chk = true ;
            for(int j=0,k=sz-1; j<sz/2; j++,k--)
            if(str[i][j] != str[i][k]){
                chk = false ;
                break ;
            }
            if(chk){
                flag = true ;
                mm[str[i]]++ ;
            }
        }
    }

    string mid = "" ;
    int mx = 0 ;
    foreach(mm){
        if(value.ss >= mx){
            mid = value.ff ;
            mx = value.ss ;
        }
    }

    int ans = ((st.size())*2)*m ;
    if(flag) ans += (mid.size()) ;

    cout<< ans << endl ;
    foreach(st)
        cout<< value ;
    if(flag) cout<< mid ;
    foreach(ed)
        cout<< value ;
    cout<< endl ;



    return 0;
}

