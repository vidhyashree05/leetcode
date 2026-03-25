class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total = 0;
        
        // Compute total sum
        for (auto &row : grid) {
            for (int val : row) {
                total += val;
            }
        }
        
        // If total is odd, cannot split equally
        if (total % 2 != 0) return false;
        
        long long target = total / 2;
        
        // Try horizontal cuts
        long long curr = 0;
        for (int i = 0; i < m - 1; i++) { // ensure bottom part non-empty
            for (int j = 0; j < n; j++) {
                curr += grid[i][j];
            }
            if (curr == target) return true;
        }
        
        // Try vertical cuts
        vector<long long> colSum(n, 0);
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }
        
        curr = 0;
        for (int j = 0; j < n - 1; j++) { // ensure right part non-empty
            curr += colSum[j];
            if (curr == target) return true;
        }
        
        return false;
    }
};