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

vector<int> nxt(string str) {
    int n = (int)str.size();
    str = " " + str;
    vector<int> nxt(n + 1, 0);
    nxt[1] = 0;
    int j = 0;
    for (int i = 2; i <= n; i++) {
        while (j > 0 && str[j + 1] != str[i]) {
            j = nxt[j];
        }
        if (str[j + 1] == str[i]) {
            j++;
        }
        nxt[i] = j;
    }
    return nxt;
}