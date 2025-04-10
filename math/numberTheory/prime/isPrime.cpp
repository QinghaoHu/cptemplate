#include <bits/stdc++.h>
using namespace std;

// Euler 
vector<int> minp, primes;

void sieve(int n) {
	minp.assign(n + 1, 0);
	primes.clear();

	for (int i = 2; i <= n; i++) {
		if (minp[i] == 0) {
			minp[i] = i;
			primes.push_back(i);
		}

		for (auto p : primes) {
			if (i * p > n) break;
			minp[i * p] = p;
			if (p == minp[i]) {
				break;
			}
		}
	}
}

bool isprime(int n) {
	return minp[n] == n;
}

// Euler
void sieve(int n) {
    minp.assign(n + 1, 0);
    phi.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            phi[i] = i - 1;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
    for (int i = 2; i <= n; i++) {
        phi[i] += phi[i - 1];
    }
}
