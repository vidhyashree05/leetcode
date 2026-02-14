class Solution {
public:
    // Helper function
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) return;

        dfs(root->left, res);     // Traverse left subtree
        dfs(root->right, res);    // Traverse right subtree
        res.push_back(root->val); // Process root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
