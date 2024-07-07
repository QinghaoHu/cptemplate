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

const int N = 1e6 + 10;

int n, m;
int nxt[N + 1], f[N + 1];
char s[N + 2], p[N + 2];

void kmp() {
    n = strlen(s + 1), m = strlen(p + 1);
    int j = 0;
    nxt[1] = 0;
    for (int i = 2; i <= m; i++) {
        while(j > 0 && p[j + 1] != p[i]) {
            j = nxt[j];
        }
        if (p[j + 1] == p[i]) {
            j++;
        }
        nxt[i] = j;
    }
    rep(i, 1, n + 1) {
        while((j == m) || (j > 0 && p[j + 1] != s[i])) {
            j = nxt[j];
        }
        if (p[j + 1] == s[i]) {
            j++;
        }
        f[i] = j;
    }
}
