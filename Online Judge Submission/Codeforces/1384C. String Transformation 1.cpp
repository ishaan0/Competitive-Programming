#include<bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;

template <typename PB>
using ordered_set = tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> ;
*/

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &val: cont)
#define     dbg(args...)        do {   cerr << #args << "-> " ;  show(args); } while(0); cerr<< endl ;
#define     TS                  template < typename T >
#define     TP                  template < typename F, typename S >
#define     TM                  template<typename T1, typename... T2>
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     memz(cont)          memset(cont, 0, sizeof cont)
#define     memn(cont)          memset(cont, -1, sizeof cont)
#define     Case                printf("Case %d: ",++cs)
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
typedef     pair <ll , ll >             pll ;

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



int solve(){
    int n ;
    string str1, str2 ;
    cin>> n >> str1 >> str2 ;
    
    vector<bool> check(26) ;
    bool flag = false ;

    for(int i=0; i<n; i++){
        if(str1[i] > str2[i]){
            flag = true ;
            break ;
        }
        else if(str1[i] < str2[i]){
            int id = str2[i] - 'a' ;
            check[id] = true ;
        }
    }
    
    if(flag) return cout<< "-1" << endl, 0 ;

    vector<int> pos(26) ;
    for(int i=0; i<26; i++)
        pos[i] = i ;

    int  ans = 0 ;
    for(int i=0; i<26; i++){
        if(!check[i]) continue ;

        vector<bool> temp(26) ;
        int cnt = 0 ;
        for(int j=0; j<n; j++){
            if(str2[j] == (char)(i+'a') && str1[j] != str2[j]){
                int id = pos[ str1[j]-'a' ] ;
                if(temp[id]) continue ;
                cnt++ ;
                temp[id] = 1 ;
            }
        }

        for(int j=0; j<26; j++){
            for(int k=0; k<26; k++){
                if(temp[ pos[j] ])
                    pos[j] = i ;
            }
        }
    
        ans += cnt ;
        
    }

    cout<< ans << "\n" ;

    return 0 ;
}


int main()
{
    //Boost ;
    int t = 1,cs = 0 ;
    //sf("%d",&t) ;
    cin>> t ;
    while(t--){
        //Case ;
        solve() ;
    }

    return 0;
}
