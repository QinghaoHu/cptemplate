#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Floyd {
	int n;
	vector<vector<T>> d;

	Floyd(int n) {
		this -> n = n;
		d.resize(n + 1, vector<T>(n + 1, 2e9));
	}

	void add(int x, int y, T z) {
		d[x][y] = min(z, d[x][y]);
	}

	void solve() {
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				for (int k = 1; k <= n; k++) 
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}

	T query(int x, int y) {
		return d[x][y];
	}
};
