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

int const lim = 1e6+5 ;

int tree[lim] ;
int n,q ;

void update(int idx,int val){
    while(idx <= n){
        tree[idx] += val ;
        idx += (idx) & (-idx) ;
    }
}

int query(int idx){
    int sum = 0 ;
    while(idx > 0){
        sum += tree[idx] ;
        idx -= (idx) & (-idx) ;
    }
    return sum ;
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

        cin>> n >> q ;
        for(int i=1; i<=n; i++){
            int val ;
            cin>> val ;
            update(val,1) ;
        }

        while(q--){
            int k ;
            cin>> k ;
            if(k<0){
                k =(-1)*k ;
                int lo = 0, hi = n ;
                while(lo<hi){
                    int mid = lo+(hi-lo)/2 ;
                    if(query(mid) >= k)
                        hi = mid ;
                    else lo = mid+1 ;
                }
                update(lo,-1) ;
            }
            else
                update(k,1) ;
        }

        int ans = query(n) ;
        if(!ans) cout<< "0" << endl ;
        else {
            int lo = 1, hi = n ;
            while(lo<hi){
                int mid = lo+(hi-lo)/2 ;
                if(query(mid) >= ans)
                    hi = mid ;
                else lo = mid+1 ;
            }
            cout<< lo << endl ;
        }
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}
