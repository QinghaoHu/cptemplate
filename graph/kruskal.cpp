#include <bits/stdc++.h>

template <typename T>
struct Kruskal {
	struct rec { 
		int x, y; T z;
		bool operator < (const rec B) const {
			return z < B.z;
		} 
	};
	int n;
	T ans;
	std::vector<int> fa;
	std::vector<rec> edge;

	Kruskal() {}
	Kruskal(int n) {
		init(n);
	}

	int _find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = _find(fa[x]);
	}

	void init(int n) {
		this -> n = n;
		fa.resize(n + 1, 0);
		ans = 0;
		iota(fa.begin(), fa.end(), 0);
		edge.clear();
	}

	void addEdge(int a, int b, T z) {
		edge.push_back({a, b, z});
	} 

	void solve() {
		std::vector<char> v; 
		std::sort(edge.begin(), edge.end());
		for (auto i : edge) {
			int a = _find(i.x);
			int b = _find(i.y);
			if (a == b) continue;
			ans += i.z;
			fa[a] = b;
		}
	}

	T get_ans() {
		return ans;
	}

};