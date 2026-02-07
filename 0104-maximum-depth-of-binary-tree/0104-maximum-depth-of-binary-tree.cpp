class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base case: empty tree
        if (root == NULL)
            return 0;

        // Recursively find depth of left & right subtree
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Take maximum and add current node
        return 1 + max(leftDepth, rightDepth);
    }
};
