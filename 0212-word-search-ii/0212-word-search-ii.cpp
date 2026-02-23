class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->word = w;
        }
        return root;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a'])
            return;
        
        node = node->children[c - 'a'];
        
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";  // avoid duplicates
        }
        
        board[i][j] = '#';  // mark visited
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size())
                dfs(board, ni, nj, node, result);
        }
        
        board[i][j] = c;  // restore
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> result;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
};