class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;      // Previous node (initially NULL)
        ListNode* curr = head;      // Start from head
        
        while (curr != NULL) {
            
            ListNode* next = curr->next;  // Store next node
            
            curr->next = prev;  // Reverse the link
            
            prev = curr;        // Move prev forward
            curr = next;        // Move curr forward
        }
        
        return prev;   // New head after reversing
    }
};