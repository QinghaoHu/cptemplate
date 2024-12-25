#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Dijkestra {
	int n, m;
	vector<vector<pair<int, T>>> _path;
	vector<T> dist;
	vector<int> isV;

	Dijkestra(int n, int m) {
		this -> n = n;
		this -> m = m;
		_path.resize(n + 1);
		dist.resize(n + 1), isV.resize(n + 1);
	}

	void addEdge(int x, int y, int z) {
		_path[x].push_back(make_pair(y, z));
	}

	void solve(int src) {
		fill(dist.begin(), dist.end(), 0x3f3f3f3f);
		fill(isV.begin(), isV.end(), 0);
		dist[src] = 0;
		priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
		pq.push(make_pair(0, src));
		while (!pq.empty()) {
			auto t = pq.top();
			pq.pop();
			if (isV[t.second]) continue;
			isV[t.second] = true;
			for (auto i : _path[t.second]) {
				if (!isV[i.first] && dist[i.first] > dist[t.second] + i.second) {
					dist[i.first] = dist[t.second] + i.second;
					pq.push(make_pair(dist[i.first], i.first));
				}
			}
		}
	}

	T dis(int x) {
		return dist[x];
	}
};
