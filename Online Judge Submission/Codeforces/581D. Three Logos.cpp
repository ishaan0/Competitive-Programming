#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;


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
#define     PI                  3.1415926535897932384
#define     pf                  printf
#define     sf                  scanf
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

const double eps = 1e-9 ;
/*
int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
int const drH[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
int const dcH[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;
*/

pii a[2],b[2],c[2] ;
int type ;
pair<pii ,char > ch[3] ;

bool isValid(){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                if((a[i].ff==b[j].ff && a[i].ff==c[k].ff) && (a[i].ss+b[j].ss+c[k].ss)==a[i].ff) type = 1 ;
                else if(a[i].ff==(b[j].ff+c[k].ff) && b[j].ss==c[k].ss && (a[i].ss+b[j].ss)==a[i].ff) type = 2 ;
                else if(b[j].ff==(a[i].ff+c[k].ff) && a[i].ss==c[k].ss && (a[i].ss+b[j].ss)==b[j].ff) type = 2 ;
                else if(c[k].ff==(b[j].ff+a[i].ff) && b[j].ss==a[i].ss && (a[i].ss+c[k].ss)==c[k].ff) type = 2 ;
                if(type != 0){
                    ch[0] = mp(mp(a[i].ff,0),'A') ;
                    ch[1] = mp(mp(b[j].ff,0),'B') ;
                    ch[2] = mp(mp(c[k].ff,0),'C') ;
                    return true ;
                }
            }
        }
    }
    return false ;
}

bool cmp(pair<pii,char> x, pair<pii,char> y){
    return x.ff.ff > y.ff.ff ;
}

void solve(){

    cin>>a[0].ff>>a[1].ff>>b[0].ff>>b[1].ff>>c[0].ff>>c[1].ff ;
    a[0].ss = a[1].ff ;
    a[1].ss = a[0].ff ;
    b[0].ss = b[1].ff ;
    b[1].ss = b[0].ff ;
    c[0].ss = c[1].ff ;
    c[1].ss = c[0].ff ;

    if(!isValid()){
        cout<< "-1" << endl ;
        return ;
    }

    if(ch[0].ff.ff == a[0].ff) ch[0].ff.ss = a[1].ff ;
    else ch[0].ff.ss = a[0].ff ;
    if(ch[1].ff.ff == b[0].ff) ch[1].ff.ss = b[1].ff ;
    else ch[1].ff.ss = b[0].ff ;
    if(ch[2].ff.ff == c[0].ff) ch[2].ff.ss = c[1].ff ;
    else ch[2].ff.ss = c[0].ff ;
    sort(ch,ch+3,cmp) ;

    cout<< ch[0].ff.ff << endl ;
    if(type == 1){
        for(int id=0; id<3; id++){
            for(int i=0; i<ch[id].ff.ss; i++){
                for(int j=0; j<ch[id].ff.ff; j++)
                    cout<< ch[id].ss ;
                cout<< endl ;
            }
        }
    }
    else{
        for(int i=0; i<ch[0].ff.ss; i++){
            for(int j=0; j<ch[0].ff.ff; j++)
                cout<< ch[0].ss ;
            cout<< endl ;
        }
        for(int i=0; i<ch[1].ff.ss; i++){
            for(int j=0; j<(ch[1].ff.ff+ch[2].ff.ff); j++){
                if(j<ch[1].ff.ff) cout<< ch[1].ss ;
                else cout<< ch[2].ss ;
            }
            cout<< endl ;
        }
    }

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


