#include <bits/stdc++.h>
using namespace std;

vector<int> multipleFactor(int x) {
	vector<int> ans;
	int k = sqrt(x);
	for (int i = 1; i <= k; i++) {
		if (x % i == 0) {
			ans.emplace_back(i);
			if (i != x / i) {
				ans.emplace_back(x / i);
			}
		}
	}
	// sort(ans.begin(), ans.end());
	return ans;
}

vector<vector<int> > trialDivision (int n) {
    vector<vector<int>> factor(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n / i; j++) {
            factor[i *j].push_back(i);
        }
    }
    return factor;
}

