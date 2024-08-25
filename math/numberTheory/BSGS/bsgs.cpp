#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define arr array
#define SZ(x) ((int)x.size())
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

struct BSGS {
    ll a, b, m;

    BSGS(ll x, ll y, ll z) : a(x), b(y), m(z) {}

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
                ans = min(ans, hs[d] - r);
            }
            d = d * a % m;
        }
        return (ans <= m) ? ans : -1;
    }
};
