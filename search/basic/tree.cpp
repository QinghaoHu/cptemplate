#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)
const int N = 100010;

vector<int> a[N];
bool st[N];

// using dfs to search the tree
void dfs(int x){
    st[x] = 1;
    for (auto s :a[x]){
        if (!st[x]) dfs(s);
    }
}

//DFS order
int order[N];
int m;

void dfs1 (int x) {
    order[++m] = x;
    st[x] = 1;
    for (auto s :a[x]) {
        if (!st[x]) {
            dfs(s);
        }
    }
    order[++m] = x;
}

// The depth of a tree
int depth[N];
void dfs2(int x) {
    st[x] = true;
    for (auto s : a[x]) {
        if (!st[x]) {
            depth[s] = depth[x] + 1;
            dfs(s);
        }
    }
}

//The centre of the tree:
int si[N];
int ans = 0, pos = 0;

void dfs3(int x) {
    st[x] = 1;
    si[x] = 1;
    int max_part = 0;
    for (auto s : a[x]) {
        if (!st[x]) {
            dfs(x);
            si[x] += si[s];
            max_part = max(max_part, si[x]);
        }
    }
    max_part = max(max_part, n - si[x]);
    if (max_part < ans) {
        ans = max_part;
        pos = x;
    }
}

// Count how many tree in this forest

int v[N]; //Count which point belong to which tree:
int cnt = 0;

void dfs4(int x) {
    v[x] = cnt;
    for (auto s : a[x]) {
        if (v[s] == 0) {
            dfs(s);
        }
    }
}

void cntForest () {
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            ++cnt;
            dfs(i);
        }
    }
}

//Topsort
int deg[N];
cnt = 0;
void topsort() {
    queue<int> heap;
    for (int i = 1; i <= n; i++) {
        if (d!eg[i]) {
            heap.push(i);
        }
    }
    while (heap.size()) {
        int x = heap.front(); heap.pop();
        a[++cnt] = x;
        for (auto s : a[x]) {
            deg[s]--;
            if (deg[s] == 0) {
                heap.push(s);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}
