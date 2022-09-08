#include<bits/stdc++.h>
using namespace std;

#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &value: cont)
#define     show(val)           cout<< #val << " -> " << val << endl
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs << ": "
#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second

typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;

const ll INF = (1LL<<60)-1 ;




//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif

    int t;
	cin>>t;
	while(t--)
	{
		int n,sum=0;
		cin>>n;
		if(n<=250000)
			sum=0;
		else if(n>250000 && n<=500000)
			sum=(n-250000)*0.05;
		else if(n>500000 && n<=750000)
			sum=(n-500000)*0.1+12500;
		else if(n>750000 && n<=1000000)
			sum=(n-750000)*0.15+37500;
        else if(n>1000000 && n<=1250000)
			sum=(n-1000000)*0.2+37500*2;
        else if(n>1250000 && n<=1500000)
			sum=(n-1250000)*0.25+50000+75000;
		else if (n>1500000)
			sum=(n-1500000)*0.3+62500+50000+75000;
		cout<<(n-sum)<<endl;
	}


    return 0;
}


