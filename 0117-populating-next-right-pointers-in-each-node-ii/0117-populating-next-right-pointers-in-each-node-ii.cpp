class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        Node* curr = root;   // current level node

        while (curr != NULL) {
            Node dummy(0);   // dummy head for next level
            Node* tail = &dummy;

            // Traverse current level using next pointers
            while (curr != NULL) {

                if (curr->left != NULL) {
                    tail->next = curr->left;
                    tail = tail->next;
                }

                if (curr->right != NULL) {
                    tail->next = curr->right;
                    tail = tail->next;
                }

                curr = curr->next;
            }

            // Move to next level
            curr = dummy.next;
        }

        return root;
    }
};
