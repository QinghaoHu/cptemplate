#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
using namespace std;
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;
typedef pair<double, double> PDD;
const ll mod = 1e9 + 7;
const db eps = 1e-9;
const int INF = 0x3f3f3f3f;
//Here is the template useful for the project

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

bool cmp(vector<int> &A, vector<int> &B) {
    if (SZ(A) != SZ(B)) {
        return SZ(A) > SZ(B);
    }
    for (int i = SZ(A) - 1; i >= 0; i--) {
        if (A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < SZ(A); i++) {
        t = A[i] - t;
        if (i < SZ(B)) t -= B[i];
        if (t < 0) {
            C.pb((t + 10) % 10);
            t = 1;
        } else {
            C.pb(t);
        }
    }
    while(SZ(C) > 1 && C.back() == 0) C.pop_back();
    return C;
}
