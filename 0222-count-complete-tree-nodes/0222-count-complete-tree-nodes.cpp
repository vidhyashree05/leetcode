class Solution {
public:

    // Function to calculate height by going LEFT only
    // This gives the maximum depth of leftmost path
    int leftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;            // increase height
            node = node->left;   // move to left child
        }
        return height;
    }

    // Function to calculate height by going RIGHT only
    // This gives the maximum depth of rightmost path
    int rightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;             // increase height
            node = node->right;   // move to right child
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        
        // Base case: if tree is empty
        if (!root) return 0;

        // Get leftmost height
        int lh = leftHeight(root);

        // Get rightmost height
        int rh = rightHeight(root);

        // If heights are same → tree is PERFECT binary tree
        if (lh == rh) {
            // Number of nodes in perfect binary tree = 2^h - 1
            return (1 << lh) - 1;
        }

        // Otherwise, recursively count left and right subtree
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};