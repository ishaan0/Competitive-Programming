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

    int t ;
    cin>> t ;

    while(t--){
        int r,c ;
        cin>> r >> c ;
        int sum = (r+c);
        int tr=sum/2 ;
        int tc = tr ;

        if((r==1 && c==1) || (r==8 && c==8))
            cout<< "25" << endl ;
        else if(r==1 || c==1 || r==8 || c==8){
            cout<< "24" << endl ;
            cout<< c << " " << r << endl ;
            cout<< sum/2 << " " << sum/2 << endl ;
        }
        else{
            cout<< "25" << endl ;
            if(tr>4){
                cout<< sum-8 << " " << 8 << endl ;
                cout<< 8 << " " << sum-8 << endl ;
            }
            else{
                cout<< sum-1 << " " << 1 << endl ;
                cout<< 1 << " " << sum-1 << endl ;
            }
            cout<< sum/2 << " " << sum/2 << endl ;
        }
        tr = (r+c)/2 ;
        tc = tr ;
        if(r!=8 || c!=8){
            tr++,tc++ ;
            while(tr < 8 || tc < 8){
                cout<<  tr << " " << tc <<endl ;
                sum = tr+tc ;
                if(tr>4){
                    cout<< sum-8 << " " << 8 << endl ;
                    cout<< 8 << " " << sum-8 << endl ;
                }
                else{
                    cout<< sum-1 << " " << 1 << endl ;
                    cout<< 1 << " " << sum-1 << endl ;
                }
                cout<< tr << " " << tc << endl ;
                tr++, tc++ ;
            }
            cout<< 8 << " " << 8 << endl ;
        }

        tr = (r+c)/2 ;
        tc = tr ;
        tr--, tc-- ;
        if(r!=1 || c!=1){
            while(tr > 1 || tc > 1){
                cout<<  tr << " " << tc <<endl ;
                sum = tr+tc ;
                if(tr>4){
                    cout<< sum-8 << " " << 8 << endl ;
                    cout<< 8 << " " << sum-8 << endl ;
                }
                else{
                    cout<< sum-1 << " " << 1 << endl ;
                    cout<< 1 << " " << sum-1 << endl ;
                }
                cout<< tr << " " << tc << endl ;
                tr--, tc-- ;
            }
            cout<< 1 << " " << 1 << endl ;
        }
    }

    return 0;
}


