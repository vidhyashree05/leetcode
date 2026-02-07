class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {

        // No elements to construct subtree
        if (left > right)
            return NULL;

        // Pick current root from preorder
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Get root index in inorder
        int mid = inorderIndex[rootVal];

        // Build left subtree
        root->left = build(preorder, inorder, left, mid - 1);

        // Build right subtree
        root->right = build(preorder, inorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
