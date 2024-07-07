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
#define SZ(x) ((int)x.size()) 
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const double eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

// Here is the template

const int base = 131;
const int N = 1e6 + 10;

ull p[N];

void init() {
    rep(i, 1, N + 1) {
        p[i] = p[i - 1] * base % mod;
    }
}

void hash(string s, vector<ull> &a) {
    rep(i, 1, N + 1) {
        a[i] = a[i - 1] * base + s[i - 1] - 'a' + 1;
        a[i] %= mod;
    }
}

int get(int l, int r, vector<ull> &a) {
     int t = a[r] - a[l - 1] * p[r - l + 1];
     return (t % mod + mod) % mod;
}
