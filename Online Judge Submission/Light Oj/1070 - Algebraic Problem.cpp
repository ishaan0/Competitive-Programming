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
#define     Case                cout<< "Case "<< ++cs << ": "
#define     inf                 LONG_LONG_MIN
#define     INF                 LONG_LONG_MAX
#define     mp                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

//typedef     long long                   ll ;
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

#define ll ull
ll const row = 3 ;
ll const col = 3 ;
ll p,q,n ;


struct matrix{
    ll mat[row][col] ;
    matrix(){}
    matrix(int type){
        memset(mat,0,sizeof mat) ;
        if(type == 1){
            for(int i=0,j=0; i<row&&j<col; i++,j++)
                mat[i][j] = 1 ;
        }
        else if(type == 2){
            mat[1][0] = mat[2][1] = 1 ;
            mat[0][0] = p ;
            mat[0][1] = (-1)*q ;
        }
    }
    matrix operator*(const matrix b) const{
        matrix ans = matrix(0) ;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                for(int k=0; k<col; k++)
                ans.mat[i][j] = (ans.mat[i][j]+ mat[i][k]*b.mat[k][j]) ;
        return ans ;
    }
    matrix operator^(int p){
        matrix res(1) ;
        matrix x = *this ;
        while(p){
            if(p&1)
                res = res * x ;
            p >>= 1 ;
            x = x * x ;
        }
        return res ;
    }
};

ll func(ll n){
    if(n==0) return 2 ;
    matrix ans(2) ;
    ans = ans^(n-1) ;
    ll tot = (ans.mat[0][0]*p + ans.mat[0][1]*2) ;
    return tot ;
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t ,cs=0 ;
    scanf("%d",&t) ;

    while(t--){
        scanf("%llu%llu%llu",&p,&q,&n) ;
        ll ans = func(n) ;
        printf("Case %d: %llu\n",++cs,ans) ;
    }


    return 0;
}

