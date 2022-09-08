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
#define     PI                  3.1415926535897932384
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


void solve(){
    int n,m,k ;
    cin>> n >> m >>  k ;
    vector<pii> arr,brr,crr,extra ;
    vector<int> index ;
    for(int i=0; i<n; i++){
        int a,b,c ;
        cin>> a >> b >> c ;
        if(b == 1 && c == 1)
            arr.pb(mp(a,i+1)) ;
        else if(b==1) brr.pb(mp(a,i+1)) ;
        else if(c==1) crr.pb(mp(a,i+1)) ;
        else extra.pb(mp(a,i+1)) ;
    }

    sort(all(arr)) ;
    sort(all(brr)) ;
    sort(all(crr)) ;
    sort(all(extra)) ;
    int a = arr.size() ;
    int b = brr.size() ;
    int c = crr.size() ;

//    dbg(arr) ;
//    dbg(brr) ;
//    dbg(crr) ;
//    dbg(extra) ;

    int i=0,j=0,p=0 ;
    ll ans = 0,cnt=0,books=0 ;
    /**for(; i<a&&j<b&&p<c&&cnt<k; ){
        int sum = brr[j].ff + crr[p].ff ;
        if(sum <= arr[i].ff && books+2<=m){
            ans += (ll)sum ;
            index.pb(brr[j].ss) ;
            index.pb(crr[p].ss) ;
            books += 2 ;
            j++, p++ ;
        }
        else if(books+1<=m){
            ans += arr[i].ff ;
            index.pb(arr[i].ss) ;
            books++ ;
            i++ ;
        }
        else break ;
        cnt++ ;
    }*/

    for(; i<a&&j<b&&p<c&&cnt<k; ){
        int sum = brr[j].ff + crr[p].ff ;
        if(((sum <= arr[i].ff)||(i+1<a&&cnt+2==k&&sum<=(arr[i].ff+arr[i+1].ff)))&&books+2 <= m){
            ans += (ll)sum ;
            index.pb(brr[j].ss) ;
            index.pb(crr[p].ss) ;
            books += 2 ;
            j++, p++ ;
        }
        else if(books+1<=m){
            ans += arr[i].ff ;
            index.pb(arr[i].ss) ;
            books++ ;
            i++ ;
        }
        else break ;
        cnt++ ;
    }

    ll A=cnt,B=cnt ;
    if(cnt<k && i==a){
        while(books+1<=m && j<b && A<k){
            ans += brr[j].ff ;
            index.pb(brr[j].ss) ;
            books++ ;
            j++, A++ ;
        }
        while(books+1<=m && p<c && B<k){
            ans += crr[p].ff ;
            index.pb(crr[p].ss) ;
            books++ ;
            p++, B++ ;
        }
    }
    else if(cnt<k && (j==b || p==c)){
        while(books+1<=m && i<a && cnt<k){
            ans += arr[i].ff ;
            index.pb(arr[i].ss) ;
            books++ ;
            i++, cnt++ ;
        }
    }

    if((A==k&&B==k) || cnt==k){
        ll rem = m-books,ee=0, e = extra.size();

        while((i<a||j<b||p<c||ee<e) && rem>0){
            ll val1,val2,val3,val4 ;
            ll id1,id2,id3,id4 ;
            val1=val2=val3=val4 = INT_MAX ;
            if(i<a){
                val1 = arr[i].ff ;
                id1 = arr[i].ss ;
            }
            if(j<b){
                val2 = brr[j].ff ;
                id2 = brr[j].ss ;
            }
            if(p<c){
                val3 = crr[p].ff ;
                id3 = crr[p].ss ;
            }
            if(ee<e){
                val4 = extra[ee].ff ;
                id4 = extra[ee].ss ;
            }
            //dbg(val1,val2,val3,val4) ;
            if(val1 != INT_MAX && val1<=val2 && val1<=val3&&val1<=val4){
                ans += val1 ;
                index.pb(id1) ;
                i++ ;
                rem-- ;
            }
            else if(val2 != INT_MAX && val2<=val1 && val2<=val3&&val2<=val4){
                ans += val2 ;
                index.pb(id2) ;
                j++ ;
                rem-- ;
            }
            else if(val3 != INT_MAX && val3<=val1&&val3<=val2&&val3<=val4){
                ans += val3 ;
                index.pb(id3) ;
                p++ ;
                rem-- ;
            }
            else if(val4!=INT_MAX&&val4<=val1&&val4<=val2&&val4<=val3){
                ans += val4 ;
                index.pb(id4) ;
                ee++ ;
                rem-- ;
            }
            //dbg(ans,rem) ;
        }

        if(rem == 0){
            cout<< ans << endl ;
            foreach(index) cout<< val << " " ;
            cout<< endl ;
        }
        else cout<< "-1" << endl ;
    }
    else cout<< "-1" << endl ;

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


