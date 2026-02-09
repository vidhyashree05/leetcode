class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Copy last row of triangle into dp
        vector<int> dp = triangle[n - 1];

        // Start from second last row and move upwards
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // Choose minimum of two adjacent numbers below
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        // dp[0] contains the minimum path sum
        return dp[0];
    }
};
