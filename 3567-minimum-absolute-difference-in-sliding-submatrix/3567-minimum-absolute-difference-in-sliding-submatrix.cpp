#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Result matrix of size (m-k+1) x (n-k+1)
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        
        // Traverse all possible top-left corners of k x k submatrices
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                
                vector<int> elements;
                
                // Collect elements of current k x k submatrix
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        elements.push_back(grid[x][y]);
                    }
                }
                
                // Sort elements
                sort(elements.begin(), elements.end());
                
                int minDiff = INT_MAX;
                
                // Find minimum absolute difference between distinct elements
                for (int t = 1; t < elements.size(); t++) {
                    if (elements[t] != elements[t - 1]) {
                        minDiff = min(minDiff, elements[t] - elements[t - 1]);
                    }
                }
                
                // If all elements are same → minDiff remains INT_MAX
                if (minDiff == INT_MAX) minDiff = 0;
                
                ans[i][j] = minDiff;
            }
        }
        
        return ans;
    }
};