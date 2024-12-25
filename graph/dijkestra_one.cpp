#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

	int _find() {
		int res = 0x3f3f3f3f;
		int bRet = -1;
		for (int i = 1; i <= n; i++) {
			if (!isV[i] && dist[i] <= res) {
				res = dist[i];
				bRet = i;
			}
		}
		return bRet;
	}

	void solve(int src) {
		fill(dist.begin(), dist.end(), 0x3f3f3f3f);
		fill(isV.begin(), isV.end(), 0);
		dist[src] = 0;
		for (int i = 1; i <= n; i++) {
			int t = _find();
			isV[t] = 1;
			for (auto j : _path[t]) {
				if (!isV[j.first] && dist[j.first] > dist[t] + j.second) {
					dist[j.first] = j.second + dist[t];
				}
			}
		}
	}

	T dis(int x) {
		return dist[x];
	}
};

