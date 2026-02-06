class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();

        // Length check
        if (n + m != s3.size())
            return false;

        // dp[i][j] = can s1[0..i-1] and s2[0..j-1]
        // form s3[0..i+j-1]
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Empty strings form empty string
        dp[0][0] = true;

        // Fill first column (only s1 used)
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // Fill first row (only s2 used)
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Fill rest of DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Take from s1 OR take from s2
                dp[i][j] =
                    (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                    (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[n][m];
    }
};
