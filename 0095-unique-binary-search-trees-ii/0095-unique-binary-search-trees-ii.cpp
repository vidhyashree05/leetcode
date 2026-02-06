class Solution {
public:
    // Function to generate all BSTs using values from start to end
    vector<TreeNode*> build(int start, int end) {

        vector<TreeNode*> trees;

        // Base case: empty tree
        if (start > end) {
            trees.push_back(NULL);
            return trees;
        }

        // Try every value as root
        for (int i = start; i <= end; i++) {

            // Generate all possible left subtrees
            vector<TreeNode*> leftTrees = build(start, i - 1);

            // Generate all possible right subtrees
            vector<TreeNode*> rightTrees = build(i + 1, end);

            // Combine left and right subtrees with root i
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;

                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};
