class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        // Start with the leftmost node of each level
        Node* leftMost = root;

        // Since it's a perfect binary tree, check left child
        while (leftMost->left != NULL) {
            Node* curr = leftMost;

            // Traverse nodes at current level
            while (curr != NULL) {

                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect right child to next node's left child
                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;
                }

                // Move to next node in the same level
                curr = curr->next;
            }

            // Move to next level
            leftMost = leftMost->left;
        }

        return root;
    }
};
