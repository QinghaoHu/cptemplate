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
//Here is the template useful for the project

template <typename T, int MAX_SIZE>
class Nodes {
public:
    int head, tail, tot;
    struct Node {
        T val;
        int prev, next;
    };
    Node nodes[MAX_SIZE];

    Nodes() {
        head = 1, tail = 2;
        tot = 2;
        nodes[head].next = tail;
        nodes[tail].prev = head;
    }

    void add(int p, T value) {
        nodes[tot].val = value;
        nodes[tot].next = nodes[p].next;
        nodes[nodes[p].next].prev = tot;
        nodes[p].next = tot;
        nodes[tot].prev = p;
        ++tot;
    }

    void del(int p) {
        nodes[nodes[p].prev].next = nodes[p].next;
        nodes[nodes[p].next].prev = nodes[p].prev;
    }

    int prev(int n) const {
        return nodes[n].prev;
    }

    int next(int n) const {
        return nodes[n].next;
    }

    void modify(int p, T value) {
        nodes[p].val = value;
    }

    void clear() {
        head = tail = tot = 0;
    }
};

