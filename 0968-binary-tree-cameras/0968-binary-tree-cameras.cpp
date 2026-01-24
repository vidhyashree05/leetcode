class Solution {
public:
    int cameras = 0;

    int dfs(TreeNode* root) {
        if (!root) return 2; // null nodes are covered

        int left = dfs(root->left);
        int right = dfs(root->right);

        // If any child needs a camera, put camera here
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // If any child has a camera, this node is covered
        if (left == 1 || right == 1) {
            return 2;
        }

        // Otherwise, this node needs a camera
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cameras++; // root needs camera
        return cameras;
    }
};

