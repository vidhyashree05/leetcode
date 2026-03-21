class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        // Loop through half the rows of the k x k submatrix
        for (int i = 0; i < k / 2; i++) {
            
            int topRow = x + i;
            int bottomRow = x + (k - 1 - i);
            
            // Swap elements column-wise within the submatrix
            for (int j = 0; j < k; j++) {
                int col = y + j;
                swap(grid[topRow][col], grid[bottomRow][col]);
            }
        }
        
        return grid;
    }
};