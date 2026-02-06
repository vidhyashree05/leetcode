class Solution {
public:
    vector<int> result;

    // Helper function for inorder traversal
    void inorder(TreeNode* root) {
        // Base case: if node is null, return
        if (root == NULL)
            return;

        // Visit left subtree
        inorder(root->left);

        //  Visit root
        result.push_back(root->val);

        //  Visit right subtree
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
};
