#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;


#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     mp                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;
typedef     pair <ll , ll >             pll ;


const double eps = 1e-9 ;
const ll mod = 1e9+7 ;




#define     left     2*iter
#define     right    2*iter+1

const ll lim = 5e4 + 5 ; 

struct node{
    ll sum,pre,suf,ans ;
    node(){sum = pre = suf = ans = 0 ; }
    node(ll val){
        sum = val ;
        pre = suf = ans = val ;
    }
};

ll arr[lim] ;
node segtree[4 * lim] ;

node mrg(node lft,node rgt){
    node res ;
    res.sum = lft.sum + rgt.sum ;
    res.pre = max(lft.pre, lft.sum+rgt.pre) ;
    res.suf = max(rgt.suf, lft.suf+rgt.sum) ;
    res.ans = max({lft.ans, rgt.ans, lft.suf+rgt.pre}) ;
    return res ;
}
void build(ll iter,ll lo,ll hi){
    if(lo == hi){
        segtree[iter] = node(arr[lo]) ;
        return ;
    }
    ll mid = lo + (hi-lo)/2 ;
    build(left,lo,mid) ;
    build(right,mid+1,hi) ;
    segtree[iter] = mrg(segtree[left],segtree[right]) ;
}

node query(ll iter,ll lo,ll hi,ll qi,ll qj){
    if(qj < lo || qi > hi) return node(-1e9) ;   
    if(qi <= lo && hi <= qj)
        return segtree[iter] ;
    ll mid = lo + (hi - lo)/2 ;
    node L = query(left, lo, mid, qi, qj) ;
    node R = query(right, mid+1, hi, qi, qj) ;
    return mrg(L, R) ;
}

void update(ll iter,ll lo,ll hi,ll qi,ll val){
    if(qi < lo || qi > hi) return ;
    if(qi <= lo && hi <= qi){
        segtree[iter] = node(val) ;
        return ;
    }
    ll mid = lo + (hi-lo)/2 ;
    update(left, lo, mid, qi, val) ;
    update(right, mid+1, hi, qi, val) ;
    segtree[iter] = mrg(segtree[left], segtree[right]) ;
}



int solve(){
    int n ;
    cin>> n ;
    for(int i=1; i<=n; i++) cin>> arr[i] ;

    build(1,1,n) ;    

    int q ;
    cin>> q ;

    while(q--){
        ll tp,l,r ;
        cin>> tp >> l >> r ;
        if(tp){
            node res = query(1,1,n,l,r) ;
            cout<< res.ans << "\n" ;
        }
        else update(1,1,n,l,r) ;
    }


    return 0 ;
}


int main()
{
    Boost ;
    int t = 1,cs = 0 ;
    //cin>> t ;

    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}