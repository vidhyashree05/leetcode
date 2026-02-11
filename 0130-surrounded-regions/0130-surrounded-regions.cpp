class Solution {
public:
    int m, n;

    // DFS to mark safe region
    void dfs(vector<vector<char>>& board, int i, int j) {
        // Boundary check
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return;

        // Mark as safe
        board[i][j] = '#';

        // Explore all 4 directions
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        m = board.size();
        n = board[0].size();

        // Step 1: Mark border connected 'O' as safe
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        // Step 2: Flip surrounded 'O' to 'X'
        // Restore '#' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
