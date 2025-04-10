#include <bits/stdc++.h>
using namespace std;

truct Hash {
    vector<uint64_t> p1, h1, p2, h2;
    int base1, base2;
    const uint64_t mod1 = 1e9 + 7, mod2 = 1e9 + 9;

    Hash(int b1, int b2) {
        base1 = b1;
        base2 = b2;
    }

    void build(const string &s) {
        int n = s.size();
        p1.resize(n + 1, 1); h1.resize(n + 1, 0);
        p2.resize(n + 1, 1); h2.resize(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            p1[i] = (p1[i - 1] * base1) % mod1;
            h1[i] = (h1[i - 1] * base1 + (s[i - 1] - 'a' + 1)) % mod1;
            
            p2[i] = (p2[i - 1] * base2) % mod2;
            h2[i] = (h2[i - 1] * base2 + (s[i - 1] - 'a' + 1)) % mod2;
        }
    }

    pair<uint64_t, uint64_t> get(int l, int r) {
        uint64_t hash1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
        uint64_t hash2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
        return {hash1, hash2};
    }
};