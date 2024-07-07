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

const int N = 1e6 + 10;

struct node {
    int val;
    int prev, next;
} nodes[N];

int head, tail, tot;

void init() {
    head = 1, tail = 2;
    tot = 2;
    nodes[head].next = 2;
    nodes[tail].prev = 1;
}

void add(int p, int value) {
    nodes[++tot].val = value;
    nodes[tot].next = nodes[p].next;
    nodes[nodes[p].next].prev = tot;
    nodes[p].next = tot;
    nodes[tot].prev = p;
}

void del(int p) {
    nodes[nodes[p].prev].next = nodes[p].next;
    nodes[nodes[p].next].prev = nodes[p].prev;
}

void clear() {
    memset(nodes, 0, sizeof nodes);
    head = tail = tot = 0;
}
