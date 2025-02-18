#include <bits/stdc++.h>

const int base = 131;
const int N = 1e6 + 10;

uint64_t p[N];

std::vector<uint64_t> a;
void init() {
    for (int i = 1; i <= N; i++) {
        p[i] = p[i - 1] * base;
    }
}

void hash(std::string s, std::vector<unsigned long long> &a) {
    for (int i = 1; i <= (int)s.size(); i++) {
        a[i] = a[i - 1] * base + s[i - 1] - 'a' + 1;
    }
}

int get(int l, int r, std::vector<uint64_t> &a) {
     int t = a[r] - a[l - 1] * p[r - l + 1];
     return t + UINT64_MAX;
}
