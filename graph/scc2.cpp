#include <bits/stdc++.h>

int dfn[N], cur, cnt, bel[N], low[N];
std::stack<int> stk;
std::vector<std::vector<int>> adj;

void dfs(int u) {
    low[u] = dfn[u] = ++cur;
    stk.push(u);
    for (auto v : adj[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = std::min(low[u], low[v]);
        } else if (!bel[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        int y;
        cnt = 0;
        do {
            y = stk.top();
            stk.pop();
            bel[y] = cnt;
        } while (y != u);
        cnt++;
    }
}