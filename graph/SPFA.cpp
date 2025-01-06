#include <bits/stdc++.h>

using ll = long long;

template <typename T>
struct SPFA {
	int n, m;
	std::vector<std::vector<std::pair<int, T>>> _path;
	std::vector<T> dist; std::vector<int> isV;
	
	SPFA(int nl, int ml) {
		this -> n = nl;
		this -> m = ml;
		dist.resize(n + 1), isV.resize(n + 1);
		_path.resize(n + 1);
	}
	
	void addEdge(int x, int y, int z) {
		_path[x].push_back(std::make_pair(y, z));
	}
	
	void solve(int src) {
		std::fill(dist.begin(), dist.end(), 0x3f3f3f3f);
		std::fill(isV.begin(), isV.end(), 0);
		dist[src] = 0;
		std::queue<int> q;
		isV[src] = 1;
		q.push(src);
		while (!q.empty()) {
			int t = q.front(); q.pop();
			isV[t] = 0;
			for (auto [i, j] : _path[t]) {
				if (dist[i] > dist[t] + j) {
					dist[i] = dist[t] + j;
					if (!isV[i]) {
						q.push(i);
						isV[i] = 1;
					}
				}
			}
		}
	}
	
	T dis(int x) {
		return dist[x];
	}
};
