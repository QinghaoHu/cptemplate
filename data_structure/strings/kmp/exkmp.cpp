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
typedef pair<ll, int> PLI;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

vector<int> ZFunction(string s) {
    int n = s.size();
    vector<int> z(n + 1);
    int l = 1, r = 0;
    z[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i > r) {
            z[i] = 0;
        } else {
            z[i] =  min(z[i - l + 1], r - i + 1);
        }
        while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}