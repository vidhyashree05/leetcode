class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Dummy node to handle edge cases (like left = 1)
        ListNode dummy(0);
        dummy.next = head;

        // prev will point to node before 'left'
        ListNode* prev = &dummy;

        // Move prev to the node just before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr points to the first node to be reversed
        ListNode* curr = prev->next;

        // Reverse the sublist using head-insertion
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;   // node to move
            curr->next = temp->next;       // detach temp
            temp->next = prev->next;       // move temp to front
            prev->next = temp;             // update prev
        }

        return dummy.next;
    }
};
