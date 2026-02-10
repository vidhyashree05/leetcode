class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        // Max path from left and right (ignore negatives)
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Path passing through current node
        int currentPath = root->val + left + right;

        // Update global maximum
        maxSum = max(maxSum, currentPath);

        // Return max single-side path
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
