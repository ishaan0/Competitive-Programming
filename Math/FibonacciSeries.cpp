#include<bits/stdc++.h>
using namespace std ;
#define ll long long

/// Recursive in exponential time
int fibRecursive(int n){
    if(n < 2) return n ;
    return fibRecursive(n-1) + fibRecursive(n-2) ;
}

/// linear Solution O(n)
int fibLinear(int n){
    if(n == 0) return 0 ;
    else if(n==1 || n==2) return 1 ;

    int f = 1 , s = 1 ;
    for(int i=3; i<=n; i++){
        int temp = f+s;
        f = s ;
        s = temp ;
    }

    return s ;
}

/// Efficient solution O(logn)
/// using matrix exponential

ll const row = 5 ;
ll const col = 5 ;
ll const mod = 1e4 ;

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
    }

    matrix operator*(const matrix b) const{
        matrix ans = matrix(0) ;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                for(int k=0; k<col; k++)
                ans.mat[i][j] = (ans.mat[i][j]+ mat[i][k]*b.mat[k][j]) % mod ;
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
    int t ;
    cin>> t ;

    while(t--){
        int n ;
        cin>> n ;

        cout<< "Fiboncci exponential: " << fibRecursive(n) << "\n" ;
        cout<< "Fiboncci iterative dp : " << fibLinear(n) << "\n" ;
        cout<< "Fiboncci matrix exponential: " ;

        if(n<2) return cout<< n << "\n" , 0 ;

        matrix ans(2) ;
        ans = ans^(n-1) ;

        int res = ans.mat[0][0] ;

        cout<< res << "\n" ;
    }

    return 0 ;
}