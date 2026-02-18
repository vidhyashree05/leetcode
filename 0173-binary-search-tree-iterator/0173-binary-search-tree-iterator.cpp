class BSTIterator {
private:
    stack<TreeNode*> st;   // Stack to simulate inorder traversal
    
    // Helper function to push all left nodes
    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        // Initialize stack with leftmost path
        pushLeft(root);
    }
    
    // Return next smallest element
    int next() {
        TreeNode* node = st.top();
        st.pop();
        
        // If there is a right subtree,
        // push all its left children
        if (node->right != nullptr) {
            pushLeft(node->right);
        }
        
        return node->val;
    }
    
    // Check if next element exists
    bool hasNext() {
        return !st.empty();
    }
};
