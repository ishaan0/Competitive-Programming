#include<bits/stdc++.h>
using namespace std;

//#define DEBUG

#define Boost ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define all(cont) cont.begin(),cont.end()
#define rall(cont) cont.rbegin(),cont.rend()
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, dec) for (int i=j ; i>=k ; i-=dec)
#define REP(i, j) FOR(i,0,j,1)
#define RREP(i, j) RFOR(i,j,0,1)
#define itloop(cont) for (auto it = cont.begin(); it != cont.end(); it++)
#define foreach(cont) for(auto &value: cont)
#define mk make_pair
#define pb push_back
#define INF (int)1e9
#define sq(x) (x*x)
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define flush cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define came cout<< "Came Here" << endl
#define ff first
#define ss second

/*typedef starts here*/

//const double pi=2*acos(0);

typedef vector <int> VI;
typedef vector <string> VS;
typedef pair <int, int> PII;
typedef long long ll;
typedef vector < pair <int, int> > VII;
typedef map < string , int > MSI;
typedef map < int ,int > MII;
typedef set < int > SETI;
typedef multiset < int > MSETI;
typedef priority_queue<int,vector<int>,greater<int> > min_heap;

/*typedef ends here*/

int countSetBit(int n){
    int cnt = 0 ;

    while(n>0){
        cnt += (n&1) ;
        n = n>>1 ;
    }
    return cnt ;
}

int bitFast(int n){
    int cnt = 0 ;
    while(n){
        cnt++ ;
        cout<< n << endl;
        n = n&(n-1) ;

    }
    return cnt ;
}

int getIthBit(int n,int i){
    return (n& (1<<i))!=0 ? 1 : 0 ;
}

void setIthBit(int n,int i){
    n = (n|(1<<i)) ;
    cout<< n << endl;
}

void removeBit(int n,int i){
    int mask = ~(1<< i) ;
    n = n & mask ;
    cout<< n << endl;
}

void filterChar(string str,int no){
    int i= 0 ;
    while(no>0){
        string ch="" ;
        if(no&1) ch = str[i] ;
        i++ ;
        no = no>>1 ;
        cout<< ch ;
    }
    cout<< endl;
}

void generateSubsets(string str){
    int n = str.size() ;
    int range = (1<<n) - 1 ;

    for(int i=0;i<=range ;i++)
        filterChar(str,i) ;
}

int main()
{
    Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif
    int a=10,b=4 ;
    int c = a&b ;
    cout<< c << endl;
    /*if(a&b)
        cout<< "Y"<< endl;
    else cout<< "N" << endl;*/

	return 0;
}

