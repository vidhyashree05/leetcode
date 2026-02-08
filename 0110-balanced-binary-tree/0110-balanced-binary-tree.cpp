class Solution {
public:
    // Function to check height and balance
    int height(TreeNode* root) {

        // Base case: empty tree
        if (root == NULL)
            return 0;

        // Height of left subtree
        int left = height(root->left);
        if (left == -1) return -1; // left not balanced

        // Height of right subtree
        int right = height(root->right);
        if (right == -1) return -1; // right not balanced

        // If height difference > 1, not balanced
        if (abs(left - right) > 1)
            return -1;

        // Return height of tree
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        // If height function returns -1, tree is not balanced
        return height(root) != -1;
    }
};
