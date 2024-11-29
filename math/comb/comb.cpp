#include <bits/stdc++.h>
using namespace std;

template<typename T, int mod>
struct combMod {
    vector<T> fv, fvc;

    combMod(int n): fv(n), fvc(n) {}

    T powmod(T a, T b) {
        T c = 1;
        for (; b; b >>= 1) {
            if (b & 1) c = (c * a) % mod;
            a = (a * a) % mod;
        }
        return c % mod;
    }

    void init() {
        fv[0] = 1, fvc[0] = 1;
        for (int i = 1; i < fv.size(); i++) {
            fv[i] = fv[i - 1] * i % mod;
            fvc[i] = powmod(fv[i], mod - 2);
        }
    }

    T getC(T a, T b) {
        return fv[a] % mod * fvc[a - b] % mod * fvc[b] % mod;
    }
};
