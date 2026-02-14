class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0); // Dummy head for sorted list
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; // Save next node

            // Find position to insert in sorted list
            ListNode* prev = dummy;

            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            // Move to next node
            curr = nextNode;
        }

        return dummy->next;
    }
};
