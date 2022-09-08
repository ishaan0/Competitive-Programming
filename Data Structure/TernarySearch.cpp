#include<bits/stdc++.h>
using namespace std;

/**
    problem : 1146 - Closest Distance
    link    : http://lightoj.com/volume_showproblem.php?problem=1146

    Used ternary search to find min distance .
    We can use ternary search when graph is U shape .
    Time : O(logn) , here log is 3 base log .
*/

int ax,ay,bx,by,cx,cy,dx,dy ;
double d1x,d1y,d2x,d2y ;
const double eps = 1e-9 ;

double func(double val){
    double x1 = ax + d1x*val ;
    double y1 = ay + d1y*val ;
    double x2 = cx + d2x*val ;
    double y2 = cy + d2y*val ;
    double a = (x2-x1) ;
    double b = (y2-y1) ;
    return sqrt(a*a + b*b) ;
}

double ternarySearch(){
    double lo = 0.0, hi = 1.0 ;
    while(hi-lo > eps){
        double m1 = lo+(hi-lo)/3.0 ;
        double m2 = hi-(hi-lo)/3.0 ;
        double f1 = func(m1) ;
        double f2 = func(m2) ;
        if(f1-f2 > eps)
            lo = m1 ;
        else hi = m2 ;
    }
    return func(lo) ;
}


void solve(){
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy ;
    d1x = bx-ax, d1y = by - ay ;
    d2x = dx-cx, d2y = dy - cy ;

    double ans = ternarySearch() ;
    cout<< fixed << setprecision(10) << ans << endl ;

}


int main()
{
    int t = 1,cs = 0 ;
    cin>> t ;

    while(t--){
        cout<< "Case "<< ++cs <<": " ;
        solve() ;
    }

    return 0;
}

