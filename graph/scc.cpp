#include <bits/stdc++.h>

constexpr int N = 10010;

struct SCC {
    int n, idx, cnt;
    std::vector<int> p[N];
    std::vector<int> low, bel, dfn, ins;
    std::vector<std::vector<int>> scc;
    std::stack<int> stk;
    std::vector<int> sz;

    SCC(int n) {
        this -> n = n;
        low.resize(n + 1, 0);
        bel.resize(n + 1, 0);
        dfn.resize(n + 1, 0);
        ins.resize(n + 1, 0);
        sz.resize(n + 1, 0);
        idx = cnt = 0;
    }

    void dfs(int x) {
        low[x] = dfn[x] = ++idx;
        ins[x] = true;
        stk.push(x);

        for (auto v : p[x]) {
            if (!dfn[v]) dfs(v);
            if (ins[v]) low[x] = std::min(low[x], low[v]);
        }

        if (dfn[x] == low[x]) {
            ++cnt;
            std::vector<int> c;
            while (true) {
                int v = stk.top();
                stk.pop();
                c.push_back(v);
                bel[v] = cnt;
                sz[cnt]++;
                ins[v] = false;
                if (v == x) {
                    break;
                }
            }
            scc.push_back(c);
        }
    }

    void solve() {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) dfs(i);
        }
    }

    std::vector<std::vector<int>> get_scc() {
        return scc;
    }

    int get_bel(int x) {
        return bel[x];
    }

    void add_edge(int x, int y) {
        p[x].push_back(y);
    }
};

// Easy version
int low[N], ins[N], dfn[N], sz[N], siz;
int idx, cnt;
std::vector<int> scc[N];

void dfs(int x) {
	low[x] = dfn[x] = ++idx;
	ins[x] = true;
	stk.push(x);

	for (auto v : p[x]) {
		if (!dfn[v]) dfs(v);
		if (ins[v]) low[x] = std::min(low[x], low[v]);
	}

	if (dfn[x] == low[x]) {
		++cnt;
		int siz = 0;
		while (true) {
			int v = stk.top();
			stk.pop();
			scc[++siz] = v;
			bel[v] = cnt;
			ins[v] = false;
			if (v == x) {
				break;
			}
		}
		sz[cnt] = siz;
	}
}
