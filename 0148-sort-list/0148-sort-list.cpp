class Solution {
public:

    // Merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        // Base case
        if (!head || !head->next)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split list
        ListNode* mid = slow->next;
        slow->next = NULL;

        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Merge sorted halves
        return merge(left, right);
    }
};
