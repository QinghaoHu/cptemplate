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
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 1e6 + 10;

// Here is the template

template<typename T>
bool is_prime(T n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Eratosthenes:
array<bool, N> v;

void primes(int n) {
    fill(all(v), false);
    for (int i = 2; i <= n; i++) {
        if (v[i] == true) {
            continue;
        }
        cout << i << " \n";
        for (int j = i; j <= n / i; j++) {
            v[i * j] = true;
        }
    }
}

//Solve Eratosthenes in the O(n)
array<int, N> vs, prime;

void get_primes(int n) {
    fill(all(vs), 0);
    int m = 0;
    for (int i = 2; i <= n; i++) {
        if (vs[i] == 0) {
            v[i] = i;
            prime[++m] = i;
        }
        for (int j = 1; j <= m; j++) {
            if (prime[j] > v[i] || prime[j] > n / i) {
                break;
            }
            vs[i * prime[j]] = prime[j];
        }
    }
}
