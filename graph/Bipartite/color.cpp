#include <bits/stdc++.h>

constexpr int N = 101000;

std::vector<int> e[N];
int color[N];

bool colored(int u, int c) {
	for (auto x : e[u]) {
		if (color[x]) {
			if (color[x] == c) return false;
		} else if (!colored(x, 3 - c)) {
			return false;
		}
	}
	return true;
}