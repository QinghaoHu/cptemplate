#include <bits/stdc++.h>

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
std::array<bool, N> v;

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
std::array<int, N> vs, prime;

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
