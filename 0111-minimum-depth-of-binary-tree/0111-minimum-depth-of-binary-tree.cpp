class Solution {
public:
    int minDepth(TreeNode* root) {
        // If tree is empty
        if (root == NULL)
            return 0;

        // Queue stores pair of (node, depth)
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;
            int depth = current.second;

            // If leaf node found
            if (node->left == NULL && node->right == NULL)
                return depth;

            // Push left child
            if (node->left)
                q.push({node->left, depth + 1});

            // Push right child
            if (node->right)
                q.push({node->right, depth + 1});
        }

        return 0; // Will never reach here
    }
};
