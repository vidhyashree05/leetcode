#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Expand factory positions based on limit
        vector<int> slots;
        for (auto &f : factory) {
            int pos = f[0], limit = f[1];
            for (int i = 0; i < limit; i++) {
                slots.push_back(pos);
            }
        }

        int n = robot.size();
        int m = slots.size();

        // DP table
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));

        // Base case
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        // Fill DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // skip this slot
                dp[i][j] = dp[i][j - 1];

                // assign robot i-1 to slot j-1
                if (dp[i - 1][j - 1] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j],
                        dp[i - 1][j - 1] + abs(robot[i - 1] - slots[j - 1]));
                }
            }
        }

        return dp[n][m];
    }
};