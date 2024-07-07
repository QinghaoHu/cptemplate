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

const int SIZE = 1e6 + 10;

int tot = 1, trie[SIZE][26];

bool endst[SIZE];

void insert(char *str) {
    int len = strlen(str);
    int p = 1;
    rep(i, 0, len) {
        int ch = str[i] - 'a';
        if (trie[p][ch] == 0) trie[p][ch] = ++ tot;
        p = trie[p][ch];
    }
    endst[p] = true;
}

bool search(char *str) {
    int n = strlen(str), p = 1;
    rep(i, 0, n) {
        if (trie[p][str[i] - 'a'] == 0) {
            return false;
        }
        p = trie[p][str[i] - 'a'];
    }
    return endst[p];
}
