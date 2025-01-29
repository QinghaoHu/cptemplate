#include <bits/stdc++.h>

constexpr int N = 101000;

int match[N];
bool st[N];
std::vector<int> e[N];

bool hungary(int u) {
	for (auto x : e[u]) {
		if (!st[x]) {
			st[x] = true;
			if (match[x] == -1 || find(match[x])) {
				match[x] = u;
				return true;
			}
		}
	}
	return false;
}