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

ll const row = 6 ;
ll const col = 6 ;
ll a1,a2,b1,b2,c1,c2,mod ;
ll f0,f1,f2,g0,g1,g2,q;


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
            mat[1][0]=mat[2][1]=mat[4][3]=mat[5][4] = 1 ;
            mat[0][0] = a1 ;
            mat[0][1] = b1 ;
            mat[0][5] = c1 ;
            mat[3][3] = a2 ;
            mat[3][4] = b2 ;
            mat[3][2] = c2 ;
        }
    }
    matrix operator*(const matrix b) const{
        matrix ans = matrix(0) ;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                for(int k=0; k<col; k++)
                ans.mat[i][j] = (ans.mat[i][j]+ mat[i][k]*b.mat[k][j]) % mod ;
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


pair<ll,ll> F(ll n){
    if(n==0) return pair<ll,ll>(f0%mod,g0%mod) ;
    if(n==1) return pair<ll,ll>(f1%mod,g1%mod) ;
    if(n==2) return pair<ll,ll>(f2%mod,g2%mod) ;
    matrix ans(2) ;
    ans = ans^(n-2) ;
    ll ans1 = ((ans.mat[0][0]*f2)%mod + (ans.mat[0][1]*f1)%mod +(ans.mat[0][5]*g0)%mod +
               (ans.mat[0][2]*f0)%mod + (ans.mat[0][3]*g2)%mod +(ans.mat[0][4]*g1)%mod)%mod ;
    ll ans2 = ((ans.mat[3][3]*g2)%mod + (ans.mat[3][4]*g1)%mod +(ans.mat[3][2]*f0)%mod +
               (ans.mat[3][0]*f2)%mod + (ans.mat[3][1]*f1)%mod +(ans.mat[3][5]*g0)%mod)%mod ;
    return pair<ll,ll>(ans1,ans2) ;
}


//#define DEBUG
int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t , cs= 0 ;
    scanf("%d",&t) ;

    while(t--){
        scanf("%lld%lld%lld",&a1,&b1,&c1) ;
        scanf("%lld%lld%lld",&a2,&b2,&c2) ;
        scanf("%lld%lld%lld",&f0,&f1,&f2) ;
        scanf("%lld%lld%lld",&g0,&g1,&g2) ;
        scanf("%lld%lld",&mod,&q) ;
        printf("Case %d:\n",++cs) ;
        while(q--){
            ll n ;
            scanf("%lld",&n) ;
            pair<ll,ll> ans = F(n) ;
            printf("%lld %lld\n",ans.ff,ans.ss) ;
        }
    }


    return 0;
}

