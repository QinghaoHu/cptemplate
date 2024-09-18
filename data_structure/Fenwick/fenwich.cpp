#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
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
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

template <typename T>
struct Fenwick {
	int n;
	std::vector<T> a;

	Fenwick(int x) {
		init(x);
	}

	void init(int n) {
		this.n = n;
		a.assign(n + 1, T());
	}

	void modify(int x, T s) {
		for (; x <= n; x += (x & -x)) {
			a[x] += s;
		}
	}

	T query(int x) {
		T s{};
		for (; x; x -= (x & -x)) {
			s += a[x];
		}
		return s;
	}

	T rangeSum(int x, int y) {
		return query(y) - query(x);
	}
}