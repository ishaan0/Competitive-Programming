#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs <<": "
#define     inf                 LLONG_MIN
#define     INF                 LLONG_MAX
#define     mp                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

/** Debugging Tool **/
TS void show(const T& v) {    cerr << v << ' ' ;}
TM void show(const T1& first,const T2&... rest){show(first);show(rest...);}
TP ostream& operator<<(ostream& os,const pair<F,S>& p){return os<<"("<<p.ff<<", "<<p.ss<<")";}
TS ostream& operator<<(ostream& os,const vector<T>& v){os << "{"; typename vector< T >::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if( it != v.begin() )os<<", ";os<<*it;}return os<<"}";}
TS ostream& operator<<(ostream& os,const set<T>& v){os<<"[";typename set<T>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
TP ostream& operator<<(ostream& os,const map<F,S>& v){os<<"[";typename map<F,S>::const_iterator it;
    for(it=v.begin();it!=v.end();it++){if(it!=v.begin())os<<", ";os<<it->ff<<" = "<<it->ss;}return os<<"]";}
/** Ends **/

bool mark[1005] ;
int cnt[26] ;

bool isPrime(int n){
    if(n<2) return false ;
    for(int i=2; i*i<=n; i++)
        if(n%i==0) return false ;
    return true ;
}

void solve(){
    bool flag = false ;
    string str ,temp="#" ;
    cin>> str ;
    int sz = str.size(),frq = 0,uni = 0;
    str = "#" + str ;

    for(int i=2; i<=sz; i++){
        if(isPrime(i)){
            if(i*2>sz) uni++ ;
            else{
                for(int j=i; j<=sz; j+=i)
                    if(!mark[j]){
                        frq++ ;
                         mark[j] = true ;
                    }
            }
        }
    }

    for(int i=1; i<=sz; i++){
        cnt[str[i]-'a']++ ;
        temp = "#"+temp ;
    }

    char same ;
    for(int i=0; i<26; i++)
    if(cnt[i] >= frq){
        flag = true ;
        same = (char)i + 'a' ;
        cnt[i] -= frq ;
        break ;
    }
    //dbg(flag,frq) ;
    string st = "" ;
    for(int i=0; i<26; i++){
        for(int j=0; j<cnt[i]; j++) st += (char)i+'a' ;
    }
    //dbg(st,same) ;
    if(st.size() < uni) flag = false ;
    if(flag){
        cout<< "YES" << endl ;
        for(int i=2; i<=sz; i++){
            if(isPrime(i) && frq){
                if(i*2<=sz)
                for(int j=i; j<=sz; j+=i)
                    temp[j] = same ;
            }
        }
        for(int i=1; i<=sz; i++)
        if(temp[i] == '#'){
            temp[i] = st.back() ;
            st.pop_back() ;
        }
        for(int i=1; i<=sz; i++)
            cout<< temp[i] ;
        cout<< endl ;
    }
    else cout<< "NO" << endl ;

}


int main()
{
    Boost;

    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t = 1,cs = 0 ;
    //cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}


