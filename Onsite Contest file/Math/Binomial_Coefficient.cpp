#include<bits/stdc++.h>
using namespace std ;

namespace bin{
    const int max_n = 1e5 + 5 ; 
    const long long mod = 1e9+7 ;

    int fact[max_n] , inv[max_n] ;

    long long expo(long long a,long long b){
        a %= mod ;
        long long res = 1 ;
        while(b > 0){
            if(b & 1) res = (res * a) % mod ;
            a = (a * a) % mod ;
            b >>= 1 ;
        }
        return res ;
    }

    void preCal(){
        fact[0] = 1 ;
        for(int i=1; i<max_n; i++) fact[i] = (fact[i-1] * 1LL * i) % mod ;
        inv[max_n-1] = expo(fact[max_n-1], mod-2) ;
        for(int i=max_n-2; i>=0; i--) inv[i] = (inv[i+1] * 1LL * (i+1)) % mod ;
    }

    inline int nCr(int n,int r){
        if(r>=n) return (n==r) ;
        return ( ((1LL*fact[n]*inv[n-r]) % mod)*(1LL*inv[r]) ) % mod ;
    }
}

namespace crt{
    long long extended_gcd(long long a, long long b, long long& x, long long& y){
        if (!b){
            y = 0, x = 1;
            return a;
        }

        long long g = extended_gcd(b, a % b, y, x);
        y -= ((a / b) * x);
        return g;
    }

    long long mod_inverse(long long a, long long m){
        long long x, y, inv;
        extended_gcd(a, m, x, y);
        inv = (x + m) % m;
        return inv;
    }

    long long chinese_remainder(vector <long long> ar, vector <long long> mods){
        int i, j;
        long long x, y, res = 0, M = 1;

        for (i = 0; i < ar.size(); i++) M *= mods[i];
        for (i = 0; i < ar.size(); i++){
            x = M / mods[i];
            y = mod_inverse(x, mods[i]);
            res = (res + (((x * ar[i]) % M) * y)) % M;
        }

        return res;
    }
}

// nCk % M , where M is non prime and all prime factor P^q  <= 10^7

namespace bin{
    int dp[MAXP];
    long long mod = 0;

    long long trailing(long long x, long long p){
        long long res = 0;
        while (x){
            x /= p;
            res += x;
        }
        return res;
    }

    long long expo(long long x, long long n, long long m){
        if (!n) return 1;
        else if (n & 1) return ((expo(x, n - 1, m) * x) % m);
        else{
            long long r = expo(x, n >> 1, m);
            return ((r * r) % m);
        }
    }

    long long factorial(long long x, long long p){
        long long res = expo(dp[mod - 1], x / mod, mod);
        if (x >= p) res = res * factorial(x / p, p) % mod;
        return res * dp[x % mod] % mod;
    }

    /// binomial co-efficients modulo p^q (p must be a prime)
    long long binomial(long long n, long long k, long long p, long long q){
        if (k > n) return 0;
        if (n == k || k == 0) return 1;

        int i, j;
        for (i = 0, mod = 1; i < q; i++) mod *= p;
        long long t = trailing(n, p) - trailing(k, p) - trailing(n - k, p);
        if (t >= q) return 0;

        assert(mod < MAXP);
        for (dp[0] = 1, i = 1; i < mod; i++){
            dp[i] = (long long)dp[i - 1] * (i % p ? i : 1) % mod;
        }

        long long res = factorial(n, p) * expo(factorial(k, p) * factorial(n - k, p) % mod, (mod / p) * (p - 1) - 1, mod) % mod;
        while (t--) res = res * p % mod;
        return res;
    }

    /// binomial co-efficients modulo m (p_i^q_i of m must be less than MAXP)
    long long binomial(long long n, long long k, long long m){
        if (k > n || m == 1) return 0;
        if (n == k || k == 0) return 1;

        vector <pair<int, int>> factors;
        for (long long i = 2; i * i <= m; i++){
            int c = 0;
            while (m % i == 0){
                c++;
                m /= i;
            }
            if (c) factors.push_back(make_pair(i, c));
        }
        if (m > 1) factors.push_back(make_pair(m, 1));

        vector <long long> ar, mods;
        for (int i = 0; i < factors.size(); i++){
            long long x = 1;
            for (int j = 0; j < factors[i].second; j++) x *= factors[i].first;
            mods.push_back(x), ar.push_back(binomial(n, k, factors[i].first, factors[i].second));
        }
        return crt::chinese_remainder(ar, mods);
    }
}

namespace lc{
    #define MAXP  1000010
    int MOD = 1000000007;
    int fact[MAXP], inv[MAXP];

    /// Call once with the modulo prime
    void init(int prime){
        MOD = prime;
        fact[0] = 1, inv[MOD - 1] = MOD - 1;
        for (int i = 1; i < MOD; i++) fact[i] = ((long long)fact[i - 1] * i) % MOD;
        for (int i = MOD - 2; i >= 0; i--) inv[i] = ((long long)inv[i + 1] * (i + 1)) % MOD;
    }

    inline int count(int n, int k){
        if (k > n) return 0;
        int x = ((long long)inv[n - k] * inv[k]) % MOD;
        return ((long long)x * fact[n]) % MOD;
    }

    /// Lucas theorem, calculates binomial(n, k) modulo MOD, MOD must be a prime
    inline int binomial(long long n, long long k){
        if (k > n) return 0;

        int res = 1;
        k = min(k, n - k);
        while (k && res){
            res = ((long long)res * count(n % MOD, k % MOD)) % MOD;
            n /= MOD, k /= MOD;
        }
        return res;
    }
}

int main(){



    
    return 0 ;
}