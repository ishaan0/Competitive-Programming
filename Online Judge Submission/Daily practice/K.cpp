#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define print(x) for (auto &el: x) cout << el << ' '; cout << '\n'
using namespace std;

int lp[10000100], u[10000100];

void mobius(int n) {
    for (int i = 2; i <= n; ++i) {
        if (lp[i]) continue;
        for (int j = 2 * i; j <= n; j += i) lp[j] = i;
        lp[i] = i;
    }
    u[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (lp[i / lp[i]] == lp[i]) u[i] = 0;
        else u[i] = -1 * u[i / lp[i]];
    }
}

int main() {
    mobius(1e7);
    int t;
    scanf("%d", &t);
    while(t--) {
        ll n;
        scanf("%lld", &n);
        ll ans = 0;
        for (ll i = 1; i * i <= n; ++i) {
            ll k = n / (i * i);
            ans += u[i] * k;
        }
        printf("%lld\n", ans);
    }
    return 0;
} 