#include<bits/stdc++.h>
using namespace std ;

int node,edge,target;
vector<int> adj[20] ;
int dp[16][(1<<16)+100] ;

int setBit(int n,int pos){ return (n|(1<<pos)); }
bool checkBit(int n,int pos){ return (bool)(n&(1<<pos)); }
int toogleBit(int n,int pos){ return (n^(1<<pos)); }


/// memory : O(n*2^n)   time : O(n*n*2^n)
bool isPath(int u,int mask){
    if(mask == target) return true ;
    bool &ans = dp[u][mask] ;
    if(ans != -1) return ans ;
    ans = false ;
    for(int &v: adj[u]){
        if(!checkBit(mask,v)){
            if(isPath(v,setBit(mask,v))){
                ans = true ;
                break ;
            }
        }
    }
    return ans ;
}


int main(){
    cin>> node >> edge ;
    for(int i=0; i<edge; i++){
        int u,v ;
        cin>> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    target = (1<<node)-1 ;
    bool flag = false ;
    memset(dp,-1,sizeof dp) ;

    for(int i=0; i<node; i++){
        if(isPath(i,setBit(0,i))){
            flag = true ;
            break ;
        }
    }

    if(flag) cout<< "Path possible" << endl ;
    else cout<< "Not possible" << endl ;

    return 0 ;
}
