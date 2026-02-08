class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // If tree is empty, no path exists
        if (root == NULL)
            return false;

        // If leaf node, check if path sum matches
        if (root->left == NULL && root->right == NULL)
            return targetSum == root->val;

        // Reduce target sum and check left or right subtree
        int remainingSum = targetSum - root->val;

        return hasPathSum(root->left, remainingSum) ||
               hasPathSum(root->right, remainingSum);
    }
};
