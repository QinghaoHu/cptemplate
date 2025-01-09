#include <bits/stdc++.h>

struct DECC {
	int n, cur, cnt;
	std::vector<std::vector<std::pair<int, int>>> adj;
	std::vector<int> cut;
	std::vector<int> dfn, low, bridge;
	int idx;

	DECC(int n) {
		init(n);
	}

	void init(int n) {
		this -> n = n;
		adj.resize(n + 1, {});
		cut.resize(n + 1, 0);
		dfn.resize(n + 1, 0);
		low.resize(n + 1, 0);
		cur = cnt = 0;
	}

	void add_edge(int x, int y) {
		adj[x].push_back(std::make_pair(y, idx));
		adj[y].push_back(std::make_pair(x, idx));
		idx++;
	}

	void dfs(int u, int id) {
		low[u] = dfn[u] = ++cur;
		for (auto [v, id2] : adj[u]) {
			if (!dfn[v]) {
				dfs(v, id2);
				low[u] = std::min(low[v], low[u]);
				if (dfn[v] == low[v]) bridge.push_back(id2 + 1); 
			} else if (id2 != id) {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
	}

	void solve() {
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) dfs(i, -1);
		}
	}

	std::vector<int> work() {
		return bridge;
	}
};