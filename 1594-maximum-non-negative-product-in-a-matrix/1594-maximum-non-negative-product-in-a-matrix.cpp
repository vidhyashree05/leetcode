class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const long long MOD = 1e9 + 7;

        // max_dp[i][j] = maximum product to reach (i, j)
        // min_dp[i][j] = minimum product to reach (i, j)
        vector<vector<long long>> max_dp(m, vector<long long>(n));
        vector<vector<long long>> min_dp(m, vector<long long>(n));

        // Initialize starting cell
        max_dp[0][0] = min_dp[0][0] = grid[0][0];

        // Fill first column (only possible from top)
        for (int i = 1; i < m; i++) {
            max_dp[i][0] = min_dp[i][0] = max_dp[i - 1][0] * grid[i][0];
        }

        // Fill first row (only possible from left)
        for (int j = 1; j < n; j++) {
            max_dp[0][j] = min_dp[0][j] = max_dp[0][j - 1] * grid[0][j];
        }

        // Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];

                // Compute all possible products from top and left
                long long a = max_dp[i - 1][j] * val;
                long long b = min_dp[i - 1][j] * val;
                long long c = max_dp[i][j - 1] * val;
                long long d = min_dp[i][j - 1] * val;

                // Take maximum and minimum among candidates
                max_dp[i][j] = max({a, b, c, d});
                min_dp[i][j] = min({a, b, c, d});
            }
        }

        long long result = max_dp[m - 1][n - 1];

        // If result is negative, no non-negative product exists
        if (result < 0) return -1;

        // Return result modulo 1e9+7
        return result % MOD;
    }
};