#include<bits/stdc++.h>
using namespace std;

#define  pi         acos(-1.0)
#define  cos(a)     cos(a*pi/180)
#define  sin(a)     sin(a*pi/180)
#define  tani(a)    atan(a)/(pi/180)

int main()
{
    int i, t;
    cin>>t;
    while(t--){
        double R, r, m, n, p, angle, q, kiteArea, area, area1, area2, areaSector1, areaSector2, blackArea, orangeArea;
        cin>>R>>r;
        m = r*cos(30.0);
        n = R-m;
        p = r*sin(30.0);
        angle = tani(p/n);
        q = n*cos(angle);
        area1 = p*m;
        area2 = p*n;
        kiteArea = area1 + area2;
        areaSector1 = (pi*r*r)/6.0;
        areaSector2 = (angle*2*pi*q*q)/360.0;
        blackArea = 6.0*(areaSector1+areaSector2-kiteArea); 
        orangeArea = pi*R*R - (6.0*kiteArea);
        // cerr<< areaSector1 << " " << areaSector2 << " " << kiteArea << " " << angle*2 << endl ;
        // cerr<< p*2 << endl ;
        // cerr<< p << " " << q << endl ;

        area = blackArea+orangeArea;
        stringstream ss;
        string s;
        ss << fixed << setprecision(4) << area;
        s=ss.str();
        cout << s.substr(0, s.size()-1)<<endl ;
        // cout<< fixed << setprecision(5) <<  kiteArea << endl ;
    }
    return 0;
}