class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    int n;

    bool isSafe(int row, int col,
                vector<bool>& cols,
                vector<bool>& diag1,
                vector<bool>& diag2) {
        return !cols[col] && !diag1[row - col + n - 1] && !diag2[row + col];
    }

    void backtrack(int row,
                   vector<bool>& cols,
                   vector<bool>& diag1,
                   vector<bool>& diag2) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, cols, diag1, diag2)) {
                board[row][col] = 'Q';
                cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

                backtrack(row + 1, cols, diag1, diag2);

                board[row][col] = '.';
                cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        board = vector<string>(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false); 
        vector<bool> diag2(2 * n - 1, false); 
        backtrack(0, cols, diag1, diag2);
        return res;
    }
};
