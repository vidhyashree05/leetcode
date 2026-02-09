class Solution {
public:
    TreeNode* prev = NULL;  // keeps track of previously visited node

    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        // First flatten right subtree
        flatten(root->right);

        // Then flatten left subtree
        flatten(root->left);

        // Rewire pointers
        root->right = prev;   // current node points to previous node
        root->left = NULL;    // left must be NULL
        prev = root;          // move prev to current node
    }
};

