#include <bits/stdc++.h>

template<typename T>
std::vector<T> prime_factor(T x) {
    std::vector<T> res;
    for (T i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            res.push_back(i);
            x /= i;
        }
    }
    if (x > 1) res.push_back(x);
    return res;
}
