class Solution {
public:
    // Helper function to validate BST using range limits
    bool validate(TreeNode* root, long long minVal, long long maxVal) {

        // Empty tree is valid
        if (root == NULL)
            return true;

        // Current node must be strictly inside (minVal, maxVal)
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Left subtree: values must be < root->val
        // Right subtree: values must be > root->val
        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        // Use long long limits to avoid overflow
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};
