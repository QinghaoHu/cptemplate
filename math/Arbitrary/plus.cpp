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
#define arr array
#define SZ(x) ((int)x.size())
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif
// Here is the header

vector<int> A, B;

void get(string a, string b) {
    reverse(all(a)); reverse(all(b));
    for (auto i : a) {
        A.pb(i - '0');
    }
    for (auto i : b) {
        B.pb(i - '0');
    }
}

vector<int> add (vector<int> &A, vector<int> &B) {
    if (SZ(A) < SZ(B)) return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < SZ(A); i++) {
        t += A[i];
        if (i < SZ(B)) t += B[i];
        C.pb(t % 10);
        t /= 10;
    }
    if (t) C.pb(t);
    return C;
}

