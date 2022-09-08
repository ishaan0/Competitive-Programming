#include<bits/stdc++.h>
using namespace std ;
#define     ll          long long


int egcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1 ;
        y = 0 ;
        return a ;
    }
    int x1,y1,g ;
    g = egcd(b, a%b, x1, y1) ;
    x = y1 ;
    y = x1 - y1 * (a/b) ;
    return g ;
}

int diophantine(int &a,int &b,int &c,int &x,int &y){
    int g = egcd(abs(a),abs(b),x,y) ;
    if(c % g != 0) return -1 ;

    x *= c/g ;
    y *= c/g ;

    if(a < 0) x *= -1 ;
    if(b < 0) y *= -1 ;

    return g ;
}

void shift_value(int a,int b,int &x,int &y,int cnt){
    x += cnt * b ;
    y -= cnt * a ;
}

int diophantine_range(int a,int b,int c,int minx,int maxx,int miny,int maxy){
    int x, y, g, l1, r1, l2, r2 ;
    g = diophantine(a,b,c,x,y) ;
    if(g == -1) return -1 ;

    a /= g ;
    b /= g ;

    int sign_a = (a > 0) ? 1 : -1 ;
    int sign_b = (b > 0) ? 1 : -1 ;

    shift_value(a, b, x, y, (minx - x)/b) ;
    if(x < minx) shift_value(a, b, x, y, sign_b) ;
    if(x > maxx) return -1 ;
    l1 = x ;

    shift_value(a, b, x, y, (maxx - x)/b) ;
    if(x > maxx) shift_value(a, b, x, y, -sign_b) ;
    r1 = x ;

    shift_value(a, b, x, y, -(miny - y)/a) ;
    if(y < miny) shift_value(a, b, x, y, -sign_a) ;
    if(y > maxy) return -1 ;
    l2 = x ;

    shift_value(a, b, x, y, -(maxy - y)/a) ;
    if(y > maxy) shift_value(a, b, x, y, sign_a) ;
    r2 = x ;

    if(l2 > r2) swap(l2, r2) ;
    int lo = max(l1, l2) ;
    int hi = min(r1, r2) ;

    if(lo > hi) return -1 ;
    return (hi - lo)/abs(b) + 1 ;
}


int main(){

    ll a, b, c, x, y ;
    scanf("%lld %lld %lld", &a, &b, &c) ;

    if(a == b && a == 0){   // degenerate case
        if(c == 0) cout<< "There are infinite solutions .\n" ;
        else cout<< "Zero solutions\n" ;
        return 0 ;
    }

    ll g = diophantine(a,b,c,x,y) ;


    if(g == -1){
        printf("Sorry no soluton exist !!!") ;
        return 0 ;
    }

    printf("One solution : %lld*%lld + %lld*%lld = %lld\n", a,x,b,y,c) ;

    printf("Some other solution :\n") ;
    for(ll k=1; k<=10; k++){
        ll nx = x + k * (b/g) ;
        ll ny = y - k * (a/g) ;

        printf("%lld*%lld + %lld*%lld = %lld\n", a,nx,b,ny,c) ;
    }

    return 0 ;
}