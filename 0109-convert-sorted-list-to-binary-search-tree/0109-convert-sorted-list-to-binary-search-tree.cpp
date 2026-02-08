class Solution {
public:
    // Function to find middle node
    ListNode* findMiddle(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (prev) prev->next = nullptr; // split the list
        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr; // base case
        ListNode* mid = findMiddle(head);
        TreeNode* root = new TreeNode(mid->val);

        // base case when only one element
        if (head == mid) return root;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};
