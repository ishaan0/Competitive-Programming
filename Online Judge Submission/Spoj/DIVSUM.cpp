/** Header Files */

//#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iterator>
#include<cctype>
#include<climits>
#include<string>
#include<sstream>
#include<cstring>
#include<ctime>
#include<numeric>
#include<stdint.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*** Macro Star Here */


#define Boost ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define all(cont) cont.begin(),cont.end()
#define rall(cont) cont.rbegin(),cont.rend()
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, dec) for (int i=j ; i>=k ; i-=dec)
#define REP(i, j) FOR(i,0,j,1)
#define RREP(i, j) RFOR(i,j,0,1)
#define itloop(it,cont) for (__typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define foreach(cont) for(auto &value: cont)
#define mk make_pair
#define pb push_back
#define INF (int)1e9
#define sortArr(arr, sz) sort(arr , arr+sz )
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define flush cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define memz(x) memset(x, 0, sizeof(x))
#define memneg(x) memset(x, -1, sizeof(x))
#define came cout<< "Came Here" << endl
#define show(val) cout<< #val << " -> " << val << endl
#define MOD (int)(1e9 + 7)
#define ff first
#define ss second


/*** Scanf Printf ***/
/**
#define sf1(n) scanf("%d",&n)
#define sf2(n,m) scanf("%d%d",&n,&m)
#define sfl1(n) scanf("%I64d",&n)
#define sfl2(n,m) scanf("%I64d%lld",&n,&m)

#define pf1(n) printf("%d",n)
#define pf2(n,m) printf("%d %d",n,m)
#define pfl1(n) printf("%I64d",n)
#define pfl2(n,m) printf("%I64d %I64d",n,m)
#define pfs(s) printf("%s",s)
#define nl printf("\n") **/


/*** Geometry & Maths */

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define pi acos(-1.0)
#define sq(x) ((x)*(x))
#define dis(x1,y1,x2,y2) sqrt(sq(x1-x2) * (y1-y2))
#define t_area(a,b,c,s) sqrt(s*(s-a)*(s-b)*(s-c)) // s = (a+b+c)/2.0
#define t_angle(a,b,c) acos((sq(a)+sq(b)-sq(c))/(2*a*b)) // return C in radian . it is anti clockwise formatted.


/**typedef starts here*/

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector < pair <int, int> > VII;
typedef map < string , int > MSI;
typedef map < int ,int > MII;
typedef set < int > SETI;
typedef multiset < int > MSETI;
typedef priority_queue<int,vector<int>,greater<int> > min_heap;

/**typedef ends here*/




//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    ll t ;
    scanf("%lld",&t) ;

    while(t--){
        ll a;
        scanf("%lld",&a) ;

        ll ans = 0 ,i=1;
        for(i=1; i*i<a; i++)
            if(a%i == 0)
                ans += i + (a/i) ;

        if(i*i == a) ans += i ;
        ans -= a ;

        printf("%lld\n",ans) ;
    }

    return 0;
}
