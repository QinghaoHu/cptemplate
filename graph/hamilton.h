void hamilton(vector<vector<int> > weight, int n) {
    int dp[1 << n][n];
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int i = 0; i < 1 << n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (i >> j & 1) {
                for (int k = 0; k < n; ++ k) {
                    if ((i - (1 << j)) >> k & 1) {
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + weight[k][j]);
                    }
                }
            }
        }
    }
    return dp[(1 << n) - 1][n - 1];
}
