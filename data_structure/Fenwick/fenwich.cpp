#include <bits/stdc++.h>
using namespace std;

const int N = 201000;

template <typename T>
struct BIT {
	int size;
	std::vector<T> a;

	BIT(): size(N), a(N, 0) {}
	BIT(int x): size(x), a(x + 1, 0) {}

	void modify(int x, T s) {
		for (; x <= size; x += (x & -x)) {
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
};
