#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct linear_basis {
    ll num[61] {};
    bool insert(ll x) {
        for (int i = 59; i >= 0; i--) {
            if (x & (1ll << i)) {
                if (num[i] == 0) {
                    num[i] = x;
                    return true;
                } else {
                    x ^= num[i];
                }
            }
        }
        return false;
    }

    ll queryMin(ll x) {
        for (int i = 59; i >= 0; i--) {
            x = min(x, x ^ num[i]);
        }
        return x;
    }

    ll queryMax(ll x) {
        for (int i = 59; i >= 0; i--) {
            x = max(x, x ^ num[i]);
        }
        return x;
    }
};
// xor amount of cases
// Can be represent by myself.
