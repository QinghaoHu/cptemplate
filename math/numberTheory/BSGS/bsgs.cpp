#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

struct BSGS {
    int64_t a, b, m;

    BSGS(int64_t x, int64_t y, int64_t z) : a(x), b(y), m(z) {}

    ll powmod(ll x, ll y, ll z) {
        ll res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = res * x % z;
            }
            x = x * x % z;
        }
        return res;
    }

    ll solve() {
        int T = sqrt(m) + 1;
        ll v = powmod(a, T, m), d = 1;
        unordered_map<ll, int> hs;
        for (int q = 1; q <= T; q++) {
            d = d * v % m;
            if (!hs.count(d)) {
                hs[d] = q * T;
            }
        }
        ll ans = m + 1;
        d = b;
        for (int r = 0; r < T; r++) {
            if (hs.count(d)) {
                ans = min(ans, (int64_t)hs[d] - r);
            }
            d = d * a % m;
        }
        return (ans <= m) ? ans : -1;
    }
};
