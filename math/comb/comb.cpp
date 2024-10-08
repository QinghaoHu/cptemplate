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
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

struct comb {
    vector<vector<int> > _c;
    // c[i][j] -> (i -> j)
    comb(int n) : c(n, vector<int>(n, 0)) {}

    void build1() {
        for (int i = 0; i < (int)c.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (!j) {
                    c[i][j] = 1;
                } else {
                    c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
                }
            }
        }
    }
}
