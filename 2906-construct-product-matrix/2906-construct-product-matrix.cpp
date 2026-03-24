class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        
        // Step 1: Flatten the grid into a 1D array
        vector<long long> arr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[i][j] % mod);
            }
        }
        
        int size = arr.size();
        
        // Step 2: Prefix product
        vector<long long> prefix(size, 1);
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
        }
        
        // Step 3: Suffix product
        vector<long long> suffix(size, 1);
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
        }
        
        // Step 4: Compute result using prefix * suffix
        vector<vector<int>> result(n, vector<int>(m));
        int idx = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = (prefix[idx] * suffix[idx]) % mod;
                idx++;
            }
        }
        
        return result;
    }
};