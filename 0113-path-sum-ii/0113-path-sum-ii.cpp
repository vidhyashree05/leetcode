class Solution {
public:
    vector<vector<int>> result;  // stores all valid paths
    vector<int> path;             // current path

    void dfs(TreeNode* root, int targetSum) {
        if (root == NULL)
            return;

        // Add current node to path
        path.push_back(root->val);

        // If leaf node and sum matches, store path
        if (root->left == NULL && root->right == NULL &&
            targetSum == root->val) {
            result.push_back(path);
        }

        // Recur for left and right subtree
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);

        // Backtrack: remove current node
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
};
