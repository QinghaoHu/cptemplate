#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else 
#define debug(...) 42
#endif

#define trav(a, x) for (auto& a : x)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)

template<typename T> T gcd(T a, T b) {return (!b ? a : gcd(b, a%b));}
template<typename T> T lcm(T a, T b) {return (a / gcd(a, b) * b);}

template<typename T, typename K> bool ckmin(T &a, K b) {return  b<a ? a=b, 1 : 0;}
template<typename T, typename K> bool ckmax(T &a, K b) {return  b>a ? a=b, 1 : 0;}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    return 0;
}
