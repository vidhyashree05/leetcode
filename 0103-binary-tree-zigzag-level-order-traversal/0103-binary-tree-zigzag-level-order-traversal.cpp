class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;   // direction flag

        while (!q.empty()) {

            int size = q.size();
            vector<int> level(size);  // fixed size vector

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // decide index based on direction
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;  // flip direction
        }

        return ans;
    }
};
