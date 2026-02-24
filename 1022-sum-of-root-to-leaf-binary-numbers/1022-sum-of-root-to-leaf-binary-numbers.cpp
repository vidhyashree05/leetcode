class Solution {
public:
    int dfs(TreeNode* root, int current) {
        if (!root) return 0;

        // Build the binary number
        current = current * 2 + root->val;

        // If leaf node
        if (!root->left && !root->right)
            return current;

        // Return sum of left and right subtree
        return dfs(root->left, current) + dfs(root->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};