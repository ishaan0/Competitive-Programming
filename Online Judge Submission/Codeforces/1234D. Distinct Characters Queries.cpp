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

#define lim 100005
string str ;
int tree[lim*4][27] ;

void build(int node,int lo,int hi){
    //cout<< "node-> " << node <<" "<<lo <<" "<<hi << endl ;
    if(lo == hi){
        tree[node][str[lo]-'a'] = 1 ;
        return ;
    }
    int left = node*2 ;
    int right = left+1 ;
    int mid = lo+(hi-lo)/2 ;
    build(left,lo,mid) ;
    build(right,mid+1,hi) ;

    for(int i=0; i<26; i++){
        //cout<< "de-> "<< node <<" "<<(char)(i+'a') <<" "<<tree[left][i] << " " << tree[right][i] <<endl;
        if(tree[left][i] == 1 || tree[right][i] == 1)
            tree[node][i] = 1 ;
        else tree[node][i] = 0 ;
    }

}

void update(int node,int lo,int hi,int qi,char val){
    if(qi<lo || qi>hi) return ;
    if(lo == hi){
        for(int i=0; i<26; i++)
            if(tree[node][i] == 1){
                tree[node][i] = 0 ;
                //cout<< "de-> " << (char)(i+'a') << endl ;
                break ;
            }
        tree[node][val-'a']=  1 ;
        return ;
    }
    int left = node*2 ;
    int right = left+1 ;
    int mid = lo+(hi-lo)/2 ;
    update(left,lo,mid,qi,val) ;
    update(right,mid+1,hi,qi,val) ;

    for(int i=0; i<26; i++){
        if(tree[left][i] == 1 || tree[right][i] == 1)
            tree[node][i] = 1 ;
        else tree[node][i] = 0 ;
    }
}

vector<int> query(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi){
        vector<int> temp(27) ;
        return temp ;
    }
    if(qi<=lo && hi<=qj){
        vector<int> temp(27) ;
        for(int i=0; i<26; i++)
            temp[i] = tree[node][i] ;
        //cout<< "de-> " << node<<" "<<cnt << endl ;
        return temp ;
    }
    int left = node*2 ;
    int right = left+1 ;
    int mid = lo+(hi-lo)/2 ;
    vector<int> lsum = query(left,lo,mid,qi,qj) ;
    vector<int> rsum = query(right,mid+1,hi,qi,qj) ;
    vector<int> temp(27) ;
    for(int i=0; i<26; i++){
        if(lsum[i] == 1 || rsum[i]==1 )
            temp[i] = 1 ;
        else temp[i] = 0 ;
    }

    return temp ;
}



//#define DEBUG
int main()
{
    //Boost;

    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif


    cin>> str ;
    str = "a" + str ;
    /*cout<< str << " " << str.size() << endl ;
    cin>> str ;*/
    build(1,1,str.size()-1) ;
    int q ;
    cin>> q ;
    while(q--){
        int temp ;
        cin>> temp ;
        if(temp == 1){
            int pos ;
            string c ;
            cin>> pos >> c ;
            update(1,1,str.size()-1,pos,c[0]) ;
        }
        else{
            int l,r ;
            cin>> l >>r ;
            vector<int> temp = query(1,1,str.size()-1,l,r) ;
            int ans = 0 ;
            for(int i=0; i<26; i++)
                if(temp[i] == 1) ans++ ;
            cout<< ans << endl ;
        }
    }


    return 0;
}


