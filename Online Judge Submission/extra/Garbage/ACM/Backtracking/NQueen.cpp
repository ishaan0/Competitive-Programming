#include<bits/stdc++.h>
using namespace std ;

/// Basic Solution Starts ...

bool nQueen(int col, int n) ;
vector<bool> queen[50] ;

void execNQueen(int n){

    for(int i=0; i<n; i++){
        queen[i].clear() ;
        for(int j=0; j<n; j++)
            queen[i].push_back(false) ;
    }
    nQueen(0,n) ;
}

bool isSafe(int row,int col,int n){
    for(int i=row; i>=0; i--)
        if(queen[i][col] == true) return false ;

    for(int i=row,j=col; i>=0&&j>=0; i--,j--)
        if(queen[i][j] == true) return false ;

    for(int i=row,j=col; i>=0&&j<n; i--,j++)
        if(queen[i][j] == true) return false ;
    return true ;
}

bool nQueen(int row, int n){
    if(row >= n){
        cout<< "output : " << endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                if(queen[i][j] == true) cout<< "Q";
                else cout<< "*";
            cout<< endl;
        }
        cout<< endl;
        return false ;
    }

    for(int j=0; j<n; j++){
        if(isSafe(row,j,n)){
            queen[row][j] = true ;
            if(nQueen(row+1,n))
                return true ;
            queen[row][j] = false ;
        }
    }
    return false ;
}

/// basic solution ends ...


/// Optimized Solution ...
vector<int> queenPos(20) ;
vector<bool> column(20), diagonal1(40), diagonal2(40) ;

void nQueenOptimized(int row, int n){
    if(row == n+1){
        cout<< "output : " << endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                if(queenPos[i]== j) cout<< "Q" ;
                else cout<< "*" ;
            cout<< endl;
        }
        cout<< endl;
        return ;
    }
    // checking all column one by one in a row .
    for(int j=1; j<=n; j++){
        if(column[j] || diagonal1[row+j] || diagonal2[n+j-row])
            continue ;
        queenPos[row] = j ;
        column[j] = diagonal1[row+j] = diagonal2[n+j-row] = true ;
        nQueenOptimized(row+1,n) ;
        column[j] = diagonal1[row+j] = diagonal2[n+j-row] = false ;
    }
}

int main(){

    execNQueen(4) ;
    nQueenOptimized(1,4) ;

    return 0 ;
}
