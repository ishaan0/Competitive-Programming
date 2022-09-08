#include<bits/stdc++.h>
using namespace std ;
#define ll long long



ll const row = 105 ;
ll const col = 105 ;
ll const mod = 1e9+7 ;

struct matrix{
    ll mat[row][col] ;
    matrix(){}
    matrix(int type){
        memset(mat,0,sizeof mat) ;
        if(type == 1){              /// Identity matrix
            for(int i=0,j=0; i<row&&j<col; i++,j++)
                mat[i][j] = 1 ;
        }
        else if(type == 2){         /// Fibonacci matrix
            mat[0][0] = mat[0][1] = mat[1][0] = 1 ;
        }
        else if(type == 3){         /// nth order fibb: f(n) = f(n-1)+f(n-2)+f(n-3)...
            for(int i=0; i<col; i++) mat[0][i] = 1 ;
            for(int i=1; i<row; i++) mat[i][i-1] = 1 ;
        }
    }
    matrix(int arr[]){
        for(int i=0,k=0; i<row; i++)
            for(int j=0; j<col; j++)
                mat[i][j] = arr[k++] ;
    }

    matrix operator+(const matrix b) const{
        matrix ans = matrix(0) ;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                ans.mat[i][j] = ((long long)mat[i][j] + b.mat[i][j]) % mod ;
        return ans ;
    }

    matrix operator*(const matrix b) const{
        matrix ans = matrix(0) ;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                for(int k=0; k<col; k++)
                ans.mat[i][j] = (ans.mat[i][j]+ mat[i][k]*1LL*b.mat[k][j]) % mod ;
        return ans ;
    }

    matrix operator^(int p){
        matrix res(1) ;
        matrix x = *this ;
        while(p){
            if(p&1)
                res = res * x ;
            p >>= 1 ;
            x = x * x ;
        }
        return res ;
    }
};


int main(){

    return 0 ;
}
