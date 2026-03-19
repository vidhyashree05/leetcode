class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 0));
        vector<vector<int>> countX(m, vector<int>(n, 0));

        // Build prefix sum and X count
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int val = 0;
                if (grid[i][j] == 'X') val = 1;
                else if (grid[i][j] == 'Y') val = -1;

                int x_val = (grid[i][j] == 'X') ? 1 : 0;

                prefix[i][j] = val;
                countX[i][j] = x_val;

                if (i > 0) {
                    prefix[i][j] += prefix[i - 1][j];
                    countX[i][j] += countX[i - 1][j];
                }
                if (j > 0) {
                    prefix[i][j] += prefix[i][j - 1];
                    countX[i][j] += countX[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i - 1][j - 1];
                    countX[i][j] -= countX[i - 1][j - 1];
                }
            }
        }

        int ans = 0;

        // Count valid submatrices
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (prefix[i][j] == 0 && countX[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};