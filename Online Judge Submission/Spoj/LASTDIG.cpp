    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long

    ll binPow(ll a, ll b, ll m){
        a = a%m ;
        ll res = 1 ;
        while(b>0){
            if(b&1) res = res * a % m ;
            a = a*a % m ;
            b >>= 1 ;
        }

        return res ;
    }

    int main() {

    	int t ;
        cin>> t ;

        while(t--){
            ll a, b ;
            cin>> a >> b ;

            cout<< binPow(a,b,10) << endl ;
        }


    	return 0;
    }
