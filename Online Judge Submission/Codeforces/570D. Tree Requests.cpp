/*
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

PBDS
*x.find_by_order(pos) ----> returns the value at "pos" index in the set 0-based
x.order_of_key(value)     ----> returns the position of "value" in the set 0-based

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
using namespace std;



#define     FastRead            ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     _flush              cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     CLR(cont)           memset(cont, 0, sizeof cont)
#define     NEG(cont)           memset(cont, -1, sizeof cont)
#define     SZ(cont)            (int)(cont).size()
#define     SQR(x)              ((x) * (x))
#define     Case                cout<< "Case "<< ++cs << ": "
#define     PI                  acos(-1.0)
#define     mp                  make_pair
#define     pb                  push_back
#define     pob                 pop_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;
typedef     pair <ll , ll >             pll ;

/** Debugging Tool **/
TS void show(const T& v) { cerr << v << ' ' ;}
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
const ll mod = 1e9+7 ;

/** Tricks for hash_map **//*
struct custom_hash {
    static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    size_t operator()(uint64_t x) const{static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+FIXED_RANDOM);}
    size_t operator()(pair<uint64_t,uint64_t> x) const{static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);}
};
m.reserve(1024) ;
m.max_load_factor(0.25) ;*/
/** Tricks ends **/

/** Functions Start **//*
TP inline F setBit(F mask, S pos) { return mask |= ((F)1 << pos) ; }
TP inline bool getBit(F mask, S pos) { return (bool)(mask & ((F)1 << pos)) ; }
TP inline F resetBit(F mask, S pos) { return mask &= (~((F)1 << pos)) ; }
TP inline F toggleBit(F mask, S pos){ return mask ^= ((F)1 << pos) ; }

ll egcd(ll a,ll b,ll &x,ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1;ll gcd=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return gcd;}
ll bigMod(ll a,ll b){a%=mod;ll res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}

inline ll modAdd(ll _a,ll _b){if(_a<0){_a+=mod;}if(_b<0){_b+=mod;}if(_a+_b>mod)return (_a+_b-mod);return (_a + _b);}
inline ll modMul(ll _a,ll _b){if(_a<0){_a+=mod;}if(_b<0){_b+=mod;}return (_a*_b)%mod;}
inline ll modInv(ll a){ return bigMod(a,mod-2) ; }*/
/** Functions End **/

/** Direction Array **//*
const int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
const int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;
const int drK[] = { 2, 1, -1, -2, -2, -1, 1, 2 } ;
const int dcK[] = { 1, 2, 2, 1, -1, -2, -2, -1 } ;*/
/** Direction Array ends **/

const ll lim = 5e5 + 5 ; 

int n, m, t ;
string str ;
vector<int> adj[lim] ;
vector<pii > query[lim] ;
int order[lim], sbtr[lim], vrtx[lim], dept[lim], ans[lim] ;

void dfs_1(int u,int p, int d){
    dept[u] = d ;
    sbtr[u] = 1 ;
    order[u] = t , vrtx[t] = u , t++ ;
    for(int v: adj[u]){
        if(v == p) continue ;
        dfs_1(v, u, d+1) ;
        sbtr[u] += sbtr[v] ;
    }
}

int cnt[lim][30] , okk[lim] ;

void dfs_2(int u,int p,int keep){
    int mx = -1, bg = -1 ;
    for(int v: adj[u]){
        if(v == p) continue ;
        if(sbtr[v] > mx){
            mx = sbtr[v] ;
            bg = v ;
        }
    }

    for(int v: adj[u]){
        if(v == p || v == bg) continue ;
        dfs_2(v, u, 0) ;
    }
    if(bg != -1) dfs_2(bg, u, 1) ;

    for(int v: adj[u]){
        if(v == p || v == bg) continue ;
        for(int i = order[v]; i < order[v] + sbtr[v]; i++){
            int x = vrtx[i] ;
            int d = dept[x] ;
            cnt[d][ str[x]-'a' ]++ ;
            if(cnt[d][ str[x]-'a' ] & 1) okk[d]++ ;
            else okk[d]-- ;
        }
    }
    cnt[ dept[u] ][ str[u]-'a' ]++ ;
    if(cnt[ dept[u] ][ str[u]-'a' ] & 1) okk[ dept[u] ]++ ;
    else okk[ dept[u] ]-- ;

    for(pii x: query[u]){
        int h = x.ff , idx = x.ss ;
        ans[idx] = (okk[h] > 1) ? 0 : 1 ;
    }

    if(!keep){
        for(int i= order[u]; i<order[u]+sbtr[u]; i++){
            int x = vrtx[i] ;
            int d = dept[x] ;
            cnt[d][ str[x]-'a' ] = 0 ;
            okk[d] = 0 ;
        }
    }
}


int solve(){
    cin>> n >> m ;
    for(int i=2; i<=n; i++){
        int p ;
        cin>> p ;
        adj[i].pb(p) ;
        adj[p].pb(i) ;
    }
    cin>> str ;
    str = "#" + str ;

    for(int i=1; i<=m; i++){
        int u, h ;
        cin>> u >> h ;
        query[u].pb({h, i}) ;
    }

    dfs_1(1, -1, 1) ;
    dfs_2(1, -1, 0) ;

    for(int i=1; i<=m; i++){
        if(ans[i]) cout<< "Yes\n" ;
        else cout<< "No\n" ;
    }

    return 0 ;
}


int main()
{
    FastRead ;
    int t = 1,cs = 0 ;
    //cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}