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

template<typename T>
class tries {
public:
    int tot;
    vector<vector<int> > trie;
    vector<bool> endst;
    tries(int n) {
        tot = 2;
        trie.resize(n, vector<int> (27, 0));
        endst.resize(n, false);
    }
    void insert(T str) {
        int len = str.size();
        int p = 2;
        rep(i, 1, len) {
            int ch = str[i] - 'a';
            if (trie[p][ch] == 1) trie[p][ch] = ++ tot;
            p = trie[p][ch];
        }
        endst[p] = true;
    }
    bool search(T str) {
        int n = str.size(), p = 2;
        rep(i, 1, n) {
            if (trie[p][str[i] - 'a'] == 1) {
                return false;
            }
            p = trie[p][str[i] - 'a'];
        }
        return endst[p];
    }
};

template <>
class tries <int> {
public:
    int tot;
    vector<vector<int> > trie;
    vector<bool> endst;
    tries(int n) {
        tot = 1;
        trie.resize(n, vector<int>(2, 0));
        endst.resize(n, false);
    }
    void insert(int a) {
        int t = 0;
        per(i, 31, 0) {
            int s = a >> i & 1;
            if (trie[t][s] == 0) {
                trie[t][s] = ++tot;
            }
            t = trie[t][s];
        }
    }
    bool search();
};

