class Solution {
public:
    TreeNode* first = NULL;   // first wrong node
    TreeNode* second = NULL;  // second wrong node
    TreeNode* prev = NULL;    // previous node in inorder traversal

    void inorder(TreeNode* root) {
        if (!root) return;

        // Traverse left subtree
        inorder(root->left);

        // Check BST violation
        if (prev && root->val < prev->val) {

            // First violation
            if (!first) {
                first = prev;
            }

            // Second violation (or update second)
            second = root;
        }

        // Update prev pointer
        prev = root;

        // Traverse right subtree
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        // Swap the two incorrect nodes
        swap(first->val, second->val);
    }
};
