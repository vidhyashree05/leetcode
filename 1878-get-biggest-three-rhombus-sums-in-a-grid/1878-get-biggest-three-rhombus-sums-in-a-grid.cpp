class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> sums;

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                
                // radius 0 rhombus
                sums.insert(grid[r][c]);

                int k = 1;
                
                while(r-k >= 0 && r+k < m && c-k >= 0 && c+k < n) {
                    int total = 0;

                    // top -> right
                    for(int i = 0; i < k; i++)
                        total += grid[r-k+i][c+i];

                    // right -> bottom
                    for(int i = 0; i < k; i++)
                        total += grid[r+i][c+k-i];

                    // bottom -> left
                    for(int i = 0; i < k; i++)
                        total += grid[r+k-i][c-i];

                    // left -> top
                    for(int i = 0; i < k; i++)
                        total += grid[r-i][c-k+i];

                    sums.insert(total);
                    k++;
                }
            }
        }

        vector<int> result;
        
        for(auto it = sums.rbegin(); it != sums.rend() && result.size() < 3; it++)
            result.push_back(*it);

        return result;
    }
};