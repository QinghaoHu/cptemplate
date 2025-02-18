#include <bits/stdc++.h>

template <typename T>
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
		_f[y] = x;
		return true;
	}
};
