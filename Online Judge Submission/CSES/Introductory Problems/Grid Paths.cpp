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
#define     eps                 1e-9
#define     inf                 LLONG_MIN
#define     INF                 LLONG_MAX
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

const int n = 7;
bool visited[n][n];
int reserved[49];

void dfs(int r, int c, int &ans, int &steps)
{
    if (r == n - 1 && c == 0){
        ans += (steps == n * n - 1);
        return;
    }

    if (((r + 1 == n || (visited[r - 1][c] && visited[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c + 1 == n || (visited[r][c - 1] && visited[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]) ||
        ((r == 0 || (visited[r + 1][c] && visited[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c == 0 || (visited[r][c + 1] && visited[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]))
        return;

    visited[r][c] = true;

    if (reserved[steps] != -1){
        switch (reserved[steps]){
        case 0:
            if (r - 1 >= 0){
                if (!visited[r - 1][c]){
                    steps++;
                    dfs(r - 1, c, ans, steps);
                    steps--;
                }
            }
            break;

        case 1:
            if (c + 1 < n){
                if (!visited[r][c + 1]){
                    steps++;
                    dfs(r, c + 1, ans, steps);
                    steps--;
                }
            }
            break;

        case 2:
            if (r + 1 < n){
                if (!visited[r + 1][c]){
                    steps++;
                    dfs(r + 1, c, ans, steps);
                    steps--;
                }
            }
            break;

        case 3:
            if (c - 1 >= 0){
                if (!visited[r][c - 1]){
                    steps++;
                    dfs(r, c - 1, ans, steps);
                    steps--;
                }
            }
            break;
        }
        visited[r][c] = false;
        return;
    }

    if (r + 1 < n){
        if (!visited[r + 1][c]){
            steps++;
            dfs(r + 1, c, ans, steps);
            steps--;
        }
    }

    if (c + 1 < n){
        if (!visited[r][c + 1]){
            steps++;
            dfs(r, c + 1, ans, steps);
            steps--;
        }
    }

    if (r - 1 >= 0){
        if (!visited[r - 1][c]){
            steps++;
            dfs(r - 1, c, ans, steps);
            steps--;
        }
    }

    if (c - 1 >= 0){
        if (!visited[r][c - 1]){
            steps++;
            dfs(r, c - 1, ans, steps);
            steps--;
        }
    }
    visited[r][c] = false;
}


int main()
{
    Boost;

    string path;
    cin >> path;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '?')
            reserved[i] = -1;
        else if (path[i] == 'U')
            reserved[i] = 0;
        else if (path[i] == 'R')
            reserved[i] = 1;
        else if (path[i] == 'D')
            reserved[i] = 2;
        else if (path[i] == 'L')
            reserved[i] = 3;
    }
    int ans = 0, steps = 0;
    dfs(0, 0, ans, steps);
    cout << ans;

    return 0;
}

