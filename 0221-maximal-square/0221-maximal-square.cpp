class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // DP table initialized with 0
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int maxSide = 0;  // store maximum square side
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // If cell contains '1'
                if (matrix[i][j] == '1') {
                    
                    // First row or first column
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } 
                    else {
                        // Apply DP formula
                        dp[i][j] = 1 + min({
                            dp[i-1][j],      // top
                            dp[i][j-1],      // left
                            dp[i-1][j-1]     // diagonal
                        });
                    }
                    
                    // Update maximum side length
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        
        // Return area (side × side)
        return maxSide * maxSide;
    }
};