class Solution {
public:
    
    // This will store all valid combinations
    vector<vector<int>> result;
    
    // Backtracking function
    void backtrack(int start, int k, int n, vector<int>& current) {
        
        //If we selected exactly k numbers AND sum becomes 0
        // We found a valid combination
        if (k == 0 && n == 0) {
            result.push_back(current);
            return;
        }
        
        // If:
        // 1. We selected k numbers but sum is not 0
        // 2. Sum becomes negative
        // Then this path is invalid
        if (k == 0 || n < 0) {
            return;
        }
        
        // Try numbers from 'start' to 9
        for (int i = start; i <= 9; i++) {
            
            // Optimization: if current number is greater than remaining sum
            // no need to continue
            if (i > n) break;
            
            // Choose the number
            current.push_back(i);
            
            // Recurse:
            // i + 1 → ensure each number is used only once
            // k - 1 → we picked one number
            // n - i → reduce remaining sum
            backtrack(i + 1, k - 1, n - i, current);
            
            // Backtrack:
            // Remove last number and try next possibility
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;          // temporary combination
        backtrack(1, k, n, current);  // start from number 1
        return result;
    }
};