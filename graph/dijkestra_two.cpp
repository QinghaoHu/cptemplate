#include <bits/stdc++.h>

template <typename T>
struct Dijkestra {
	int n, m;
	std::vector<std::vector<std::pair<int, T>>> _path;
	std::vector<T> dist;
	std::vector<int> isV;

	Dijkestra(int n, int m) {
		this -> n = n;
		this -> m = m;
		_path.resize(n + 1);
		dist.resize(n + 1), isV.resize(n + 1);
	}

	void addEdge(int x, int y, int z) {
		_path[x].push_back(std::make_pair(y, z));
	}

	void solve(int src) {
		fill(dist.begin(), dist.end(), 0x3f3f3f3f);
		fill(isV.begin(), isV.end(), 0);
		dist[src] = 0;
		std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> pq;
		pq.push(std::make_pair(0, src));
		while (!pq.empty()) {
			auto t = pq.top();
			pq.pop();
			if (isV[t.second]) continue;
			isV[t.second] = true;
			for (auto i : _path[t.second]) {
				if (!isV[i.first] && dist[i.first] > dist[t.second] + i.second) {
					dist[i.first] = dist[t.second] + i.second;
					pq.push(std::make_pair(dist[i.first], i.first));
				}
			}
		}
	}

	T dis(int x) {
		return dist[x];
	}
};
