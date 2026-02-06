class Solution {
public:
    int numTrees(int n) {

        // dp[i] = number of unique BSTs with i nodes
        vector<int> dp(n + 1, 0);

        // Base cases
        dp[0] = 1;  // empty tree
        dp[1] = 1;  // single node

        // Fill dp table
        for (int nodes = 2; nodes <= n; nodes++) {

            // Try each node as root
            for (int root = 1; root <= nodes; root++) {

                // Left subtree has root - 1 nodes
                // Right subtree has nodes - root nodes
                dp[nodes] += dp[root - 1] * dp[nodes - root];
            }
        }

        return dp[n];
    }
};
