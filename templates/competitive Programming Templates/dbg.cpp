/*
 *	Author: Qinghao Hu
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else 
#define debug(...) 42
#endif

typedef long long i64;
typedef long double u64;

#define trav(a, x) for (auto& a : x)
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= a; i--)

template<typename T> T gcd(T a, T b) {return (!b ? a : gcd(b, a%b));}
template<typename T> T lcm(T a, T b) {return (a / gcd(a, b) * b);}
template<typename T, typename K> bool ckmin(T &a, K b) {return  b<a ? a=b, 1 : 0;}
template<typename T, typename K> bool ckmax(T &a, K b) {return  b>a ? a=b, 1 : 0;}

void solve() {


}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int tt = 1;
	// cin >> tt;

	rep(i, 0, tt) solve();

	return 0;
}
