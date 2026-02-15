class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = (pA == NULL) ? headB : pA->next;
            pB = (pB == NULL) ? headA : pB->next;
        }

        return pA;  // Either intersection node or NULL
    }
};
