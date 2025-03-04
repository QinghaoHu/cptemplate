#include <bits/stdc++.h>
using namespace std;

#define trav(a, x) for (auto& a : x)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)

template<typename T>
void _dbg(T x) {cerr << x << ' ';}
template<typename T>
void _dbgl(T x) {cerr << x << '\n';}
void _dbg(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void _dbgl(bool x) {cerr << (!x ? "false" : "true") << '\n';}

template<typename T>
void _dbg(std::vector<T> u) {for(auto i : u) _dbg(i);}
template<typename T>
void _dbgl(std::vector<T> u) {for(auto i : u) {_dbg(i);}; cerr << '\n';}
template<typename T, typename U>
void _dbg(std::pair<T, U> p) {cerr << "(" << p.first << ", " << p.second << ") ";}
template<typename T, typename U>
void _dbgl(std::pair<T, U> p) {cerr << "(" << p.first << ", " << p.second << ")\n";}

template<typename T> T gcd(T a, T b) {return (!b ? a : gcd(b, a%b));}
template<typename T> T lcm(T a, T b) {return (a / gcd(a, b) * b);}

template<typename T, typename K> bool ckmin(T &a, K b) {return  b<a ? a=b, 1 : 0;}
template<typename T, typename K> bool ckmax(T &a, K b) {return  b>a ? a=b, 1 : 0;}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    return 0;
}
