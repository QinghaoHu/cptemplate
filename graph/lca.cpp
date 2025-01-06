#include <bits/stdc++.h>

// By BFS
// vector<int> head(MAXN), nxt(MAXN), ver(MAXN), edge(MAXN);
// int d[MAXN], dist[MAXN], f[MAXN][LOG];
std::vector<int> head(), nxt(), ver(), edge();
std::vector<int> f(), d();
std::vector<int> dist();
void bfs(int n, int root) {
    std::queue<int> q;
    d[root] = 1;
    q.push(root);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i]; 
            if (d[y]) continue;
            d[y] = d[x] + 1;
            //dist[y] = dist[x] + edge[i];
            f[y][0] = x;
            for (int j = 1; j < LOG; j++) {
                f[y][j] = f[f[y][j - 1]][j - 1];
            }
            q.push(y);
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) std::swap(x, y);
    for (int i = LOG - 1; i >= 0; i--) {
        if (d[f[x][i]] >= d[y]) x = f[x][i];
    }
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

// By Tarjan
std::vector<int> fa();
std::vector<int> ans();
std::vector<int> head(), nxt(), ver(), edge();
std::vector f();
std::vector<int> dist();
std::vector<std::vector<std::pair<int, int>>> query;
int get(int x) {
	return (x == fa[x] ? x : (fa[x] = get(fa[x])));
}

void tarjan(int x) {
	v[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (v[y]) continue;
		d[y] = d[x] + edge[i];
		tarjan(y);
		fa[y] = x;
	}
	for (int i = 0; i < (int)query[x].size(); i++) {
		int y = query[x].first, y = query[x].second;
		if (v[y] == 2) {
			int lca = get(y);
			ans[id] = std::min(ans[id], d[x] + d[y] - 2 * d[lca]);
		}
	}
	v[x] = 2;
}
