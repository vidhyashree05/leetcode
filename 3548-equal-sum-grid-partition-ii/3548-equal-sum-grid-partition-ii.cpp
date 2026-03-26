class Solution {
public:

    // Rotate matrix 90° clockwise
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> tmp(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {

        long long total = 0;

        //  Calculate total sum
        for (auto &row : grid)
            for (int x : row)
                total += x;

        //  Try 4 rotations (cover all directions)
        for (int k = 0; k < 4; k++) {

            int m = grid.size();
            int n = grid[0].size();

            //  If only 1 row → can't cut horizontally
            if (m < 2) {
                grid = rotation(grid);
                continue;
            }

            long long sum = 0;
            unordered_set<long long> exist;

            // Stores values in top section
            exist.insert(0);

            // Special case: single column
            if (n == 1) {
                for (int i = 0; i < m - 1; i++) {
                    sum += grid[i][0];

                    // tag = difference needed
                    long long tag = sum * 2 - total;

                    // Check:
                    // 1. equal sum
                    // 2. remove top edge
                    // 3. remove bottom edge
                    if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                        return true;
                    }
                }

                grid = rotation(grid);
                continue;
            }

            //  Normal case (2D grid)
            for (int i = 0; i < m - 1; i++) {

                // add row to top section
                for (int j = 0; j < n; j++) {
                    exist.insert(grid[i][j]);
                    sum += grid[i][j];
                }

                long long tag = sum * 2 - total;

                //  First row special (edge connectivity)
                if (i == 0) {
                    if (tag == 0 ||
                        tag == grid[0][0] ||        // left edge
                        tag == grid[0][n - 1]) {   // right edge
                        return true;
                    }
                    continue;
                }

                // Main check:
                // If we can remove one value = tag
                if (exist.count(tag)) {
                    return true;
                }
            }

            //  Rotate for next direction
            grid = rotation(grid);
        }

        return false;
    }
};