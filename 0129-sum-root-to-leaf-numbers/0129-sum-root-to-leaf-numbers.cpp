class Solution {
public:
    int dfs(TreeNode* root, int currentSum) {
        if (!root) 
            return 0;

        // Build the number for current path
        currentSum = currentSum * 10 + root->val;

        // If it's a leaf node, return the formed number
        if (!root->left && !root->right) {
            return currentSum;
        }

        // Recurse left and right
        return dfs(root->left, currentSum) +
               dfs(root->right, currentSum);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};