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
ll powmod(ll a, ll b, ll p) { ll res=1; for(;b;b>>=1){ if(b&1){ res=res*a%p;} a=a*a%p;} return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

struct DSU {
    std::vector<T> _f, _siz;

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        _f.assign(n, 0);
        std::iota(_f.begin(), _f.end(), 0);
        _siz.assign(n, 1);
    }

    int find(int x) {
        if (x != _f[x]) {
            _f[x] = _find(_f[x]);
        }
        return _f[x];
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        f[y] = x;
        return true;
    }
};