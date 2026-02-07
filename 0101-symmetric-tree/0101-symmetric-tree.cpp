class Solution {
public:
    // Helper function to check mirror symmetry
    bool isMirror(TreeNode* left, TreeNode* right) {

        // Both nodes are NULL → symmetric
        if (left == NULL && right == NULL)
            return true;

        // One is NULL, other is not → not symmetric
        if (left == NULL || right == NULL)
            return false;

        // Values must be equal
        if (left->val != right->val)
            return false;

        // Check mirror condition
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        // Empty tree is symmetric
        if (root == NULL)
            return true;

        // Compare left and right subtrees
        return isMirror(root->left, root->right);
    }
};
