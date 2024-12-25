#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
struct Prim {
	int n;
	vector<vector<T>> d;
	vector<int> dist, isV;

	Prim() {}
	Prim(int n) {
		init(n);
	}

	void init(int n) {
		this -> n = n;
		d.resize(n, vector<T>(n, 2e9));
		dist.resize(n + 1, 2e9);
		isV.resize(n + 1, 0);
	}

	void add_edge(int x, int y, T z) {
		a[x][y] = min(a[x][y], z);
	}

	void solve() {
		d[1] = 0;
		for (int i = 1; i <= n; i++) {
			int x = 0;
			for (int j = 1; j <= n; j++) {
				if (!v[j] && (x == 0 || d[x] > d[j])) x = j;
			}
			v[x] = 1;
			for (int y = 1; y <= n; y++) {
				if (!v[y]) d[y] = min(d[y], d[x][y]);
			}
		}
	}

	T dis(int x) {
		return dist[x];
	}
};
