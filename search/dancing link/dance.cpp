#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);}

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 5505;

int n, m, cnt;
int u[N], d[N], l[N], r[N]; // up, down, right, left for the point
int row[N], col[N]; // The row and col each point sit at
int h[N]; // the top point in the column
int s[N]; // The number of points in each row
int ans[N]; // Is this column selection

void init() {
    for (int y = 0; y <= m; y++) {
        u[y] = d[y] = y;
        l[y] = y - 1, r[y] = y + 1;
    }
    l[0] = m; r[m] = 0; cnt = m;
}

void link(int x, int y) {
	row[++cnt] = x; col[cnt] = y; s[y]++;
	 u[cnt] = u[y];
	 d[u[y]] = cnt;
	 d[cnt] = y;
	 u[y] = cnt;
	 if (h[x] == 0) {
		 h[x] = r[cnt] = l[cnt] = cnt;
	 } else {
		 l[cnt] = l[h[x]];
		 r[l[h[x]]] = cnt;
		 r[cnt] = h[x];
		 l[h[x]] = cnt;  
	 }
}

void remove(int y) {
	r[l[y]] = r[y], l[r[y]] = l[y];
	for (int i = d[i]; i != y; i = d[i]) {
		for (int j = r[i]; j != i; j = r[j]) {
			u[d[j]] = u[j]; d[u[j]] = d[j]; s[col[j]]--;
		}
	}
}

void resume (int y) {
	r[l[y]] = y; l[r[y]] = y;
	for (int i = u[y]; i != y; i = u[i]) {
		for (int j = l[i]; j != i; j = l[j]) {
			u[d[j]] = j, d[u[j]] = j, s[col[j]]++;
		}
	}
}

bool dance(int dep) {
	if (r[0] == 0) {
		for (int i = 0; i < dep; i++) {
			cout << ans[i] << " ";
		}
		return true;
	}
	int y = r[0];
	for (int i = r[0]; i; i = r[i]) {
		if (s[i] < s[y]) {
			y = i;
		}
	}
	remove(y);
	for (int i = d[y]; i != y; i = d[i]) {
		ans[dep] = row[i];
		for (int j = r[i]; j != i; j = r[j]) {
			remove(col[j]);
		}
		if (dance(dep + 1)) {
			return true;
		}
		for (int j = l[i]; j != i; j = l[j]) {
			resume(col[j]);
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}
