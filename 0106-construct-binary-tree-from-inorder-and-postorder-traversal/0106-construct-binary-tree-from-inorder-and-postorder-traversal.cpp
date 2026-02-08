class Solution {
public:
    // Map to store value -> index from inorder
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd) {

        // Base case: no elements
        if (inStart > inEnd)
            return NULL;

        // Pick current root from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find root index in inorder
        int inIndex = mp[rootVal];

        // IMPORTANT:
        // Build right subtree first
        root->right = build(inorder, postorder, inIndex + 1, inEnd);
        root->left  = build(inorder, postorder, inStart, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Store inorder indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        // Start from last index of postorder
        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};
