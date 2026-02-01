class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        tail->next = head;

        
        k = k % len;
        int steps = len - k;
        while (steps--) {
            tail = tail->next;
        }

        
        head = tail->next;
        tail->next = NULL;

        return head;
    }
};
