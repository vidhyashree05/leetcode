#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // dp[j][c] = max score at column j with cost c
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        dp[0][0] = 0; // start

        for (int i = 0; i < m; i++) {
            vector<vector<int>> new_dp(n, vector<int>(k + 1, -1));

            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                int cost = (val == 0 ? 0 : 1);

                for (int c = 0; c <= k; c++) {
                    if (c < cost) continue;

                    int best = -1;

                    // from top
                    if (i > 0 && dp[j][c - cost] != -1) {
                        best = max(best, dp[j][c - cost] + val);
                    }

                    // from left
                    if (j > 0 && new_dp[j - 1][c - cost] != -1) {
                        best = max(best, new_dp[j - 1][c - cost] + val);
                    }

                    // start cell
                    if (i == 0 && j == 0 && c == 0) {
                        best = 0;
                    }

                    new_dp[j][c] = max(new_dp[j][c], best);
                }
            }

            dp = new_dp;
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n - 1][c]);
        }

        return ans; // always return
    }
};