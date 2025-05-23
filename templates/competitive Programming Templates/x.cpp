#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else 
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define trav(a, x) for (auto& a : x)
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= a; i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void fast_OI() {
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
}

mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}

template<typename T> T gcd(T a, T b) {return (!b ? a : gcd(b, a%b));}
template<typename T> T lcm(T a, T b) {return (a / gcd(a, b) * b);}
template<typename T, typename K> bool ckmin(T &a, K b) {return  b<a ? a=b, 1 : 0;}
template<typename T, typename K> bool ckmax(T &a, K b) {return  b>a ? a=b, 1 : 0;}
// header

void solve() {


}

int main() {
	fast_OI();

	int tt = 1;
	// cin >> tt;

	rep(i, 1, tt + 1) {
		startTime = clock();
		bool sp = 0;
		// sp = 1;
		if (sp)
			eprintf("___ Case %d start___\n", i);

		solve();

		// if (solve) {
		// 	cout << "YES\n";
		// } else {
		// 	cout << "NO\n";
		// }

		if (sp) {
			eprintf("___ Case # %d end ___\n", i);
			eprintf("Time = %.4f\n", getCurrentTime());
			eprintf("+++++++++++++++++++\n\n");
		}
	}

	return 0;
}
